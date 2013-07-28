#include <cstring>
#include "Keyboard.h"

#if defined(WIN32)
#include <glut.h>
#elif defined(UNIX)
#include <GL/glut.h>
#endif

namespace Farsight
{
	uchar Keyboard::keys[256];

	void Keyboard::BindToGlut()
	{
		memset(Keyboard::keys, GLUT_UP, 256);
		glutKeyboardFunc(KeyboardCallback);
		glutKeyboardUpFunc(KeyboardUpCallback);
	}

	KeyboardState Keyboard::GetState() 
	{
		return KeyboardState(keys);
	}

	void Keyboard::KeyboardCallback(const uchar key, const int x, const int y)
	{
		keys[key] = GLUT_DOWN;
	}

	void Keyboard::KeyboardUpCallback(const uchar key, const int x, const int y)
	{
		keys[key] = GLUT_UP;
	}
};