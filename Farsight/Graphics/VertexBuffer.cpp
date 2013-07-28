#include <iostream>

#if defined(WIN32)
#include <glut.h>
#elif defined(UNIX)
#include <GL/glut.h>
#endif

#include "VertexBuffer.h"

namespace Farsight
{
	VertexBuffer::VertexBuffer()
		: id(0)
	{ }

	VertexBuffer::VertexBuffer(const Vertex* vertices, const uint count, const uint primitiveType)
		: id(0)
	{
		this->SetData(vertices, count, primitiveType);
	}

	VertexBuffer::VertexBuffer(const VertexBuffer &buffer)
		: id(buffer.id)
	{ }

	uint VertexBuffer::GetId() const
	{
		return this->id;
	}

	template<>
	void VertexBuffer::SetData(const Vector3* vertices, const uint count, const uint primitiveType)
	{
		// Clear old data if already set.
		if (this->id != 0)
		{
			glDeleteLists(this->id, 1);
		}


		this->id = glGenLists(1);
		if (this->id == 0)
			return;

		glNewList(id, GL_COMPILE);
		
		glBegin(primitiveType);
		for (uint i = 0; i < count; i++) 
		{
			glVertex3f(
				vertices[i].x,
				vertices[i].y,
				vertices[i].z);
		}
		
		glEnd();
		glEndList();

	}

	template<typename Vertex>
	void VertexBuffer::SetData(const Vertex* vertices, const uint count, const uint primitiveType)
	{
		// Clear old data if already set.
		if (this->id != 0)
		{
			glDeleteLists(this->id, 1);
		}

		this->id = glGenLists(1);
		glNewList(id, GL_COMPILE);
		
		glBegin(primitiveType);
		for (uint i = 0; i < count; i++)
		{
			glColor4ub(
				vertices[i].Color.R,
				vertices[i].Color.G,
				vertices[i].Color.B,
				vertices[i].Color.A);
			glVertex3f(
				vertices[i].Position.x,
				vertices[i].Position.y,
				vertices[i].Position.z);
		}
		glEnd();
		glEndList();
	}

	void VertexBuffer::SetId(const uint id)
	{
		this->id = id;
	}
};