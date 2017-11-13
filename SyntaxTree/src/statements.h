#ifndef STATEMENTS_H
#define STATEMENTS_H

#include <vector>
#include <memory>

#include "visitor.h"
#include "expressions.h"

class Statement: public Visitable {
public:
    Statement() {};
    virtual ~Statement() {};
    virtual void accept(Visitor *v) {};
};

class StatementList: public Statement{
public:
    StatementList(StatementList * prev, Statement * newStatement_)
    {
        statements.clear();
        std::vector<Statement * > newVec(prev->getVector());
        statements.swap(newVec);
        statements.push_back(newStatement_);
    }
    StatementList(Statement * statement){
        statements.clear();
        statements.push_back(statement);
    }
    ~StatementList() {}
    std::vector<Statement * > getVector(){
        return statements;
    }
    void accept(Visitor *v) {
        v->visit(this);
    }

    std::vector<Statement * > statements;
};

class Statements: public Statement{
public:
    Statements(StatementList * statements_){
        std::vector<Statement * > newVec(statements_->getVector());
        statements.clear();
        statements.swap(newVec);
    }
    void accept(Visitor *v) {
        v->visit(this);
    }

    std::vector<Statement * > statements;
};

class WhileStatement: public Statement{
public:
    WhileStatement(Expr * cond_, Statement * action_):
        cond(cond_),
        action(action_)
    {}
    void accept(Visitor *v) {
        v->visit(this);
    }


    Expr * cond;
    Statement * action;
};

class RandomAccessAssignStatement: public Statement{
public:
    RandomAccessAssignStatement(Id * id_, Expr * position_, Expr * expression_):
        id(id_),
        position(position_),
        expression(expression_)
    {}
    void accept(Visitor *v) {
        v->visit(this);
    }

    Id * id;
    Expr * position;
    Expr * expression;

};

class PrintLineStatement: public Statement{
public:
    PrintLineStatement(Expr * object_):
        object(object_)
    {}
    void accept(Visitor *v) {
        v->visit(this);
    }

    Expr * object;
};

class IfStatement: public Statement{
public:
    IfStatement(Visitable * cond_, Statement * ifTrue_, Statement * ifFalse_):
        cond(cond_),
        ifTrue(ifTrue_),
        ifFalse(ifFalse_)
    {
    }
    void accept(Visitor *v) {
        v->visit(this);
    }

    Visitable * cond;
    Statement * ifTrue;
    Statement * ifFalse;
};

class AssignStatement: public Statement{
public:
    AssignStatement(Id * left_, Expr * right_):
        left(left_),
        right(right_)
    {}
    void accept(Visitor *v) {
        v->visit(this);
    }
    Id * left;
    Expr * right;
};

#endif
