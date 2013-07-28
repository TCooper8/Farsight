#include <math.h>
#include <glut.h>
#include "Vertex.h"

namespace Farsight
{
	Vertex::Vertex()
		: Position(), Color()
	{ }

	Vertex::Vertex(const Vector3 &position, const Color4 &color)
		: Position(position), Color(color)
	{ }

	Vertex::Vertex(const Vertex &vertex)
		: Position(vertex.Position), Color(vertex.Color)
	{ }

	void Vertex::operator=(const Vertex &vertex)
	{
		this->Position = vertex.Position;
		this->Color = vertex.Color;
	}
};