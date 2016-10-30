#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Map.h"
#include "Timer.h"

static class GameController {
	GameController() {}
	static SpriteCache groundCache;
	static Map * map;
	static Timer * timer;
	static SpriteSheet * character;
public: 
	static D3DXVECTOR3 camPosition;
	static void Initialize(Graphics * _gfx, HWND _hwnd, int wndWidth, int wndHeight);
	static void Render(Graphics *gfx, int wndWidth, int wndHeight);
	static void Update();
};

#endif
