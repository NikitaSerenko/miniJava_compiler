#ifndef MINIJAVA_TYPE_H
#define MINIJAVA_TYPE_H

#include <string>
#include <vector>
#include <memory>

#include "visitor.h"
#include "expressions.h"

class Type
{
public:
    std::string label;
};

class ClassType: public Type
{
public:
    ClassType(Id * id_):
        id(id_)
    {
        label = id->name;
    }
    Id * id;
};

enum BasicTypes{
    INT_,
    BOOL_,
    INT_ARRAY_
};

class BasicType: public Type{
public:

    BasicType(BasicTypes type_): type(type_){
        if (type == INT_) label = "int";
        if (type == BOOL_) label = "bool";
        if (type == INT_ARRAY_) label = "int[]";
    }
    BasicTypes type;
};

#endif
