#ifndef SPRITECACHE_H
#define SPRITECACHE_H

#include "Graphics.h"
#include "SpriteSheet.h"
#include <map>

class SpriteCache {

	std::map<std::string, SpriteSheet*> spriteStorage;
	SpriteSheet *tex;
public:
	void Initialise(Graphics *gfx, int _n, std::string _name);
	void SpritesOut();
	SpriteSheet* GetTexturePtr(std::string id);
};

#endif
