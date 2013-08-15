#pragma once

#include <Windows.h>
#include "IGraphicsDevice.h"
#include "GraphicsParams.h"	

namespace Farsight
{
	class glGraphicsDevice : public IGraphicsDevice
	{
		HDC hDC;

	public:
		glGraphicsDevice();

		virtual bool Initialize() override;
		virtual void DrawBuffer(const VertexBuffer &buffer) override;
		virtual void Clear(const Color4& color) override;
		virtual void Present() override;
	};
};