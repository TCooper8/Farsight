#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#if defined(WIN32)
#include <glut.h>
#elif defined(UNIX)
#include <GL/glut.h>
#endif

#include "ContentManager.h"
#include "../Framework/Face.h"
#include "../Graphics/VertexBuffer.h"
#include "../Graphics/Model.h"
#include "../ExternalDependencies/Soil/SOIL.h"

namespace Farsight
{
	ContentManager::ContentManager()
		: rootDirectory("")
	{ }

	ContentManager::ContentManager(const ContentManager& ContentManager)
	{ }

	#pragma region ContentManager::Load definitions

	template<>
	VertexBuffer* ContentManager::Load(const char* filename)
	{
		std::string filepath = rootDirectory;
		filepath.append(filename);

		std::string key;
		std::ifstream fin (filepath.c_str(), std::ios::in | std::ios::binary);

		std::vector<Vector3> vertices;

		if (fin.is_open())
		{
			while (fin.good())
			{
				fin >> key;

				if (key == "v")
				{
					float x, y, z;
					fin >> x >> y >> z >> std::ws;

					vertices.push_back(Vector3(x, y, z));
				}
			}

			VertexBuffer* vb = new VertexBuffer();
			const int count = vertices.size();
			Vector3* data = new Vector3[count];

			std::copy(vertices.begin(), vertices.end(), data);
			vb->SetData(data, count, GL_POLYGON);

			delete [] data;

			return vb;
		}
		else
		{
			fprintf(stderr, "File %s not found.", filename);
		}

		return nullptr;
	}

	template<>
	Model* ContentManager::Load(const char* filename)
	{
		std::string filepath = rootDirectory;
		filepath.append(filename);

		std::vector<std::string> coords;
		std::vector<Vector3> vertices;
		std::vector<Face> faces;
		std::vector<Vector3> normals;

		std::string key;
		std::ifstream fin (filepath.c_str());

		if (fin.is_open())
		{
			while (fin.good())
			{
				fin >> key;

				if (key[0] == '#')
					continue;
				if (key[0] == 'v' && key[1] == ' ')
				{
					float x, y, z;
					fin >> x >> y >> z >> std::ws;

				}
			}
		}

		return nullptr;
	}


	// This function will determine which subfunction to call
	// based on what file extention is passed in to filename.
	template<>
	Texture2D* ContentManager::Load(const char* filename)
	{
		std::string filepath = rootDirectory;
		filepath.append(filename);

		uint id = SOIL_load_OGL_texture(
			filepath.c_str(), 
			SOIL_LOAD_AUTO, 
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_POWER_OF_TWO |
			SOIL_FLAG_MIPMAPS |
			SOIL_FLAG_DDS_LOAD_DIRECT);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, id);

		#if _DEBUG
		FarSystem::Report("SOIL loading texture : ");
		FarSystem::Report(filepath.c_str());
		FarSystem::Report(SOIL_last_result());
		#endif

		if (id <= 0)
		{
			#if _DEBUG
			FarSystem::ReportError(0, "Texture loading failed.");
			FarSystem::ReportError(0, SOIL_last_result());
			#endif

			return nullptr;
		}

		#if _DEBUG
		FarSystem::Report("Texture loading success.");
		#endif

		Texture2D* texture = new Texture2D(id);

		return texture;
	}

	#pragma endregion

	const char* ContentManager::GetRootDirectory() const
	{
		return rootDirectory;
	}

	void ContentManager::SetRootDirectory(const char* rootDirectory)
	{
		if (strlen(this->rootDirectory) != 0)
			delete [] this->rootDirectory;

		const int length = strlen(rootDirectory);
		this->rootDirectory = new char[length];

		strcpy(this->rootDirectory, rootDirectory);
	}
};