#include <iostream>
#include <boost/ptr_container/ptr_vector.hpp>

class LolA{ 
public:
    virtual void Lol() {};
};

class LolB : public LolA{
public:
    void Lol() {}
};
template <typename T> class ABC;

class Other {
public:
    void AddABC(ABC<LolA>* abc);
    boost::ptr_vector<ABC<LolA> > mList; 
};

template <typename T>
class ABC {
public:
    ABC() {}

    T GetT() {
        return mT;
    }

    void SetT(T t) {
        mT = t;
    }

    Other* GetOther() {
        return mOther;
    }
    void SetOther(Other* other) {
        mOther = other;
    }

    virtual std::string GetType() = 0;

protected:
    T mT;
    Other* mOther;    
};


class Derived : public ABC<LolB> {
public:
    Derived(LolB t) {
        mT = t;
    }
    std::string GetType() {
        return "Derived";
    }
};


void Other::AddABC(ABC<LolA>* abc) {
    mList.push_back(abc);
    mList.back().SetOther(this);
}

int main() {
    Other o;
    o.AddABC(new Derived(LolB()));
    std::cout << o.mList.back().GetType() << std::endl;
    o.mList.back().GetT().Lol();
}
