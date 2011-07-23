#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow w;
    w.Create(sf::VideoMode(1024, 768, 32), "Render Window");
    std::cout << w.GetSystemHandle() << std::endl;
    return 0;
}
