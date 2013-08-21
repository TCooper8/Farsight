#pragma once

#include "../Graphics/Texture2D.h"

namespace Farsight
{
	class ContentManager sealed
	{
	private:
		char* rootDirectory;
		static const char* directorySeperator;

	public:
		ContentManager();

		template<typename T>
		T* Load(const char* filename);

		const char* GetRootDirectory() const;
		void SetRootDirectory(const char* rootDirectory);

	private:
		ContentManager(const ContentManager& contentManager);
	};
};