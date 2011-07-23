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
    std::vector<uint16_t> container;
    uint64_t lol;

    Derived() {
        container.push_back(0);
        lol = 10;
    }

    std::shared_ptr<Base> Clone() {
        return std::shared_ptr<Base>(new Derived());
    }

    void SayHello() {
        std::cout << "Hello from Derived!" << std::endl;
    }
};

class Factory {
public:
    void Register(Base* b) {
        std::shared_ptr<Base> base(b);
        bs.push_back(base);
    }

    std::shared_ptr<Base> Get(int index) {
        return bs[index];
    }

    std::shared_ptr<Base> GetClone(int index) {
        for(auto iter = bs.begin(); iter != bs.end(); ++iter) {
            return (*iter)->Clone();
        }
        return bs[index]->Clone();
    }

    std::vector<std::shared_ptr<Base>> bs;
};

int main() {
    Factory f;
    
    // register prototype
    f.Register(new Derived()); // leak

    // get the prototype instance and clone it
    // Base* p = f.Get(0);
    // Base* b = p->Clone();
    //Base* b = f.GetClone(0); // leak

    // make a safe pointer
    //std::shared_ptr<Base> b_ptr(b);
    
    std::shared_ptr<Base> b_ptr = f.GetClone(0);



    // convert to correct class
    // this is actually done after checking the type
    std::shared_ptr<Derived> d_ptr = std::dynamic_pointer_cast<Derived>(b_ptr);

    // use that
    d_ptr->SayHello();

    return 0;
}
