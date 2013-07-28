#include "KeyboardState.h"
#include <glut.h>

namespace Farsight
{
	KeyboardState::KeyboardState()
	{
		for (int i = 0; i < 256; i++)
		{
			keys[i] = GLUT_UP;
		}
	}

	KeyboardState::KeyboardState(const uchar keys[256])
	{
		SetKeys(keys);
	}

	KeyboardState::KeyboardState(const KeyboardState &state)
	{
		SetKeys(state.keys);
	}

	bool KeyboardState::IsKeyDown(const uchar key) const
	{
		return (keys[key] == GLUT_DOWN);
	}

	bool KeyboardState::IsKeyUp(const uchar key) const
	{
		return (keys[key] == GLUT_UP);
	}

	void KeyboardState::SetKeys(const uchar keys[256])
	{
		for (int i = 0; i < 256; i++)
		{
			this->keys[i] = keys[i];
		}
	}

	void KeyboardState::operator=(const KeyboardState &state)
	{
		SetKeys(state.keys);
	}
};