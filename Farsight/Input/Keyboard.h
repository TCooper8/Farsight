#pragma once

#include "KeyboardState.h"

namespace Farsight
{
	class Keyboard
	{
		static uchar keys[256];

	public:
		static void BindToGlut();
		static KeyboardState GetState();
		static void KeyboardCallback(const uchar key, const int x, const int y);
		static void KeyboardUpCallback(const uchar key, const int x, const int y);
	};
};