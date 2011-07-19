#include <iostream>
#include <vector>
#include <memory>
#include <cstdint>
#include <boost/ptr_container/ptr_vector.hpp>

class Base {
public:
    virtual Base* Clone() = 0;
};

class Derived : public Base {
public:
    std::vector<uint16_t> container;
    uint64_t lol;

    Derived() {
        container.push_back(0);
        lol = 10;
    }

    Base* Clone() {
        return new Derived();
    }

    void SayHello() {
        std::cout << "Hello from Derived!" << std::endl;
    }
};

class Factory {
public:
    void Register(Base* b) {
        bs.push_back(b);
    }

    Base* Get(int index) {
        return (Base*)&bs[index];
    }

    Base* GetClone(int index) {
        for(auto iter = bs.begin(); iter != bs.end(); ++iter) {
            return (Base*)iter->Clone();
        }
        return ((Base*)&bs[index])->Clone();
    }

    boost::ptr_vector<Base> bs;
};

int main() {
    Factory f;
    
    // register prototype
    f.Register(new Derived());

    // get the prototype instance and clone it
    // Base* p = f.Get(0);
    // Base* b = p->Clone();
    Base* b = f.GetClone(0);
    
    // make a safe pointer
    std::shared_ptr<Base> b_ptr(b);

    // convert to correct class
    // this is actually done after checking the type
    std::shared_ptr<Derived> d_ptr = std::dynamic_pointer_cast<Derived>(b_ptr);

    // use that
    d_ptr->SayHello();

    return 0;
}
