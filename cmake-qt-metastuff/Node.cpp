#include "Node.hpp"

#include <iostream>

Node::Node() {
    mName = "node";
}

Node::Node(const Node& other) {}

Node::~Node() {}

void Node::ShowName() {
    std::cout << mName << std::endl;
}
