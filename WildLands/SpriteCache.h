#ifndef SPRITECACHE_H
#define SPRITECACHE_H

#include "Graphics.h"
#include "SpriteSheet.h"
#include <vector>

class SpriteCache {

	std::vector<SpriteSheet*> spriteStorage;
	SpriteSheet *tex;
public:
	void Initialise(Graphics *gfx, int _n, std::string _name);
	void SpritesOut();
	std::vector<SpriteSheet*> GetStorage() { return spriteStorage; }
};

#endif
