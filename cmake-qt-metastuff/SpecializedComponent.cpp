#include "SpecializedComponent.hpp"

#include <iostream>

SpecializedComponent::SpecializedComponent() {
    mName = "node";
}

SpecializedComponent::~SpecializedComponent() {}

void SpecializedComponent::ShowName() {
    std::cout << mName << std::endl;
}
