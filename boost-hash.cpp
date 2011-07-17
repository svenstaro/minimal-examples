#include <boost/functional/hash.hpp>
#include <iostream>

int main() {
    boost::hash<std::string> string_hash;
    std::size_t hash = string_hash("lolhash");

    std::cout << hash << std::endl;
    std::cout << string_hash("lol") << std::endl;

    return 0;
}
