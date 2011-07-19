#include <iostream>
#include <SFML/System.hpp>

int main() {
    sf::Clock c;
    while(true) {
        uint32_t t = c.GetElapsedTime();
        if(t > 0) {
            std::cout << "There is a remainder." << std::endl;
            break;
        }
        c.Reset();
    }
}
