#ifndef COMPONENT_B
#define COMPONENT_B

#include "Component.hpp"

class ComponentB : public Component {
    Q_OBJECT
public:
    void SayName();
};
//Q_DECLARE_METATYPE(ComponentB)

#endif
