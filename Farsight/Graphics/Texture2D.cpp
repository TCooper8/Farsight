#include <iostream>

#if defined(WIN32)
#include <glut.h>
#elif defined(UNIX)
#include <GL/glut.h>
#endif

#include "Texture2D.h"
#include "../Framework/Color4.h"

namespace Farsight
{
	Texture2D::Texture2D()
		: id(0)
	{ }

	uint Texture2D::GetId() const
	{
		return id;
	}

	uint Texture2D::GetFormat() const
	{
		return format;
	}

	int Texture2D::GetHeight() const
	{
		return height;
	}

	int Texture2D::GetWidth() const
	{
		return width;
	}

	void Texture2D::SetData(const Color4* data, const int width, const int height)
	{
		this->width = width;
		this->height = height;
		char* bindData = new char[width * height * 4];
		
		int i = 0;
		int j = 0;
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				Color4 c (data[i++]);
				bindData[j++] = c.R;
				bindData[j++] = c.G;
				bindData[j++] = c.B;
				bindData[j++] = c.A;
			}
		}

		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(
			GL_TEXTURE_2D,
			0, 
			GL_RGBA, 
			width,
			height, 
			0, 
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			bindData);

		delete [] bindData;
	}
};