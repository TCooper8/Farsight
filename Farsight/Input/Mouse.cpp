#include <Windows.h>
#include "Mouse.h"

namespace Farsight
{
	MouseState Mouse::GetState()
	{
		LPPOINT p;
		GetCursorPos(p);
		HWND hWnd = GetActiveWindow();

		ScreenToClient(hWnd, p);

		return MouseState(
			false,
			false,
			Vector3(p->x, p->y, 0));
	}
};