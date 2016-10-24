#ifndef BLOCK_H
#define BLOCK_H

#include "Graphics.h"
#include "SpriteSheet.h"


class Block {

	D3DXVECTOR3 position, screenPosition;
	SpriteSheet *texture;
	bool accessibility;
public:
	Block(Graphics * _gfx);
	~Block();
	void RenderBlock();
	void ComputeScreenPosition();
	void SetBlock(D3DXVECTOR3 _vec);
};

#endif
