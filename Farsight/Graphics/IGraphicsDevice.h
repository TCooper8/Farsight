#pragma once

#include "VertexBuffer.h"
#include "GraphicsParams.h"

namespace Farsight
{
	// Defines an interface for a graphics device.
	class IGraphicsDevice
	{
	public:
		GraphicsParams Params;
		// Inistializes the current graphics device and returns true if successful.
		virtual bool Initialize() = 0;
		// Draws a vertex buffer to the current device's resource buffers.
		virtual void DrawBuffer(const VertexBuffer &buffer) = 0;
		// Clears the current resource buffers.
		virtual void Clear(const Color4& color) = 0;
		// Presents the display with the contents of the next buffer in the swap chain.
		virtual void Present() = 0;
	};
};