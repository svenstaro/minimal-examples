default:
	mkdir -p bin/
	g++ -std=c++0x -g -obin/abstract-derived-data.bin src/abstract-derived-data.cpp
	g++ -std=c++0x -g -obin/abstract-derived-data-container.bin src/abstract-derived-data-container.cpp
	g++ -std=c++0x -g -obin/abstract-derived-data-any-container.bin src/abstract-derived-data-any-container.cpp
	g++ -std=c++0x -g -obin/abstract-derived-data-template-container.bin src/abstract-derived-data-template-container.cpp
	g++ -std=c++0x -g -I/usr/include/OGRE/ -lOgreMain -obin/ogre-init.bin src/ogre-init.cpp
	g++ -std=c++0x -g -obin/shared-ptr.bin src/shared-ptr.cpp
	g++ -std=c++0x -g -oshare_ptr-casting.bin share_ptr-casting.cpp
	g++ -std=c++0x -g -obin/inherit-from-template-class.bin src/inherit-from-template-class.cpp
	g++ -std=c++0x -g -obin/ncurses-chat.bin -lncurses -lsfml-system src/ncurses-chat.cpp
	g++ -std=c++0x -g -obin/multimap-sharedptr.bin src/multimap-sharedptr.cpp
	g++ -std=c++0x -g -lsfml-system -obin/sfml-clock.bin -std=c++0x src/sfml-clock.cpp
	g++ -std=c++0x -g -obin/boost-uuid-name-generator.bin src/boost-uuid-name-generator.cpp
	g++ -std=c++0x -g -obin/boost-hash.bin src/boost-hash.cpp
	g++ -std=c++0x -g -obin/boost-ptr-containers.bin src/boost-ptr-containers.cpp

vector-leak:
	 g++ -std=c++0x -g  -obin/vector-leak.bin src/vector-leak.cpp
	
vector-leak-check:
	valgrind --leak-check=full ./bin/vector-leak.bin
