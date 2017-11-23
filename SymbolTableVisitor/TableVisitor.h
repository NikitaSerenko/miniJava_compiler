#pragma once

#include "../SymbolTable/Table.h"
#include "../SyntaxTree/src/types.h"
#include "../SyntaxTree/src/expressions.h"
#include "../SyntaxTree/src/statements.h"
#include "../SyntaxTree/src/declarations.h"
#include "../SyntaxTree/src/grammar.h"

#include <iostream>
#include "../SymbolTable/DeclarationException.h"
#include "../SymbolTable/Table.h"
#include "../SymbolTable/ClassInfo.h"
#include "../SymbolTable/MethodInfo.h"
#include "../SymbolTable/Position.h"
#include "../SymbolTable/VariableInfo.h"
#include "../SymbolTable/StringSymbol.h"
#include "../SymbolTable/Symbol.h"
#include "../SymbolTable/Table.h"

class TableVisitor : public Visitor {

public:
    TableVisitor() {};

    ~TableVisitor() {};


    virtual void visit(const BinaryExpr *node) {};

    virtual void visit(const Id *node) {};

    virtual void visit(const TrueExpr *node) {};

    virtual void visit(const FalseExpr *node) {};

    virtual void visit(const MethodDecl *node) {};

    virtual void visit(const BooleanExpr *node) {};

    virtual void visit(const IntegerExpr *node) {};

    virtual void visit(const AssignStatement *node) {};

    virtual void visit(const IfStatement *node) {};

    virtual void visit(const IdExpr *node) {};

    virtual void visit(const NotExpr *node) {};

    virtual void visit(const CallMethodExpr *node) {};

    virtual void visit(const NewIntArrayExpr *node) {};

    virtual void visit(const NewObjectExpr *node) {};

    virtual void visit(const RandomAccessAssignStatement *node) {};

    virtual void visit(const LengthExpr *node) {};

    virtual void visit(const PrintLineStatement *node) {};

    virtual void visit(const WhileStatement *node) {};

    virtual void visit(const Statements *node) {};

    virtual void visit(const RandomAccessExpr *node) {};

    virtual void visit(const ArgDecl *node) {};

    virtual void visit(const StatementList *node) {};

    virtual void visit(const VarDecl *node) {};

    virtual void visit(const ThisExpr *node) {};

    void ParseProgram(Program *program) {
        program->accept(this);
        for (auto className = table.GetClassesNames().begin();
             className != table.GetClassesNames().end(); ++className) {
            try {
                std::string name = (*className)->GetString();
                std::cout << "class " << name << ":" << std::endl;
                auto classInfo = table.GetClass(name, Position(0, 0));
                table.AddClassToScope(name, Position(0, 0));
                printClassInfo(classInfo);
                table.FreeLastScope();
                std::cout << std::endl;
            } catch (DeclarationException e) {
                std::cout << "Declaration error:" << e.what() << std::endl;
            }
        }
    }

    void visit(const Program *node) {
        node->main->accept(this);
        for (auto class_el = node->classes.begin(); class_el != node->classes.end(); class_el++) {
            (*class_el)->accept(this);
        }
    }

    void visit(const MainClass *node) {
        auto newClass = new ClassInfo(node->id->name, fromCoords(node->coordinates));

        auto methodInfo = new MethodInfo("main",
                                         fromCoords(node->coordinates),
                                         TypeInfo(VT_UserClass, "void"),
                                         Q_Public);

        methodInfo->AddVariableInfo(new VariableInfo(node->paramId->name,
                                                     fromCoords(node->coordinates),
                                                     TypeInfo(VT_UserClass, "String[]")));
        newClass->AddMethodInfo(methodInfo);
        table.AddClass(newClass, fromCoords(node->coordinates));
    }

