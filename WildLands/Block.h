#ifndef BLOCK_H
#define BLOCK_H

#include "SpriteCache.h"

class Block {

	D3DXVECTOR3 position, screenPosition;
	SpriteSheet *texture;
	bool accessibility;
	int texId;
public:
	Block(Graphics * _gfx, SpriteCache gs);
	~Block();
	void RenderBlock();
	void ComputeScreenPosition();
	void SetBlock(D3DXVECTOR3 _vec);
};

#endif
