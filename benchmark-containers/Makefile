default: build run

build:
	g++ -Wall -Wextra -Werror -Wshadow -pedantic -Wno-unused-parameter -O0 -g -std=c++0x -I/usr/include/QtCore -lQtCore main.cpp -obenchmark.bin

run:
	./benchmark.bin
