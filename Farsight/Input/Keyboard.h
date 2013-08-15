#pragma once

#include "KeyboardState.h"

namespace Farsight
{
	class Keyboard
	{
		static uchar keys[256];

	public:
		static KeyboardState GetState();
	};
};