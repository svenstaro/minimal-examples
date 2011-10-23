#include "ComponentA.hpp"

ComponentA::ComponentA() {}

void ComponentA::SayName() {
    std::cout << "Name: Component A" << std::endl;
}

void ComponentA::OnSerialize(YAML::Emitter& out) {
    // With nice IOPackets it would look like this.
    //
    // int a_value = 100;
    // YamlIOPacket.ReadWrite("a_value", a_value);
    // assert(a_value == 100);
    out << YAML::Key << "a_value" << YAML::Value << 100;    
}

void ComponentA::OnDeserialize(const YAML::Node& node) {
    int a = 0;
    node["a_value"] >> a;
    assert(a == 100);
}
