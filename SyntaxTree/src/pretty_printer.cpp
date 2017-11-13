#include "pretty_printer.h"

Printer::Printer(std::string path){
    out.open(path);
    out << "digraph g {\n" << "\n";
}
Printer::~Printer(){
    out << "}";
    out.close();
}
void Printer::visit(const Program* node) {
    this->printVertex(node, "Program");
    node->main->accept(this);
    printEdge(node, node->main);
    for (auto el : node->classes){
        el->accept(this);
        printEdge(node, el);
    }
}
void Printer::visit(const MainClass* node)  {
    printVertex(node, "Main");
    node->id->accept(this);
    printEdge(node, node->id);
    node->paramId->accept(this);
    printEdge(node, node->paramId, "paramId");
    for (auto statement : node->statements){
        statement->accept(this);
        printEdge(node, statement, "st");
    }
}
void Printer::visit(const ClassDecl* node)  {
    printVertex(node, "Class");
    node->id->accept(this);
    printEdge(node, node->id);
    for (auto method : node->methods){
        method->accept(this);
        printEdge(node, method);
    }
}
void Printer::visit(const Id* node) {
    printVertex(node, "id:" + node->name);
}
void Printer::visit(const PrintLineStatement* node) {
    printVertex(node, "println");
    node->object->accept(this);
    printEdge(node, node->object);
}
void Printer::visit(const CallMethodExpr* node)  {
    printVertex(node, "callMethod");
    node->id->accept(this);
    printEdge(node, node->id);
    node->expression->accept(this);
    printEdge(node, node->expression, "object");
    for (auto param : node->params){
        param->accept(this);
        printEdge(node, param, "param");
    }
}
void Printer::visit(const IntegerExpr* node)  {
    printVertex(node, "int " + std::to_string(node->val));

}
void Printer::visit(const BinaryExpr* node){
    printVertex(node, node->label);
    node->left->accept(this);
    node->right->accept(this);
    printEdge(node, node->left, "left");
    printEdge(node, node->right, "right");
}
void Printer::visit(const TrueExpr* node)  {
    printVertex(node, "True");
}
void Printer::visit(const FalseExpr* node)  {
    printVertex(node, "False");
}


void Printer::visit(const MethodDecl* node)  {
    printVertex(node, "method " + node->type->label + " " + node->modifier->label);
    node->id->accept(this);
    printEdge(node, node->id);
    for (auto var : node->vars){
        var->accept(this);
        printEdge(node, var, "var");
    }
    for (auto statement : node->statements){
        statement->accept(this);
        printEdge(node, statement);
    }
    for (auto arg : node->params){
        arg->accept(this);
        printEdge(node, arg, "arg");
    }

    node->res->accept(this);
    printEdge(node, node->res, "return");
}

void Printer::visit(const BooleanExpr* node) {
    printVertex(node, "bool " + std::to_string(node->val));
}
void Printer::visit(const AssignStatement* node)  {
    printVertex(node, "=");
    node->left->accept(this);
    node->right->accept(this);
    printEdge(node, node->left, "left");
    printEdge(node, node->right, "right");
}
void Printer::visit(const IfStatement* node) {
    printVertex(node, "If");
    node->cond->accept(this);
    printEdge(node, node->cond, "condition");
    node->ifFalse->accept(this);
    printEdge(node, node->ifFalse, "False");
    node->ifTrue->accept(this);
    printEdge(node, node->ifTrue, "True");
}
void Printer::visit(const IdExpr* node) {
    
}
void Printer::visit(const NotExpr* node) {
    printVertex(node, "NotExpression");
    node->right->accept(this);
    printEdge(node, node->right);
}
void Printer::visit(const NewIntArrayExpr* node)  {
    printVertex(node, "new int[]");
    node->size->accept(this);
    printEdge(node, node->size, "size");
}
void Printer::visit(const NewObjectExpr* node)  {
    printVertex(node, "new");
    node->id->accept(this);
    printEdge(node, node->id);
}
void Printer::visit(const RandomAccessAssignStatement* node)  {
    printVertex(node, "=");
    node->id->accept(this);
    printEdge(node, node->id, "array");
    node->position->accept(this);
    printEdge(node, node->position, "position");
    node->expression->accept(this);
    printEdge(node, node->expression);
}
void Printer::visit(const LengthExpr* node)  {
    printVertex(node, "getLength");
    node->object->accept(this);
    printEdge(node, node->object, "object");
}
void Printer::visit(const Statements* node)  {
    printVertex(node, "statements");
    for (auto statement : node->statements){
        statement->accept(this);
        printEdge(node, statement);
    }
}
void Printer::visit(const RandomAccessExpr* node) {
    printVertex(node, "AccessToPosition");
    node->object->accept(this);
    node->position->accept(this);
    printEdge(node, node->object, "object");
    printEdge(node, node->position, "position");
}

void Printer::visit(const ArgDecl* node) {
    printVertex(node, node->type->label);
    node->id->accept(this);
    printEdge(node, node->id);
}
void Printer::visit(const StatementList* node) {}
void Printer::visit(const VarDecl* node)  {
    printVertex(node, node->type->label +" "+ node->id->name);
    //node->id->accept(this);

}
void Printer::visit(const ThisExpr* node) {
    printVertex(node, "this");
}
void Printer::visit(const WhileStatement* node) {
    printVertex(node, "while");
    node->cond->accept(this);
    printEdge(node, node->cond, "condition");
    node->action->accept(this);
    printEdge(node, node->action, "action");
}

void Printer::printEdge(const Visitable* from, const Visitable * to){
    out << "\tnode" << from << "->" << "node" << to << "\n";
}

void Printer::printVertex(const Visitable* node, const std::string label){
    out << "\tnode" << node << "[label=\"" << label << "\"]\n";
}

void Printer::printEdge(const Visitable* from, const Visitable * to, std::string label){
    out << "\tnode" << from << "->" << "node" << to << "[label=\"" << label << "\"]\n";
}

void Printer::printEdge(std::string from, std::string to){
    out << "\t" << from << "->" << to << "\n";
}
void Printer::printEdge(std::string from, Visitable* to){
    out << "\t"<< from << "->" << "node" << to << "\n";
}
