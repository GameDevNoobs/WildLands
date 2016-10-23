#include <windowsx.h>
#include "Graphics.h"
#include "SpriteSheet.h"
#include "Timer.h"


void Render(Graphics *gfx);
bool Update(float time);

SpriteSheet *ssh1;
Timer *gameTime;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	} break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}


int WINAPI WinMain(HINSTANCE hInstance,	HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwnd;
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = "WildLands";

	
	if (!RegisterClassEx(&wc)) {
		return (-1);
	}
	
	hwnd = CreateWindowEx(NULL,	"WildLands", "WildLands", WS_OVERLAPPEDWINDOW,  100, 100, 800, 640, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow);

	Graphics *gfx = new Graphics();
	gfx->Initialize(hwnd, true);

	ssh1 = new SpriteSheet(gfx->device, "Male.png", 368, 64, 46);
	gameTime = new Timer();

	//-----------------------------------------------------------

	MSG msg;
	msg.message = WM_NULL;
	while (true)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT) break;
		else
		{
			gameTime->Current();
			if (Update(gameTime->GetTimeInSec()))
				gameTime->Previous();
			Render(gfx);
		}
	}
	
	delete ssh1;
	delete gfx;
	delete gameTime;
	return msg.wParam;
}

void Render(Graphics *gfx) {
	D3DXVECTOR3 pos;
	pos.x = 200;
	pos.y = 200;
	pos.z = 0;
	gfx->ClearScreen(D3DCOLOR_XRGB(0, 100, 100));
	gfx->BeginScene();

	if (ssh1->IsInitialized()) {
		ssh1->Draw(pos);
	}

	gfx->EndScene();
	gfx->Present();
}

bool Update(float time) {
	return ssh1->Update(time);
}