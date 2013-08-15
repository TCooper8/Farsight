#include <cstring>
#include <Windows.h>
#include "Keyboard.h"

#if defined(WIN32)
#include <glut.h>
#elif defined(UNIX)
#include <GL/glut.h>
#endif

namespace Farsight
{
	uchar Keyboard::keys[256];

	KeyboardState Keyboard::GetState() 
	{
		GetKeyboardState(keys);
		return KeyboardState(keys);
	}
};