#pragma once

namespace Farsight
{
	// Defines presentation parameters for a graphics device.
	class GraphicsParams
	{
	public:
		int BackBufferWidth;
		int BackBufferHeight;

		GraphicsParams()
			: BackBufferWidth(512), BackBufferHeight(512)
		{ }
	};
};