#include "SpecializedComponent.hpp"

#include <iostream>

SpecializedComponent::SpecializedComponent() {
    mName = "node";
}

SpecializedComponent::SpecializedComponent(const SpecializedComponent& other) {}

SpecializedComponent::~SpecializedComponent() {}

void SpecializedComponent::ShowName() {
    std::cout << mName << std::endl;
}
