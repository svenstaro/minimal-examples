default:
	g++ -std=c++0x -g -oabstract-derived-data.bin abstract-derived-data.cpp
	g++ -std=c++0x -g -oabstract-derived-data-container.bin abstract-derived-data-container.cpp
	g++ -std=c++0x -g -oabstract-derived-data-any-container.bin abstract-derived-data-any-container.cpp
	g++ -std=c++0x -g -oabstract-derived-data-template-container.bin abstract-derived-data-template-container.cpp
	g++ -std=c++0x -g -I/usr/include/OGRE/ -lOgreMain -oogre-init.bin ogre-init.cpp
