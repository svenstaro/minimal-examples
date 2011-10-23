#ifndef COMPONENT_A
#define COMPONENT_A

#include "Component.hpp"

class ComponentA : public Component {
    Q_OBJECT
public:
    void SayName();

    void OnSerialize(YAML::Emitter& out);
    void OnDeserialize(const YAML::Node& node);
};

#endif
