#include "SpriteBatch.h"
#include <glut.h>

namespace Farsight
{
	SpriteBatch::SpriteBatch()
	{ }

	void SpriteBatch::Begin(const int width, const int height)
	{
		//glPushMatrix();
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, width, 0, height);
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
		glTranslatef(position.x, position.y, position.z);
		glScalef(scale.x, scale.y, 1);
		glRotatef(rotation, 0, 0, 1);
		glTranslatef(-origin.x, -origin.y, -origin.z);

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
		//glPopMatrix();
	}
};