#include "Node.hpp"
#include "Component.hpp"
#include "ComponentA.hpp"
#include "ComponentB.hpp"

#include <iostream>

int main(int argc, char** argv) {
    Node base;
    base.AddChild(new Node)->AddComponent(new ComponentA);
    base.AddChild(new Node)->AddChild(new Node);
    Node* n = base.AddChild(new Node);
    n->AddComponent(new ComponentA);
    n->AddComponent(new ComponentB);

    //base.Display();
    //

    // yaml test
    YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << "metadata" << YAML::Value;
        out << YAML::BeginMap;
        out << YAML::Key << "author" << YAML::Value << "opatut";
        out << YAML::Key << "date" << YAML::Value << "2011-10-23";
        out << YAML::EndMap;


    out << YAML::Key << "rootnode" << YAML::Value;
    base.Serialize(out);

    std::string yaml(out.c_str());

    std::cout << "Output YAML:" << std::endl << "========" << std::endl;
    std::cout << yaml << std::endl;

    std::cout << "Base:" << std::endl << "========" << std::endl;
    base.Display();
    
    std::istringstream stream;
    stream.str(yaml);

    YAML::Parser parser(stream);
    YAML::Node doc;
    parser.GetNextDocument(doc);
    Node* read = Node::Deserialize(doc["rootnode"]);
    std::cout << "Read:" << std::endl << "========" << std::endl;
    read->Display();



    return 0;
}
