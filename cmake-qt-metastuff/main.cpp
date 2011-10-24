#include "Node.hpp"
#include "SpecializedComponent.hpp"

#include <QMetaType>

#include <iostream>

int main() {
    qRegisterMetaType<Node>("Node");
    qRegisterMetaType<SpecializedComponent>("SpecializedComponent");

    Node testnode1;
    testnode1.ShowName();

    int id = QMetaType::type("Node");
    std::cout << "node id: " << id << std::endl;

    Node* testnode2 = static_cast<Node*>(QMetaType::construct(id));
    testnode2->ShowName();

    return 0;
}
