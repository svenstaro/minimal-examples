#include <cstdlib>
#include <string>

#include <boost/ptr_container/ptr_map.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

class wat {
public:
    wat() : m_big_stuff("oddadidnnj2") {}
private:
    std::string m_big_stuff;
};

int main() {
    boost::ptr_map<std::string, wat> map1;
    boost::ptr_map<std::string, wat> map2;
    boost::ptr_vector<wat> vector1;

    std::string key("omg");

    wat lol;                    // Wrong
    map1[key] = lol;            // Wrong
    map2.insert(key, new wat);  // Right

    vector1.push_back(new wat); // Right

    return 0;
}
