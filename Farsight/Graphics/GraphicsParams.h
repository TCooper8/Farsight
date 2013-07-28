#pragma once

namespace Farsight
{
	class GraphicsParams
	{
	public:
		int BackBufferWidth;
		int BackBufferHeight;

		inline GraphicsParams()
			: BackBufferWidth(512), BackBufferHeight(512)
		{ }
	};
};