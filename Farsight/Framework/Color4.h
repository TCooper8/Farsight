#pragma once

#include "../FarSystem.h"

namespace Farsight
{
	// Represents a color using Red, Green, Blue and Alpha values.
	class Color4
	{
	public:
		// Represents the Red-component value.
		uint8 A;
		// Represents the Blue-component value.
		uint8 B;
		// Represents the Green-component value.
		uint8 G;
		// Represents the Red-component value.
		uint8 R;

		// Represents a predefined color with the value R:0 G:0 B:0 A:255.
		static const Color4 Black;
		// Represents a predefined color with the value R:255 G:255 B:255 A:255.
		static const Color4 White;

		// Initializes a new instance of Color4 as (0, 0, 0, 0).
		Color4();
		// Initializes a new instance of Color4 as (r, g, b, a).
		Color4(const uint8 r, const uint8 g, const uint8 b, const uint8 a);
		// Initializes a new copied instance of Color4.
		Color4(const Color4 &color);

		void operator=(const Color4 &color);
	};
};