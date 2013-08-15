#include <Windows.h>

#include "glGraphicsDevice.h"

#if defined(WIN32)
#include <gl/GL.h>
#include <gl/GLU.h>
#elif defined(UNIX)
#include <GL/glut.h>
#endif

namespace Farsight
{
	LRESULT CALLBACK WindowProc(HWND hWnd,
								UINT message,
								WPARAM wParam,
								LPARAM lParam)
	{
		switch(message)
		{
		case WM_DESTROY:
			{
				PostQuitMessage(0);
				return 0;
			} break;
		}

		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	 glGraphicsDevice::glGraphicsDevice()
	 { }

	 bool glGraphicsDevice::Initialize()
	 {
		 WNDCLASSEX wcex;
		 HWND hWnd;
		 HGLRC hRC;

		 HINSTANCE hInstance = GetModuleHandle(0);
		 
		 // Register new window class.
		 wcex.cbSize = sizeof(WNDCLASSEX);
		 wcex.style = CS_OWNDC;
		 wcex.lpfnWndProc = WindowProc;
		 wcex.cbClsExtra = 0;
		 wcex.cbWndExtra = 0;
		 wcex.hInstance = hInstance;
		 wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		 wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		 wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		 wcex.lpszMenuName = NULL;
		 wcex.lpszClassName = L"GLSample";
		 wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

		 if (!RegisterClassEx(&wcex))
			 return false;

		 hWnd = CreateWindowEx(
			 0,
			 L"GLSample",
			 L"Farsight Sample",
			 WS_OVERLAPPEDWINDOW,
			 CW_USEDEFAULT,
			 CW_USEDEFAULT,
			 Params.BackBufferWidth,
			 Params.BackBufferHeight,
			 NULL,
			 NULL,
			 hInstance,
			 NULL);

		 ShowWindow(hWnd, true);

		 // Enable OpenGL.
		 PIXELFORMATDESCRIPTOR pixelFormat;
		 int iFormat;
		 
		 // Get device context
		 hDC = GetDC(hWnd);

		 ZeroMemory(&pixelFormat, sizeof(pixelFormat));

		 pixelFormat.nSize = sizeof(pixelFormat);
		 pixelFormat.nVersion = 1;
		 pixelFormat.dwFlags = 
			 PFD_DRAW_TO_WINDOW |
			 PFD_SUPPORT_OPENGL | 
			 PFD_DOUBLEBUFFER;
		 pixelFormat.iPixelType = PFD_TYPE_RGBA;
		 pixelFormat.cColorBits = 24;
		 pixelFormat.cDepthBits = 16;
		 pixelFormat.iLayerType = PFD_MAIN_PLANE;

		 iFormat = ChoosePixelFormat(hDC, &pixelFormat);

		 SetPixelFormat(hDC, iFormat, &pixelFormat);

		 // Create and enable the render context.
		 hRC = wglCreateContext(hDC);
		 wglMakeCurrent(hDC, hRC);

		 return true;
	 }

	 void glGraphicsDevice::DrawBuffer(const VertexBuffer &buffer)
	 {
		 glCallList(buffer.GetId());
	 }

	 void glGraphicsDevice::Clear(const Color4& color)
	 {
		 const float scale = 1.0f / 255.0f;
		 glClearColor(color.R * scale, color.G * scale, color.B * scale, color.A * scale);
		 glClear(GL_COLOR_BUFFER_BIT);
	 }

	 void glGraphicsDevice::Present()
	 {
		 SwapBuffers(hDC);
	 }
};