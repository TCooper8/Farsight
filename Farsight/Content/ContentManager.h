#pragma once

#include <unordered_map>
#include "../Graphics/Texture2D.h"

namespace Farsight
{
	class ContentManager sealed
	{
	public:
		typedef std::unordered_map<const char*, int> TextureDictionary;

	private:
		char* rootDirectory;
		static const char* directorySeperator;
		TextureDictionary TextureTable;

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