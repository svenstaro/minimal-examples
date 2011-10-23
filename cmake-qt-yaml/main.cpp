#include "header.hpp"

#include <iostream>

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

void Node::Serialize(YAML::Emitter& out) {
    out << YAML::BeginMap;
    out << YAML::Key << "uuid";
    out << YAML::Value << boost::uuids::to_string(mId);

    if(mChildren.size() > 0) {
        out << YAML::Key << "children";
        out << YAML::Value << YAML::BeginSeq;
        for(auto iter = mChildren.begin(); iter != mChildren.end(); ++iter) {
            iter->second->Serialize(out);
        }
        out << YAML::EndSeq;
    }
    out << YAML::EndMap;
}

Node* Node::Deserialize(const YAML::Node& node) {
    Node* n = new Node;

    std::string uuid;
    node["uuid"] >> uuid;
    std::cout << "::LOADING " << uuid << std::endl;
    n->mId = boost::uuids::string_generator()(uuid);

    try {
        for(unsigned i = 0; i < node["children"].size(); i++) {
            Node* c = Deserialize(node["children"][i]);
            if(c != nullptr)
                n->AddChild(c);
        }
    } catch(YAML::TypedKeyNotFound<std::string> e) {
        std::cout << "// Warning: no children array" << std::endl;
    }

    return n;
}

int main(int argc, char** argv) {
    Node base;
    base.AddChild(new Node);
    base.AddChild(new Node)->AddChild(new Node);
    base.AddChild(new Node);

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
