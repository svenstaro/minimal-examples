#include <string>
#include <iostream>

class Lol {
public:
    Lol(const std::string& text) : mText(text) {}
    void Hi() { std::cout << mText << std::endl; }
private:
    const std::string& mText;
};


int main() {
    Lol lol("omg");
    lol.Hi();
}
