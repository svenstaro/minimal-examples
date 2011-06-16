#include <iostream>
#include <memory>

class A {
public:
    virtual void lol() {
        std::cout << "A" << std::endl;
    }
};
class B : public A {
public:
    B() { mInt = 10; }
    virtual void lol() {
        std::cout << "B" << std::endl;
    }
    int mInt;
};

std::shared_ptr<A> ptr;

class Tester {
public:
    
    template <typename T> Tester(T* t) {
        ptr = std::shared_ptr<T>(t);
    }

    std::shared_ptr<A> ptr;    
};

int main() {
    Tester ta(new A());
    ta.ptr->lol();
    Tester tb(new B());
    tb.ptr->lol();
    // std::cout << tb.ptr->mInt << std::endl;
}
