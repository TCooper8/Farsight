#pragma once

#include "Vertex.h"
#include "Texture2D.h"

namespace Farsight
{
	/* Defines a sprite batch that enables a group of sprites to be drawn using the same settings.
		Remark : Use a sprite batch to draw a 2D bitmap directly to the screen. */
	class SpriteBatch
	{
	public:
		// Initializes a new instance of SpriteBatch.
		SpriteBatch();

		// Begins a sprite batch operation.
		void Begin();
		// Adds a texture to the batch to be rendered.
		void Draw(const Texture2D &texture);
		// Adds a texture to the batch to be rendered.
		void Draw(const Texture2D &texture, const Vector3 &position);
		// Adds a texture to the batch to be rendered.
		void Draw(const Texture2D &texture, const Vector3 &position, const Vector3 &origin, const Vector3 &scale, const float rotation);
		// Flushes the batch and restores the graphics device state to how it was before Begin was called.
		void End();
	};
};