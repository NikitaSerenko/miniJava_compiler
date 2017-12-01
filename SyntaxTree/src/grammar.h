#ifndef MINIJAVA_GRAMMAR_H
#define MINIJAVA_GRAMMAR_H
#include "visitor.h"
#include "declarations.h"
#include <vector>

class Program: public Visitable
{
public:
    Program(MainClass * main_, 
      ClassDeclList * classes_, 
      Coordinates *coords):
      main(main_)
    {
        coordinates = coords;
        classes.clear();
        std::vector<ClassDecl * > newVec(classes_->getVector());
        classes.swap(newVec);
    }
    Program(MainClass * main_, Coordinates *coords):
    main(main_)
    {
        coordinates = coords;
    }
    void accept(Visitor *v) {
        v->visit(this);
    }
    ~Program(){}

    MainClass * main;
    std::vector<ClassDecl * > classes;
};

#endif
