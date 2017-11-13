#ifndef MINIJAVA_VISITOR
#define MINIJAVA_VISITOR

#include "visitable.h"

class Program;

class MainClass;
class ClassDeclList;
class ClassDecl;
class VarDeclList;
class VarDecl;
class MethodModifier;
class MethodDeclList;
class MethodDecl;
class ArgDecl;
class ArgDeclList;

class Type;
class ClassType;
class BasicType;

class Statement;
class Statements;
class StatementList;
class WhileStatement;
class RandomAccessAssignStatement;
class PrintLineStatement;
class IfStatement;
class AssignStatement;

class Expr;
class ExprList;
class BinaryExpr;
class BooleanExpr;
class CallMethodExpr;
class FalseExpr;
class Id;
class IdExpr;
class IntegerExpr;
class LengthExpr;
class NewObjectExpr;
class NewIntArrayExpr;
class NotExpr;
class RandomAccessExpr;
class ThisExpr;
class TrueExpr;

class Visitor
{
public:
    // Visitor();
    virtual ~Visitor() {}
    virtual void visit(const BinaryExpr* node) = 0;
    virtual void visit(const Id* node) = 0;
    virtual void visit(const TrueExpr* node) = 0;
    virtual void visit(const FalseExpr* node) = 0;
    virtual void visit(const ClassDecl* node) = 0;
    virtual void visit(const MainClass* node) = 0;
    virtual void visit(const MethodDecl* node) = 0;
    virtual void visit(const Program* node) = 0;
    virtual void visit(const BooleanExpr* node) = 0;
    virtual void visit(const IntegerExpr* node) = 0;
    virtual void visit(const AssignStatement* node) = 0;
    virtual void visit(const IfStatement* node) = 0;
    virtual void visit(const IdExpr* node) = 0;
    virtual void visit(const NotExpr* node) = 0;
    virtual void visit(const CallMethodExpr* node) = 0;
    virtual void visit(const NewIntArrayExpr* node) = 0;
    virtual void visit(const NewObjectExpr* node) = 0;
    virtual void visit(const RandomAccessExpr* node) = 0;
    virtual void visit(const LengthExpr* node) = 0;
    virtual void visit(const PrintLineStatement* node) = 0;
    virtual void visit(const WhileStatement* node) = 0;
    virtual void visit(const Statements* node) = 0;
    virtual void visit(const RandomAccessAssignStatement* node) = 0;
    virtual void visit(const ArgDecl* node) = 0;
    virtual void visit(const StatementList* node) = 0;
    virtual void visit(const VarDecl* node) = 0;
    virtual void visit(const ThisExpr* node) = 0;
};

#endif