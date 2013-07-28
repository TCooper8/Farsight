#pragma once

#include "../Framework/Vector3.h"
#include "../Framework/Color4.h"

namespace Farsight
{
	class Vertex
	{
	public:
		Vector3 Position;
		Color4 Color;

		Vertex();
		Vertex(const Vector3 &position, const Color4 &color);
		Vertex(const Vertex &vertex);

		void operator=(const Vertex &vertex);
	};
};