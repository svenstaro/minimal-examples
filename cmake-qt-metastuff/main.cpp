#include "Node.hpp"

#include <QMetaType>

#include <iostream>

int main() {
    Node testnode1;
    testnode1.DoStuff();

    int id = QMetaType::type("Node");
    std::cout << "id: " << id << std::endl;
    if(id != -1) {
        Node* testnode2 = static_cast<Node*>(QMetaType::construct(id));
        testnode2->DoStuff();
    }

    return 0;
}
