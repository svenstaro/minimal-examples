#include <iostream>
#include <SFML/System.hpp>
#include <ncurses.h>

bool running;
std::string buf;

void write_line(std::string string) {
    string = "\r" + string + "\n" + buf;
    printw(&string[0]);
    refresh();
}

void in_thread() {
    bool inrun = true;
    while(inrun) {
        char ch = getch();
        if(ch == 10) {
            std::string get = buf;
            buf = "";
            write_line("You said: " + get);
        } else {
            buf += ch;
        }
    }
}


int main() {
    initscr();
    cbreak();
  
    sf::Thread t(&in_thread);
    t.Launch();

    running = true;
    while(running) {
        write_line("It's too late!");
        sf::Sleep(2000);
    }
    endwin();
}
