#include "Block.h"
#include <math.h>


Block::Block(Graphics * _gfx, SpriteCache gs) {
	texId = 0;
	std::string curBlockTex = "ground_" + std::to_string(texId) + ".png";
	texture = gs.GetTexturePtr(curBlockTex);
	accessibility = true;
}

inline int ToScreenX(D3DXVECTOR3 _map, int texWidth, int texHeight) {
	return ((int)_map.y % 2 == 0) ? _map.x * texWidth : _map.x * texWidth + texWidth/2;
}

inline int ToScreenY(D3DXVECTOR3 _map, int texWidth, int texHeight) {
	return ((int)_map.y % 2 == 0) ? _map.y * texHeight - (floor(_map.y/2)*texHeight) : _map.y * texHeight - texHeight/2 - (floor(_map.y / 2) * texHeight);
}

void Block::ComputeScreenPosition() {
	screenPosition.x = ToScreenX(position, texture->GetSize().right, texture->GetSize().bottom);
	screenPosition.y = ToScreenY(position, texture->GetSize().right, texture->GetSize().bottom);
}

void Block::RenderBlock(int posX, int posY, int _wndWidth, int _wndHight) {
	texture->Draw(screenPosition.x+posX, screenPosition.y + posY, _wndWidth, _wndHight);
}

void Block::SetBlock(D3DXVECTOR3 _vec) {
	position.x = _vec.x;
	position.y = _vec.y;
	ComputeScreenPosition();
}

Block::~Block() {
	delete texture;
}