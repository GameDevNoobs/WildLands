#include "Map.h"
#include <cmath>

Map::Map(int N) {
	mapSize = N;
	gameMap.reserve(std::pow(mapSize, 2));
}

Map::~Map() {
	gameMap.clear();
}

void Map::GenerateMap(Graphics * _gfx, SpriteCache gs) {
	Block *b;
	D3DXVECTOR3 vec;

	for (auto i = 0; i < mapSize; i++) {
		for (auto j = 0; j < mapSize; j++) {
			b = new Block(_gfx, gs);
			vec.x = i;
			vec.y = j;
			b->SetBlock(vec);
			gameMap.push_back(b);
		}
	}
}

void Map::RenderMap() {
	for (auto iter = gameMap.begin(); iter != gameMap.end(); iter++) {
		(*iter)->RenderBlock();
	}
}