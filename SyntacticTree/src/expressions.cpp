#ifndef MINIJAVA_EXPR_H
#define MINIJAVA_EXPR_H

#include <vector>
#include <memory>
#include <iostream>

#include "visitor.h"

class Expr: public Visitable {
public:
    Expr() {};
    virtual ~Expr() {};
    virtual void accept(Visitor *v) {};

    std::string label;
};

class ExprList{
public:
    ExprList(Expr * exp){
        expressions.clear();
        expressions.push_back(exp);
    }
    ExprList(ExprList * exps, Expr * exp){
        expressions.clear();
        std::vector<Expr * > newVec(exps->getVector());
        newVec.push_back(exp);
        expressions.swap(newVec);
    }
    std::vector<Expr * > getVector(){
        return expressions;
    }
    std::vector<Expr * > expressions;
};

enum BinaryType {
    LESS_T  = 1,
    AND_T = 2,
    OR_T = 3,
    PLUS_T = 4,
    MINUS_T = 5,
    TIMES_T = 6,
    MOD_T = 7
};

class BinaryExpr: public Expr{
public:
    BinaryExpr(Expr * left_, BinaryType type_, Expr * right_):
        type(type_),
        left(left_),
        right(right_)
    {
        switch(type){
            case AND_T:
                label = "and";
            break;
            case OR_T:
                label = "or";
            break;
            case PLUS_T:
                label = "+";
            break;
            case MINUS_T:
                label = "-";
            break;
            case TIMES_T:
                label = "*";
            break;
            case LESS_T:
                label = "<";
            break;
            case MOD_T:
                label = "%";
            break;
        }
    }

    virtual void accept(Visitor *v) {
        v->visit(this);
    }
    std::string label;
    BinaryType type;
    Expr * left;
    Expr * right;
};

class BooleanExpr: public Expr{
public:
    BooleanExpr(bool val_): val(val_){}
    virtual void accept(Visitor *v) {
        v->visit(this);
    }
    bool val;
};

class CallMethodExpr: public Expr{public:
    CallMethodExpr(Expr * expression_, Id * id_, ExprList * params_):
        expression(expression_),
        id(id_)
    {
        params.clear();
        if(params_){
            std::vector<Expr * > newVec(params_->getVector());
            params.swap(newVec);
        }
    }
    void accept(Visitor *v) {
        v->visit(this);
    }
    Expr * expression;
    Id * id;
    std::vector<Expr * > params;
};


class FalseExpr: public Expr{
public:
    FalseExpr(){}
    void accept(Visitor* v) {
        v->visit(this);
    }
};

class Id: public Expr{
public:
    Id(std::string name_){
        if (name_!=""){
            name = name_;
        }
        std::cout << name_ << std::endl;
    }
    void accept(Visitor* v) {
        v->visit(this);
    }

    std::string name;
};

class IdExpr: public Expr{
public:
    IdExpr(std::string id_): id(id_){}
    void accept(Visitor *v) {
        v->visit(this);
    }
    std::string id;
};

class IntegerExpr: public Expr{
public:
    IntegerExpr(int val_):
        val(val_)
    {}
    void accept(Visitor *v) {
        v->visit(this);
    }
    int val;
};

class LengthExpr: public Expr{
public:
    LengthExpr(Expr * object_):
        object(object_)
    {}
    void accept(Visitor *v) {
        v->visit(this);
    }
    Expr * object;
};

class NewObjectExpr: public Expr{
public:
    NewObjectExpr(Id * id_):
        id(id_)
    {}
    void accept(Visitor *v) {
        v->visit(this);
    }

    Id * id;
};

class NewIntArrayExpr: public Expr
{
public:
    NewIntArrayExpr(Expr * size_):
        size(size_)
    {}
    void accept(Visitor *v) {
        v->visit(this);
    }

    Expr * size;
};

class NotExpr: public Expr{
public:
    NotExpr(Expr * right_):
        right(right_)
    {}
    void accept(Visitor *v) {
        v->visit(this);
    }

    Expr * right;
};

class RandomAccessExpr: public Expr{
public:
    RandomAccessExpr(Expr * left_, Expr * right_):
        object(left_),
        position(right_)
    {}
    void accept(Visitor *v) {
        v->visit(this);
    }

    Expr * object;
    Expr * position;

};

class ThisExpr: public Expr{
public:
    ThisExpr(){}
    void accept(Visitor* v) {
        v->visit(this);
    }
};

class TrueExpr: public Expr{
public:
    TrueExpr(){}
    void accept(Visitor* v) {
        v->visit(this);
    }
};

#endif