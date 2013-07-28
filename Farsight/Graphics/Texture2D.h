#pragma once

#include "../Framework/Color4.h"
#include "../FarSystem.h"

namespace Farsight
{
	class Texture2D
	{
		uint id;
		uint format;
		int height;
		int width;

	public:
		Texture2D();

		uint GetId() const;
		uint GetFormat() const;
		int GetHeight() const;
		int GetWidth() const;

		void SetData(const Color4* data, const int width, const int height);

	private:
		static uint IndexCounter;
	};
};