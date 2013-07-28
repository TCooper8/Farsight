#pragma once

#include "Vertex.h"
#include "Texture2D.h"

namespace Farsight
{
	class SpriteBatch
	{
	public:
		SpriteBatch();

		void Begin(const int width, const int height);
		void Draw(const Texture2D &texture);
		void Draw(const Texture2D &texture, const Vector3 &position);
		void Draw(const Texture2D &texture, const Vector3 &position, const Vector3 &origin, const Vector3 &scale, const float rotation);
		void End();
	};
};