#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <windows.h>
#include <d3dx9.h>

class Graphics {

	IDirect3D9 * d3d;

public:
	IDirect3DDevice9 * device;

	Graphics();
	~Graphics();

	void Initialize(HWND hwnd, bool windowed);
	void BeginScene();
	void EndScene();
	void Present();
	void ClearScreen(D3DCOLOR color);
};

#endif