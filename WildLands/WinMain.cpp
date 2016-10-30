#include <windowsx.h>
#include "GameController.h"

int wndWidth, wndHight;
Graphics * gfx;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	} break;
	case WM_KEYDOWN:
		switch (wParam) {
		case 'A':
		case VK_LEFT:
			GameController::camPosition.x++;
			break;
		case 'D':
		case VK_RIGHT:
			GameController::camPosition.x--;
			break;
		case 'S':
		case VK_DOWN:
			GameController::camPosition.y--;
			break;
		case 'W':
		case VK_UP:
			GameController::camPosition.y++;
			break;
		}
	break;

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
	
	wndWidth = 800;
	wndHight = 640;

	hwnd = CreateWindowEx(NULL,	"WildLands", "WildLands", WS_OVERLAPPEDWINDOW,  100, 100, wndWidth, wndHight, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow);

	gfx = new Graphics();
	GameController::Initialize(gfx, hwnd, wndWidth, wndHight);

	//************************ MAIN LOOP *******************************

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
			GameController::Update();
			GameController::Render(gfx, wndWidth, wndHight);
		}
	}
	
	//******************************************************
	delete gfx;
	return msg.wParam;
}