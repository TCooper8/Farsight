#pragma once

#include "VertexBuffer.h"

namespace Farsight
{
	// Defines an interface for a graphics device.
	class IGraphicsDevice
	{
	public:
		// Inistializes the current graphics device and returns true if successful.
		virtual bool Initialize(int argc, char** argv) = 0;
		// Draws a vertex buffer to the current device's resource buffers.
		virtual void DrawBuffer(const VertexBuffer &buffer) = 0;
		// Clears the current resource buffers.
		virtual void Clear() = 0;
	};
};