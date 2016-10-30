#include "GameController.h"

#define CAMERASPEED 16

SpriteCache GameController::groundCache;
D3DXVECTOR3 GameController::camPosition;
Map * GameController::map;
Timer * GameController::timer;
SpriteSheet * GameController::character;

void GameController::Initialize(Graphics * _gfx, HWND _hwnd, int wndWidth, int wndHeight) {

	//=================== GRAPHICS DEVICE ================
	_gfx->Initialize(_hwnd, true);

	//=================== CAMERA =========================
	camPosition.x = 0;
	camPosition.y = 0;
	camPosition.z = 0;
	//=================== SPRITE CACHE ===================
	groundCache.Initialise(_gfx, 1, "ground");

	//=================== MAP ============================
	map = new Map(100);
	map->GenerateMap(_gfx, groundCache);

	//==================  TIMER ==========================
	timer = new Timer();

	character = new SpriteSheet(_gfx->device, "Male.png", 384, 64, 48);
}

void GameController::Render(Graphics *gfx, int wndWidth, int wndHeight) {
	gfx->ClearScreen(D3DCOLOR_XRGB(0, 100, 100));
	gfx->BeginScene();

	map->RenderMap(camPosition.x*CAMERASPEED, camPosition.y*CAMERASPEED, wndWidth, wndHeight);
	character->Draw(camPosition.x*CAMERASPEED, camPosition.y*CAMERASPEED, wndWidth, wndHeight);
	gfx->EndScene();
	gfx->Present();
}


void GameController::Update() {

	timer->Current();
	if (character->Update(timer->GetTimeInSec()))
		timer->Previous();
}
