default:
	mkdir -p bin/
	g++ -std=c++0x -g -obin/abstract-derived-data.bin src/abstract-derived-data.cpp
	g++ -std=c++0x -g -obin/abstract-derived-data-container.bin src/abstract-derived-data-container.cpp
	g++ -std=c++0x -g -obin/abstract-derived-data-any-container.bin src/abstract-derived-data-any-container.cpp
	g++ -std=c++0x -g -obin/abstract-derived-data-template-container.bin src/abstract-derived-data-template-container.cpp
	g++ -std=c++0x -g -I/usr/include/OGRE/ -lOgreMain -obin/ogre-init.bin src/ogre-init.cpp
	g++ -std=c++0x -g -obin/shared_ptr.bin src/shared_ptr.cpp
	g++ -std=c++0x -g -obin/shared_ptr-casting.bin src/shared_ptr-casting.cpp
	g++ -std=c++0x -g -obin/inherit-from-template-class.bin src/inherit-from-template-class.cpp
	g++ -std=c++0x -g -obin/ncurses-chat.bin -lncurses -lsfml-system src/ncurses-chat.cpp
	g++ -std=c++0x -g -obin/multimap-sharedptr.bin src/multimap-sharedptr.cpp
	g++ -std=c++0x -g -lsfml-system -obin/sfml-clock.bin -std=c++0x src/sfml-clock.cpp
	g++ -std=c++0x -g -obin/boost-uuid-name-generator.bin src/boost-uuid-name-generator.cpp
	g++ -std=c++0x -g -obin/boost-hash.bin src/boost-hash.cpp
	g++ -std=c++0x -g -obin/boost-ptr-containers.bin src/boost-ptr-containers.cpp

const-reference-member:
	g++ -std=c++0x -g  -obin/const-reference-member.bin src/const-reference-member.cpp

vector-leak:
	 g++ -std=c++0x -g  -obin/vector-leak.bin src/vector-leak.cpp
	 g++ -std=c++0x -g  -obin/vector-leak-shared_ptr.bin src/vector-leak-shared_ptr.cpp
	
vector-leak-check:
	valgrind --leak-check=full ./bin/vector-leak.bin
	valgrind --leak-check=full ./bin/vector-leak-shared_ptr.bin

sfml-handle:
	 g++ -std=c++0x -g -lsfml-window -lsfml-graphics -lsfml-system -obin/sfml-handle.bin src/sfml-handle.cpp

reinterpret:
	g++ -std=c++0x -g -lsfml-window -lsfml-graphics -lsfml-system -obin/reinterpret.bin src/reinterpret.cpp 
