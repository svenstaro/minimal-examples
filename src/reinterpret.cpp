#include <iostream>

class Parent {
public:
    Parent() { pos = 10; }

    virtual void Lol() {
        std::cout << "Lol Parent" << std::endl;
        std::cout << pos << std::endl;
    }

protected:
    int pos;
};

class Child : public Parent {
public:
    Child() { size = 20; }

    virtual void Lol() {
        std::cout << "lol Child" << std::endl;
        std::cout << size << " " << pos << std::endl;
    }

private:
    int size;
};

int main() {
    void* ptr = new Child;
    Parent* pa = reinterpret_cast<Parent*>(ptr);
    pa->Lol();
}
