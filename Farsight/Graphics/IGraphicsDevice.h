#pragma once

#include "VertexBuffer.h"

namespace Farsight
{
	class IGraphicsDevice
	{
	public:
		virtual bool Initialize(int argc, char** argv) = 0;
		virtual void DrawBuffer(const VertexBuffer &buffer) = 0;
		virtual void Clear(const Color4 &color) = 0;
	};
};