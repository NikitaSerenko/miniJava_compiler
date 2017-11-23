#include "Test.h"
#include "Table.h"
#include "ClassInfo.h"
#include "Position.h"

#include <iostream>
#include <assert.h>

/*
 * Тест:
 * class A {
 *  int x;
 *  boolean b;
 *  int[] a;
 *
 * public B foo(boolean f) {
 *      int g;
 *  }
 * }
 *
 * class B : A {
 *  int y;
 *  private bool foo1() {
 *      int[] b;
 *  }
 * }
 *
 * */

void TestClasses() {
    Table table;
    auto aClass = new ClassInfo("A", Position(0, 0));
    auto xVariable = new VariableInfo("x", Position(1, 0), 
                                                   TypeInfo(VT_Int));
    auto bVariable = new VariableInfo("b", Position(2, 0),
                                                   TypeInfo(VT_Boolean));
    auto aVariable = new VariableInfo("a", Position(3, 0),
                                                   TypeInfo(VT_IntArray));
    auto fooMethod = new MethodInfo("foo", Position(4, 0),
                                                 TypeInfo(VT_UserClass, "B"),
                                                 Q_Public);
    auto fArg = new VariableInfo("f", Position(5, 0),
                                              TypeInfo(VT_Boolean));
    auto gLocal = new VariableInfo("g", Position(6, 0),
                                                TypeInfo(VT_IntArray));
    fooMethod->AddArgInfo(fArg);
    fooMethod->AddVariableInfo(gLocal);
    aClass->AddVariableInfo(xVariable);
    aClass->AddVariableInfo(bVariable);
    aClass->AddVariableInfo(aVariable);
    aClass->AddMethodInfo(fooMethod);
    table.AddClass(aClass, Position(0, 0));

    auto bClass = new ClassInfo("B", Position(7, 0));
    bClass->AddSuperClassName("A");
    auto yVariable = new VariableInfo("y", Position(8, 0),
                                                   TypeInfo(VT_Int));
    auto bLocal = new VariableInfo("b", Position(9, 0),
                                                TypeInfo(VT_IntArray));
    auto foo1Method = new MethodInfo("foo1", Position(10, 0),
                                                  TypeInfo(VT_Boolean),
                                                  Q_Private);
    foo1Method->AddVariableInfo(bLocal);
    bClass->AddVariableInfo(yVariable);
    bClass->AddMethodInfo(foo1Method);
    table.AddClass(bClass, Position(7, 0));

    assert(table.GetClass("B", Position(11, 0))->GetMethodsBlock().size() == 1);
    table.AddClassToScope("B", Position(12, 0));
    auto method = table.GetMethod("foo", Position(12, 0));
    assert(method->GetVariableBlocks().find(method->GetArgsName().at(0))->second->GetType().GetType() ==
           VT_Boolean);
    assert(table.GetVariable("b", Position(12, 0))->GetType().GetType() == VT_Boolean);
    table.AddMethodToScope("foo1", Position(13, 0));
    assert(table.GetVariable("b", Position(12, 0))->GetType().GetType() == VT_IntArray);
}
