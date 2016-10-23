#include "Graphics.h"

Graphics::Graphics() {
	d3d = NULL;
	device = NULL;
}

void Graphics::Initialize(HWND hwnd, bool windowed) {

	d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dparam;

	ZeroMemory(&d3dparam, sizeof(d3dparam));
	d3dparam.Windowed = windowed;
	d3dparam.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dparam.hDeviceWindow = hwnd;

	d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dparam, &device);
}

void Graphics::BeginScene() {
	device->BeginScene();
}

void Graphics::EndScene() {
	device->EndScene();
}


void Graphics::Present() {
	device->Present(NULL, NULL, NULL, NULL);
}

void Graphics::ClearScreen(D3DCOLOR color) {
	device->Clear(0, NULL, D3DCLEAR_TARGET, color, 1.0f, 0);
}

Graphics::~Graphics() {
	if (device) {
		device->Release();
		device = NULL;
	}
	if (d3d) {
		d3d->Release();
		d3d = NULL;
	}
}