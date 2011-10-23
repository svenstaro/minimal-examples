#include "Node.hpp"

Node::Node() 
    : mId(boost::uuids::random_generator()()) {
}

Node::~Node() {}

Node* Node::AddChild(Node* node) {
    node->mParent = this;
    mChildren.insert(node->mId, node);
    return &mChildren[node->mId];
}

Component* Node::AddComponent(Component* component) {
    component->mNode = this;

    std::shared_ptr<Component> ptr(component);
    std::pair<boost::uuids::uuid, std::shared_ptr<Component>> pair(component->mId, ptr);
    mComponents.insert(pair);
    return mComponents[component->mId].get();
}

void Node::Display(int level) {
    for(int i = 0; i < level; ++i)
        std::cout << "  ";
    std::cout << "- Node " << boost::uuids::to_string(mId) << std::endl;

    for(auto iter = mComponents.begin(); iter != mComponents.end(); ++iter) {
        for(int i = 0; i < level; ++i)
            std::cout << "  ";
        std::cout << "  - Component ";
        iter->second->SayName();
    }

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

    if(mComponents.size() > 0) {
        out << YAML::Key << "components";
        out << YAML::Value << YAML::BeginSeq;
        for(auto iter = mComponents.begin(); iter != mComponents.end(); ++iter) {
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
    } catch(YAML::TypedKeyNotFound<std::string> e) {}

    try {
        for(unsigned i = 0; i < node["components"].size(); i++) {
            Component* c = Component::Deserialize(node["components"][i]);
            if(c != nullptr)
                n->AddComponent(c);
        }
    } catch(YAML::TypedKeyNotFound<std::string> e) {}

    return n;
}