    void visit(const ClassDecl *node) {
        auto newClass = new ClassInfo(node->id->name, fromCoords(node->coordinates));
        if (node->extends != nullptr) {
            newClass->AddSuperClassName(node->extends->name);
        }
        auto varDeclarations = node->vars;
        if (varDeclarations.size() != 0) {
            for (auto var = varDeclarations.begin(); var != varDeclarations.end(); ++var) {
                newClass->AddVariableInfo(new VariableInfo((*var)->id->name,
                                                           fromCoords((*var)->coordinates),
                                                           fromType((*var)->type)));
            }
        }
        auto methodDeclarations = node->methods;
        if (methodDeclarations.size() != 0) {
            for (auto method = methodDeclarations.begin(); method != methodDeclarations.end(); ++method) {
                auto methodInfo = new MethodInfo((*method)->id->name,
                                                 fromCoords((*method)->coordinates),
                                                 fromType((*method)->type),
                                                 (*method)->modifier->label == "PUBLIC" ? Q_Public : Q_Private);
                auto argDeclarations = (*method)->params;
                if (argDeclarations.size() != 0) {
                    for (auto arg = argDeclarations.begin(); arg != argDeclarations.end(); ++arg) {
                        methodInfo->AddArgInfo(new VariableInfo((*arg)->id->name,
                                                                fromCoords((*arg)->coordinates),
                                                                fromType((*arg)->type)));
                    }
                }
                auto varDeclarations = (*method)->vars;
                if (varDeclarations.size() != 0) {
                    for (auto var = varDeclarations.begin(); var != varDeclarations.end(); ++var) {
                        methodInfo->AddVariableInfo(new VariableInfo((*var)->id->name,
                                                                     fromCoords((*var)->coordinates),
                                                                     fromType((*var)->type)));
                    }
                }
                newClass->AddMethodInfo(methodInfo);
            }
        }
        table.AddClass(newClass, fromCoords(node->coordinates));
    }


    TypeInfo fromType(const Type *node) {
        if (node->label == "int") {
            return TypeInfo(VT_Int);
        } else if (node->label == "int[]") {
            return TypeInfo(VT_IntArray);
        } else if (node->label == "bool") {
            return TypeInfo(VT_Boolean);
        } else {
            return TypeInfo(VT_UserClass, node->label);
        }


    }

    void printClassInfo(const ClassInfo *classInfo) {
        if (classInfo->GetSuperClassName() != nullptr) {
            std::cout << "  Super: " << classInfo->GetSuperClassName()->GetString() << std::endl;
            auto superClass = table.GetClass(classInfo->GetSuperClassName()->GetString(), Position(0, 0));
            printClassInfo(superClass);
        }

        for (auto varName = classInfo->GetVarsNames().begin();
             varName != classInfo->GetVarsNames().end(); ++varName) {
            std::cout << "    ";
            auto variable = table.GetVariable((*varName)->GetString(), Position(0, 0));
            printVariable(variable);
        }

        for (auto methodName = classInfo->GetMethodNames().begin();
             methodName != classInfo->GetMethodNames().end(); ++methodName) {
            auto method = table.GetMethod((*methodName)->GetString(), Position(0, 0));
            table.AddMethodToScope(method->GetName()->GetString(), Position(0, 0));
            std::cout << "    " << (method->GetQualifier() == Q_Public ? "public " : "private ");
            printType(method->GetReturnType());
            std::cout << method->GetName()->GetString() << std::endl;
            std::cout << "      Args:" << std::endl;
            auto &args = method->GetArgsName();
            for (auto arg = args.begin(); arg != args.end(); ++arg) {
                auto var = table.GetVariable((*arg)->GetString(), Position(0, 0));
                std::cout << "        ";
                printVariable(var);
            }
            std::cout << "      Local vars:" << std::endl;
            auto &vars = method->GetVarsName();
            for (auto var = vars.begin(); var != vars.end(); ++var) {
                auto varInfo = table.GetVariable((*var)->GetString(), Position(0, 0));
                std::cout << "        ";
                printVariable(varInfo);
            }
            table.FreeLastScope();
        }
    }

    void printVariable(const VariableInfo *varInfo) {
        printType(varInfo->GetType());
        std::cout << " " << varInfo->GetName()->GetString() << std::endl;
    }

    void printType(const TypeInfo &type) {
        switch (type.GetType()) {
            case VT_Int:
                std::cout << "int ";
                break;
            case VT_IntArray:
                std::cout << "int[] ";
                break;
            case VT_Boolean:
                std::cout << "boolean ";
                break;
            case VT_UserClass:
                std::cout << type.GetUserClass()->GetString() << " ";
                break;
            default:
                break;
        }
    }

    Position fromCoords(const Coordinates *coords) { return Position(coords->x, coords->y); }

private:
    Table table;

};


