#include <iostream>
#include <string>

class AbstractBase {
public:
    AbstractBase() : base_data("unchanged") {}
    virtual ~AbstractBase() = 0;
    std::string base_data;
};

AbstractBase::~AbstractBase() {}

class Derived : public AbstractBase {
public:
    Derived() : derived_data("unchanged") {}
    std::string derived_data;
};

int main() {
    Derived* d = new Derived();
    d->base_data = "changed";
    d->derived_data = "changed";
    AbstractBase* ab = d;

    std::cout << "AbstractBase member data: " << ab->base_data << std::endl;
    std::cout << "Derived member data: " << (dynamic_cast<Derived*>(ab))->derived_data << std::endl;

    return 0;
}
