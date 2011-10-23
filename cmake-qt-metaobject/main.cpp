#include "header.hpp"

#include <iostream>

#include <QtCore/QCoreApplication>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValueIterator>

Node::Node() 
    : mId(boost::uuids::random_generator()()) {
}

Node::~Node() {}

Node* Node::AddChild(Node* node) {
    node->mParent = this;
    mChildren.insert(node->mId, node);
    return &mChildren[node->mId];
}

void Node::Display(int level) {
    for(int i = 0; i < level; ++i)
        std::cout << "  ";
    std::cout << "- Node " << boost::uuids::to_string(mId) << std::endl;

    for(auto iter = mChildren.begin(); iter != mChildren.end(); ++iter) {
        iter->second->Display(level + 1);
    }
}

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);

    Node base;
    base.AddChild(new Node);
    base.AddChild(new Node)->AddChild(new Node);
    base.AddChild(new Node);

    base.Display();

    QScriptValue sc; 
    QScriptEngine engine;
    sc = engine.evaluate("({\"penis\":\"rofl\", \"lol\":12})");

    QScriptValueIterator it(sc);
    while (it.hasNext()) {
        it.next();
        std::cout << it.name().toStdString() << " => " << it.value().toString().toStdString() << std::endl;
    }

    return 0;
}
