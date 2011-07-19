#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <iostream>

int main() {
    boost::uuids::uuid dns_namespace_uuid;

    boost::uuids::name_generator gen(dns_namespace_uuid);
    boost::uuids::uuid u = gen("boost.org");

    std::cout << u << std::endl;

    return 0;
}
