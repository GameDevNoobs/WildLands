#ifndef MAP_H
#define MAP_H

#include "Block.h"
#include <vector>

class Map {
	int mapSize;
	std::vector <Block*> gameMap;
public:
	Map(int N);
	~Map();

	void GenerateMap(Graphics * _gfx);
	void RenderMap();
};

#endif