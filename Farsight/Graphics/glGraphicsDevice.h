#pragma once

#include "IGraphicsDevice.h"
#include "GraphicsParams.h"	

namespace Farsight
{
	class glGraphicsDevice : public IGraphicsDevice
	{
	public:
		GraphicsParams Params;

		glGraphicsDevice();

		virtual bool Initialize(int argc, char** argv) override;
		virtual void DrawBuffer(const VertexBuffer &buffer) override;
		virtual void Clear() override;
	};
};