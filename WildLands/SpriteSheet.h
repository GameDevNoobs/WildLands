#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <d3dx9.h>
#include <string>


class SpriteSheet {

	IDirect3DTexture9 *texture;
	ID3DXSprite *sprite;
	D3DXIMAGE_INFO inf;
	D3DCOLOR color;
	SYSTEMTIME cTime, lTime;
	RECT rct;
	float frame;
	int frameWidth;
	int frameCount;
	bool initialized;

public:

	SpriteSheet(IDirect3DDevice9 *device, std::string file, int width, int height, int _frameWidth);
	~SpriteSheet();

	bool Initialize(IDirect3DDevice9 *device, std::string file, int width, int height, int frameWidth);
	bool IsInitialized();
	virtual bool Update(float time);
	virtual void Draw(D3DXVECTOR3 position);
};

#endif
