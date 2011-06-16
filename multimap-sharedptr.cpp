#include <map>
#include <iostream>
#include <memory>

class Lol {

};

int main() {
    std::multimap<std::string, std::shared_ptr<Lol>> map1;
    map1.insert(std::pair<std::string, std::shared_ptr<Lol>>("rofl", std::shared_ptr<Lol>(new Lol())));

    std::cout << "Map 1: " << map1.find("rofl")->second.use_count() << std::endl;

    auto map2 = map1;

    std::cout << "Map 1: " << map1.find("rofl")->second.use_count() << std::endl;
    std::cout << "Map 2: " << map2.find("rofl")->second.use_count() << std::endl;
}
