#pragma once

#include "../Graphics/Texture2D.h"

namespace Farsight
{
	class ContentManager
	{
	public:
		template<typename T>
		static T* Load(const char* filename);

	private:
		static Texture2D* LoadFar(const char* filename);
		static Texture2D* LoadTGA(const char* filename);
	};
};