#ifndef MINIJAVA_DECLS_H
#define MINIJAVA_DECLS_H

#include <vector>
#include <memory>

#include "visitor.h"

class VarDecl: public Visitable
{
public:
    VarDecl(Type * type_, Id * id_):
        type(type_),
        id(id_)
    {}
    void accept(Visitor *v){
        v->visit(this);
    }


    Type * type;
    Id * id;
};

class VarDeclList
{
public:
    VarDeclList(VarDeclList * prev, VarDecl * newVar_)
    {
        vars.clear();
        std::vector<VarDecl * > newVec(prev->getVector());
        vars.swap(newVec);
        vars.push_back(newVar_);
    }
    VarDeclList(VarDecl * var){
        vars.clear();
        vars.push_back(var);
    }

    std::vector<VarDecl * > getVector(){
        return vars;
    }

    std::vector<VarDecl * > vars;
};

class ArgDecl: public Visitable
{
public:
    ArgDecl(Type * type_, Id * id_):
        type(type_),
        id(id_)
    {}
    void accept(Visitor *v) {
        v->visit(this);
    }
    Type * type;
    Id * id;
};

class ArgDeclList
{
public:
    ArgDeclList(){
        vars.clear();
    }
    ArgDeclList(ArgDeclList * prev, Type * type_, Id * id_)
    {
        ArgDecl *newArg = new ArgDecl(type_, id_);
        vars.clear();
        std::vector<ArgDecl * > newVec(prev->getVector());
        vars.swap(newVec);
        vars.push_back((ArgDecl *)(newArg));
    }
    ArgDeclList(Type * type_,Id * id_){
        vars.clear();
        ArgDecl *newArg = new ArgDecl(type_, id_);
        vars.push_back((ArgDecl *)(newArg));
    }

    std::vector<ArgDecl * > getVector(){
        return vars;
    }
    std::vector<ArgDecl * > vars;
};

class MethodModifier
{
public:
    MethodModifier(std::string label_): label(label_) {}
    std::string label;
};

class MethodDecl: public Visitable
{
public:
    MethodDecl(MethodModifier * modifier_, Type * type_, Id * id_, ArgDeclList * params_,
             VarDeclList * vars_, StatementList * statements_,Expr * res_):
        modifier(modifier_),
        type(type_),
        id(id_),
        res(res_)
    {
        params.clear();
        if (params_){
            std::vector<ArgDecl * > newVecP(params_->getVector());
            params.swap(newVecP);
        }

        vars.clear();
        if (vars_){
            std::vector<VarDecl * > newVecV(vars_->getVector());
            vars.swap(newVecV);
        }

        statements.clear();
        if (statements_){
            std::vector<Statement * > newVec(statements_->getVector());
            statements.swap(newVec);
        }
    }
    void accept(Visitor *v) {
        v->visit(this);
    }
    Type * type;
    Id * id;
    MethodModifier * modifier;
    std::vector<ArgDecl * > params;
    std::vector<VarDecl * > vars;
    std::vector<Statement * > statements;
    Expr * res;
};

class MethodDeclList
{
public:
    MethodDeclList(MethodDeclList * prev, MethodDecl * newMethod_)
    {
        methods.clear();
        std::vector<MethodDecl * > newVec(prev->getVector());
        methods.swap(newVec);
        methods.push_back(newMethod_);
    }
    MethodDeclList(MethodDecl * method){
        methods.clear();
        methods.push_back(method);
    }
    std::vector<MethodDecl * > getVector(){
        return methods;
    }

    std::vector<MethodDecl * > methods;
};


class MainClass: public Visitable 
{
public:
    MainClass(Id * id_, 
        Id * paramId_, 
        StatementList * statements_):
        id (id_),
        paramId(paramId_)
    {
        std::vector<Statement * > newVec(statements_->getVector());
        statements.clear();
        statements.swap(newVec);
    }
    void accept(Visitor *v) {
        v->visit(this);
    }
    Id * id;
    Id * paramId;
    std::vector<Statement * > statements;
};

class ClassDecl: public Visitable
{
public:
    ClassDecl(Id * id_, 
        Id * extends_, 
        VarDeclList * vars_, 
        MethodDeclList * methods_):
        id(id_),
        extends(extends_)
    {
        std::vector<VarDecl * > newVec(vars_->getVector());
        vars.clear();
        vars.swap(newVec);
        std::vector<MethodDecl * > newVecM(methods_->getVector());
        methods.clear();
        methods.swap(newVecM);
    }
    ClassDecl(Id * id_, Id * extends_, VarDeclList * vars_):
        id(id_),
        extends(extends_)
    {
        std::vector<VarDecl * > newVec(vars_->getVector());
        vars.clear();
        vars.swap(newVec);
    }
    ClassDecl(Id * id_, Id * extends_, MethodDeclList * methods_):
        id(id_),
        extends(extends_)
    {
        std::vector<MethodDecl * > newVecM(methods_->getVector());
        methods.clear();
        methods.swap(newVecM);
    }
    ClassDecl(Id * id_, Id * extends_):
        id(id_),
        extends(extends_)
    {}

    void accept(Visitor *v) {
        v->visit(this);
    }

    Id * id;
    Id * extends;
    std::vector<VarDecl * > vars;
    std::vector<MethodDecl * > methods;
};


class ClassDeclList
{
public:
    ClassDeclList(ClassDeclList * prev, ClassDecl * newClass_)
    {
        classes.clear();
        std::vector<ClassDecl * > newVec(prev->getVector());
        newVec.push_back(newClass_);
        classes.swap(newVec);
    }
    ClassDeclList(ClassDecl * class_){
        classes.clear();
        classes.push_back(class_);
    }
    std::vector<ClassDecl * > getVector(){
        return classes;
    }
    std::vector<ClassDecl * > classes;
};

#endif
