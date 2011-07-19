#include <type_traits>

class A {};
class B : public A {};
class C : public B {};
template <typename T> class Base {
    public: void Lol() {}
};
class Derived : public Base<B> {};

template <typename T> void Go(T base) {
    //static_assert(std::is_base_of<Base<A>, T>::value, "omg");
    base.Lol();
}

int main() {
    Derived d;
    Go<Derived>(d);
}
