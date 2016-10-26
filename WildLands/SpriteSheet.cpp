#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(IDirect3DDevice9 *device, std::string file, int width, int height, int _frameWidth) {

	color = D3DCOLOR_ARGB(255, 255, 255, 255);
	initialized = false;
	if (Initialize(device, file, width, height, _frameWidth))
		initialized = true;
	fileName = file;
}

bool SpriteSheet::Initialize(IDirect3DDevice9 *device, std::string file, int width, int height, int _frameWidth) {

	frameWidth = _frameWidth;
	if (!SUCCEEDED(D3DXCreateTextureFromFileEx(device, file.c_str(), width, height, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &inf, NULL, &texture))) {
		std::string s = "There was an issue creating the Texture.  Make sure the requested image is available.  Requested image: " + file;
		MessageBox(NULL, s.c_str(), NULL, NULL);
		return false;
	}

	if (!SUCCEEDED(D3DXCreateSprite(device, &sprite)))
	{
		MessageBox(NULL, "There was an issue creating the Sprite.", NULL, NULL);
		return false;
	}

	frameCount = inf.Width / frameWidth;
	rct.left = 0;
	rct.right = frameWidth;
	rct.top = 0;
	rct.bottom = inf.Height;
	return true;
}

bool SpriteSheet::IsInitialized() {
	return initialized;
}

bool SpriteSheet::Update(float time) {
	if (time >= 0.1f) {
		if (frame < frameCount) {
			rct.left = frame * frameWidth;
			rct.right = rct.left + frameWidth;
			frame++;
		}
		else
		{
			frame = 0;
			rct.left = 0;
			rct.right = frameWidth;
			rct.left = frame * frameWidth;
			rct.right = rct.left + frameWidth;
			frame++;
		}
		return true;
	}
	return false;
}

void SpriteSheet::Draw(D3DXVECTOR3 position) {

	if (sprite&&texture) {
		sprite->Begin(D3DXSPRITE_ALPHABLEND);
		sprite->Draw(texture, &rct, NULL, &position, color);
		sprite->End();
	}
}

SpriteSheet::~SpriteSheet()
{
	if (sprite)
	{
		sprite->Release();
		sprite = NULL;
	}

	if (texture)
	{
		texture->Release();
		texture = NULL;
	}
}