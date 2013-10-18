#pragma once

#include "IGraphicsDevice.h"
#include "Vertex.h"
#include "Texture2D.h"
#include "../Framework.h"

namespace Farsight
{
	/* Defines a sprite batch that enables a group of sprites to be drawn using the same settings.
		Remark : Use a sprite batch to draw a 2D bitmap directly to the screen. */
	class SpriteBatch
	{
	protected:
		IGraphicsDevice* graphicsDevice;

	public:
		// Initializes a new instance of SpriteBatch.
		SpriteBatch(IGraphicsDevice& graphicsDevice);

		// Begins a sprite batch operation.
		void Begin();
		// Adds a texture to the batch to be rendered.
		void Draw(const Texture2D &texture);
		// Adds a texture to the batch to be rendered.
		void Draw(const Texture2D &texture, const Vector3 &position);
		// Adds a texture to the batch to be rendered.
		void Draw(const Texture2D& texture, const Rectangle& source);
		// Adds a texture to the batch to be rendered.
		void Draw(const Texture2D &texture, const Rectangle& source, const Vector3 &position, const Vector3 &origin, const Vector3 &scale, const float rotation);
		// Flushes the batch and restores the graphics device state to how it was before Begin was called.
		void End();

	private:
		SpriteBatch();
		SpriteBatch(const SpriteBatch& spriteBatch);
	};
};