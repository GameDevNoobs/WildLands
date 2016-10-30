#include "SpriteCache.h"



void SpriteCache::Initialise(Graphics *gfx, int _n, std::string _name) {
	for (auto i = 0; i < _n; i++) {
		tex = new SpriteSheet(gfx->device, _name + "_" + std::to_string(i) + ".png", 64, 32, 64);
		spriteStorage.insert(std::pair <std::string, SpriteSheet*> (tex->GetFileName(),tex));
	}
}

void SpriteCache::SpritesOut() {
	spriteStorage.clear();
}

SpriteSheet * SpriteCache::GetTexturePtr(std::string id) {
	for (auto it = spriteStorage.begin(); it != spriteStorage.end(); it++)
	{
		if (std::strcmp(id.c_str(), it->first.c_str())==0) {
			return  it->second;
		}
	}
}