#include "Block.h"

Block::Block(Graphics * _gfx, SpriteCache gs) {
	texId = 0;
	std::string curBlockTex = "ground_" + std::to_string(texId)+".png";
	for (auto iter = gs.GetStorage().begin(); iter != gs.GetStorage().end(); iter++) {
		if (std::strcmp((*iter)->GetFileName().c_str(), curBlockTex.c_str()) == 0) {
			texture = *iter;
		}
	}
	accessibility = true;
}

inline int ToScreenX(D3DXVECTOR3 _map) {
	int screenX = (_map.x - _map.y) * 16;
	return screenX;
}

inline int ToScreenY(D3DXVECTOR3 _map) {

	int screenY = (_map.x + _map.y) * 8;
	return screenY;
}

void Block::ComputeScreenPosition() {
	screenPosition.x = ToScreenX(position);
	screenPosition.y = ToScreenY(position);
}

void Block::RenderBlock() {
	texture->Draw(screenPosition);
}

void Block::SetBlock(D3DXVECTOR3 _vec) {
	position.x = _vec.x;
	position.y = _vec.y;
	ComputeScreenPosition();
}

Block::~Block() {
	delete texture;
}