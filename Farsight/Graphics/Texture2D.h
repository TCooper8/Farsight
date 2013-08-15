#pragma once

#include "../Framework/Color4.h"
#include "../FarSystem.h"

namespace Farsight
{
	// Represents a 2D grid of texels.
	class Texture2D
	{
		// Represents the id of this texture, assigned by the graphics device.
		uint id;
		// Represents the surface format of this texture.
		uint format;
		// Represents the height of this texture, in pixels.
		int height;
		// Represents the width of this texture, in pixels.
		int width;

	public:
		/* Creates an uninitialized Texture2D resource.
			Remark : Use ContentManager.Load to initialize this resource. */
		Texture2D();
		// Creates an initialized Texture2D resource from an existing texture id.
		Texture2D(const uint id);
		// Creates an initialized Texture2D resource from an existing Texture2D.
		Texture2D(const Texture2D& texture);

		// Gets the current resource id, assigned by the graphics device.
		uint GetId() const;
		// Gets the current surface format of this resource.
		uint GetFormat() const;
		// Gets the height of this texture, in pixels.
		int GetHeight() const;
		// Gets the width of this texture, in pixels.
		int GetWidth() const;
		// Sets data to the texture.
		void SetData(const Color4* data, const int width, const int height);
	};
};