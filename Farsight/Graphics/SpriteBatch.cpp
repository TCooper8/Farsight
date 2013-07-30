#include "SpriteBatch.h"

#if defined(WIN32)
#include <glut.h>
#elif defined(UNIX)
#include <GL/glut.h>
#endif

namespace Farsight
{
	SpriteBatch::SpriteBatch()
	{ }

	void SpriteBatch::Begin()
	{
		const int width = glutGet(GLUT_WINDOW_WIDTH);
		const int height = glutGet(GLUT_WINDOW_HEIGHT);

		glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glViewport(0, 0, width, height);
		gluOrtho2D(0, width, 0, height);
		glScalef(1, -1, 1);

		glTranslatef(0, -height, 0);
		glMatrixMode(GL_MODELVIEW);
	}

	void SpriteBatch::Draw(const Texture2D &texture)
	{
		Draw(texture, Vector3::Zero);
	}

	void SpriteBatch::Draw(const Texture2D &texture, const Vector3 &position)
	{
		Draw(texture, position, Vector3::Zero, Vector3::One, 0);
	}

	void SpriteBatch::Draw(const Texture2D &texture, const Vector3 &position, const Vector3 &origin, const Vector3 &scale, const float rotation)
	{
		if (&texture == nullptr)
			return;

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture.GetId());

		glPushMatrix();
		glTranslatef(position.X, position.Y, position.Z);
		glScalef(scale.X, scale.Y, 1);
		glRotatef(rotation, 0, 0, 1);
		glTranslatef(-origin.X, -origin.Y, -origin.Z);

		glBegin(GL_QUADS);
		
		glNormal3d(0, 0, 1);
		glTexCoord2f(0, 0); glVertex2i(0, 0);
		glTexCoord2f(1, 0); glVertex2i(texture.GetWidth(), 0);
		glTexCoord2f(1, 1); glVertex2i(texture.GetWidth(), texture.GetHeight());
		glTexCoord2f(0, 1); glVertex2i(0, texture.GetHeight());

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	void SpriteBatch::End()
	{
		glPopMatrix();
	}
};