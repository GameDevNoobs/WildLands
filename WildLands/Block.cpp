#include "Block.h"

Block::Block(Graphics * _gfx) {

	texture = new SpriteSheet(_gfx->device,"ground.png",32,16,32);
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