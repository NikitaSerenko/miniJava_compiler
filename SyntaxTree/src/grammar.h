#ifndef MINIJAVA_GRAMMAR_H
#define MINIJAVA_GRAMMAR_H
#include "visitor.h"
#include "declarations.h"
#include <vector>

class Program: public Visitable
{
public:
    Program(MainClass * main_, 
      ClassDeclList * classes_):
      main(main_)
    {
        classes.clear();
        std::vector<ClassDecl * > newVec(classes_->getVector());
        classes.swap(newVec);
    }
    Program(MainClass * main_):
    main(main_){}
    void accept(Visitor *v) {
        v->visit(this);
    }
    ~Program(){}

    MainClass * main;
    std::vector<ClassDecl * > classes;
};

#endif
