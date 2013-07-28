#include "Color4.h"

namespace Farsight
{
	const Color4 Color4::White (255, 255, 255, 255);
	const Color4 Color4::Black (0, 0, 0, 255);

	Color4::Color4()
		: R(0), G(0), B(0), A(255)
	{ }

	Color4::Color4(const uint8 r, const uint8 g, const uint8 b, const uint8 a)
		: R(r), G(g), B(b), A(a)
	{ }

	Color4::Color4(const Color4 &color)
		: R(color.R), G(color.G), B(color.B), A(color.A)
	{ }

	void Color4::operator=(const Color4 &color)
	{
		this->R = color.R;
		this->G = color.G;
		this->B = color.B;
		this->A = color.A;
	}
};