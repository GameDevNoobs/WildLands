#include "SpriteCache.h"



void SpriteCache::Initialise(Graphics *gfx, int _n, std::string _name) {
	for (auto i = 0; i < _n; i++) {
		tex = new SpriteSheet(gfx->device, _name + "_" + std::to_string(i) + ".png", 32, 16, 32);
		spriteStorage.push_back(tex);
	}
}

void SpriteCache::SpritesOut() {
	spriteStorage.clear();
}