#include <iostream>
#include <vector>
#include <memory>
#include <cstdint>
#include <boost/ptr_container/ptr_vector.hpp>

class Base {
public:
    virtual std::shared_ptr<Base> Clone() = 0;
};

class Derived : public Base {
public:
    std::vector<uint64_t> container;

    Derived() {
        std::cout << "omg" << std::endl;
        container.push_back(0);
    }

    std::shared_ptr<Base> Clone() {
        std::shared_ptr<Base> ptr(new Derived);
        return ptr;
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

    std::shared_ptr<Base> GetClone(int index) {
        for(auto iter = bs.begin(); iter != bs.end(); ++iter) {
            return iter->Clone();
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
    std::shared_ptr<Base> b = f.GetClone(0);
    
    // make a safe pointer
    std::shared_ptr<Base> b_ptr(b);

    // convert to correct class
    // this is actually done after checking the type
    std::shared_ptr<Derived> d_ptr = std::dynamic_pointer_cast<Derived>(b_ptr);

    // use that
    d_ptr->SayHello();

    return 0;
}
