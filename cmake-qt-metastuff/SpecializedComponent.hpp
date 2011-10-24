#ifndef SPECIALIZEDCOMPONENT_HPP
#define SPECIALIZEDCOMPONENT_HPP

#include "Component.hpp"

#include <QMetaType>

#include <string>

class SpecializedComponent : public Component {
    Q_OBJECT
public:
    SpecializedComponent();
    SpecializedComponent(const SpecializedComponent& other);
    ~SpecializedComponent();

    void ShowName();

    std::string mName;
};

#endif
