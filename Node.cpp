#include <iostream>
#include "Node.h"

////////////////////////// Nodes Class Definitions//////////////////////////

Node::Node(int vertex, double time, double adjustment_factor): vertex(vertex), time(time), adjustment_factor(adjustment_factor), next(nullptr){} // constructor definition
Node* Node::getnext() const {return next;}// getnext function definition
void Node::setnext(Node* new_node) {next = new_node;} //setnext function definition