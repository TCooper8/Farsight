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
		void End();
	};
};