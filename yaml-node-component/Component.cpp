#include "Component.hpp"

#include "Node.hpp"
#include <QMetaType>

Component::Component()
    : mId(boost::uuids::random_generator()()) {
}

Component::Component(const Component& other) {
    assert(false && "OH GOD DON'T USE THIS COPY CONSTRUCTOR");
}

Component::~Component() {}

void Component::Serialize(YAML::Emitter& out) {
    out << YAML::BeginMap;
    out << YAML::Key << "type";
    out << YAML::Value << metaObject()->className();
    out << YAML::Key << "uuid";
    out << YAML::Value << boost::uuids::to_string(mId);

    OnSerialize(out);
    out << YAML::EndMap;
}

Component* Component::Deserialize(const YAML::Node& node) {
    std::string type;

    try {
        node["type"] >> type;
    } catch(YAML::TypedKeyNotFound<std::string> e) {
        std::cerr << "No component type specified." << std::endl;
        return nullptr;
    }

    int meta_type_id = QMetaType::type(type.c_str());
    if(meta_type_id == 0) {
        std::cerr << "Invalid component type: " << type << std::endl;
        return nullptr;
    }

    std::cout << "INFO: MetaType " << type << " maps to ID " << meta_type_id << std::endl;
    void* ptr = QMetaType::construct(meta_type_id);
    Component* c = static_cast<Component*>(ptr);

    try {
        std::string uuid;
        node["uuid"] >> uuid;
        c->mId = boost::uuids::string_generator()(uuid);
    } catch(YAML::TypedKeyNotFound<std::string> e) {
        std::cerr << "Warning: No UUID for Component specified. Generating a new UUID." << std::endl;
    }

    c->OnDeserialize(node);
    return c;
}

void Component::OnSerialize(YAML::Emitter& out) {}

void Component::OnDeserialize(const YAML::Node& node) {}
