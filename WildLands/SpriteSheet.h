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
	float frame;
	int frameWidth;
	int frameCount;
	bool initialized;
	std::string fileName;
	D3DXVECTOR3 position;

public:
	RECT rct;
	SpriteSheet(IDirect3DDevice9 *device, std::string file, int width, int height, int _frameWidth);
	~SpriteSheet();

	bool Initialize(IDirect3DDevice9 *device, std::string file, int width, int height, int frameWidth);
	bool IsInitialized();
	virtual bool Update(float time);
	virtual void Draw(int posX, int posY, int _wndWidth, int _wndHight);
	std::string GetFileName() { return fileName;}
	RECT GetSize() { return this->rct; }
};

#endif
