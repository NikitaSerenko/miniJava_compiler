#ifndef PRETTYPRINTER_H
#define PRETTYPRINTER_H

#include "types.h"
#include "expressions.h"
#include "statements.h"
#include "declarations.h"
#include "grammar.h"

#include <fstream>
#include <memory>

class Printer: public Visitor
{
public:
    Printer(std::string path);
    ~Printer();
    void printEdge(const Visitable* from, const Visitable * to);
    void printVertex(const Visitable *node, const std::string label);
    void printEdge(const Visitable* from, const Visitable * to, const std::string label);
    void printEdge(std::string from, std::string to);
    void printEdge(std::string from, Visitable* to);
    virtual void visit(const BinaryExpr* node);
    virtual void visit(const Id* node);
    virtual void visit(const TrueExpr* node);
    virtual void visit(const FalseExpr* node);
    virtual void visit(const ClassDecl* node);
    virtual void visit(const MainClass* node);
    virtual void visit(const MethodDecl* node);
    virtual void visit(const Program* node);
    virtual void visit(const BooleanExpr* node);
    virtual void visit(const IntegerExpr* node);
    virtual void visit(const AssignStatement* node);
    virtual void visit(const IfStatement* node);
    virtual void visit(const IdExpr* node);
    virtual void visit(const NotExpr* node);
    virtual void visit(const CallMethodExpr* node);
    virtual void visit(const NewIntArrayExpr* node);
    virtual void visit(const NewObjectExpr* node);
    virtual void visit(const RandomAccessAssignStatement* node);
    virtual void visit(const LengthExpr* node);
    virtual void visit(const PrintLineStatement* node);
    virtual void visit(const WhileStatement* node);
    virtual void visit(const Statements* node);
    virtual void visit(const RandomAccessExpr* node);
    virtual void visit(const ArgDecl* node);
    virtual void visit(const StatementList* node);
    virtual void visit(const VarDecl* node);
    virtual void visit(const ThisExpr* node);

private:
    std::ofstream out;

};

#endif
