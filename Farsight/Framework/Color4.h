#pragma once

#include "../FarSystem.h"

namespace Farsight
{
	class Color4
	{
	public:
		uint8 R;
		uint8 G;
		uint8 B;
		uint8 A;

		static const Color4 White;
		static const Color4 Black;

		Color4();
		Color4(const uint8 r, const uint8 g, const uint8 b, const uint8 a);
		Color4(const Color4 &color);

		void operator=(const Color4 &color);
	};
};