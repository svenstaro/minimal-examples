#include <iostream>
#include <memory>
#include <map>
#include <string>

class AbstractBase {
public:
    AbstractBase() : base_data("base_data") {}
    virtual ~AbstractBase() = 0;
    std::string base_data;
};

AbstractBase::~AbstractBase() {}

class Derived : public AbstractBase {
public:
    Derived() : derived_data("derived_data") {}
    std::string derived_data;
};

class Manager {
public:
    AbstractBase* Get(const std::string& name) const {
        for(std::pair<std::string, std::shared_ptr<AbstractBase>> set: mStuff) {
            if(set.first == name)
                return set.second.get();
        }
        return nullptr;
    }

    void Add(const std::string& string, std::shared_ptr<AbstractBase> object) {
        mStuff.insert(std::pair<std::string, std::shared_ptr<AbstractBase>>(string, object));
    }
private:
    std::multimap<std::string, std::shared_ptr<AbstractBase>> mStuff;
};

int main() {
    Manager manager;

    std::shared_ptr<Derived> d(new Derived);

    manager.Add("lol", d);

    std::cout << manager.Get("lol")->base_data << std::endl;
    //std::cout << manager.Get("lol")->derived_data << std::endl;

    return 0;
}
