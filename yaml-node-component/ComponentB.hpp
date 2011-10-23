#ifndef COMPONENT_B
#define COMPONENT_B

#include "Component.hpp"

class ComponentB : public Component {
    Q_OBJECT
public:
    void SayName();
};

#endif
