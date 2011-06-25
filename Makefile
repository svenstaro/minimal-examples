default:
	g++ -std=c++0x -g -oabstract-derived-data.bin abstract-derived-data.cpp
	g++ -std=c++0x -g -oabstract-derived-data-container.bin abstract-derived-data-container.cpp
	g++ -std=c++0x -g -oabstract-derived-data-any-container.bin abstract-derived-data-any-container.cpp
	g++ -std=c++0x -g -oabstract-derived-data-template-container.bin abstract-derived-data-template-container.cpp
	g++ -std=c++0x -g -I/usr/include/OGRE/ -lOgreMain -oogre-init.bin ogre-init.cpp
	g++ -std=c++0x -g -oshared-ptr.bin shared-ptr.cpp
	g++ -std=c++0x -g -oinherit-from-template-class.bin inherit-from-template-class.cpp
	g++ -std=c++0x -g -oncurses-chat.bin -lncurses -lsfml-system ncurses-chat.cpp
	g++ -std=c++0x -g -omultimap-sharedptr.bin multimap-sharedptr.cpp
	g++ -std=c++0x -g -llsfml-system -osfml-clock.bin -std=c++0x sfml-clock.cpp 
	g++ -std=c++0x -g -oboost-uuid-name-generator.cpp boost-uuid-name-generator.cpp
