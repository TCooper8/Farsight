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
#include "Filetypes\TGAFile.h"
#include "Filetypes\PNGFile.h"
#include "../Framework/Face.h"
#include "../Graphics/VertexBuffer.h"
#include "../Graphics/Model.h"
#include "../ExternalDependencies/Soil/SOIL.h"

namespace Farsight
{
	#pragma region ContentManager::Load definitions

	template<>
	VertexBuffer* ContentManager::Load(const char* filename)
	{
		std::string key;
		std::ifstream fin (filename, std::ios::in | std::ios::binary);

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
		std::vector<std::string> coords;
		std::vector<Vector3> vertices;
		std::vector<Face> faces;
		std::vector<Vector3> normals;

		std::string key;
		std::ifstream fin (filename);

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
		SOIL_load_OGL_texture(filename, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0);
		#if _DEBUG
		FarSystem::Report("SOIL loading texture : ");
		FarSystem::Report(filename);
		FarSystem::Report(SOIL_last_result());
		#endif



		return nullptr;
	}

	Texture2D* ContentManager::LoadPNG(const char* filename)
	{
		return nullptr;
		/*
		std::stringstream sstream;
		sstream << "Content\\ImageParser.exe " << filename;

		system(sstream.str().c_str());

		sstream = std::stringstream();

		int i = strlen(filename);
		while (filename[i] != '.')
			i--;

		int j = 0;
		while (j < i)
		{
			sstream << filename[j];
			j++;
		}

		sstream << ".far";

		std::cout << sstream.str() << std::endl;

		return LoadFar(sstream.str().c_str());*/
	}

	Texture2D* ContentManager::LoadFar(const char* filename)
	{
		std::fstream fin (filename);

		if (fin.is_open())
		{
			// Pull in .far header.

			int width, height;
			fin >> width >> height;

			Color4* data = new Color4[width * height];

			using namespace std;
			int i = 0;
			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{
					int r, g, b, a;

					fin 
						>> r
						>> g
						>> b
						>> a;

					data[i] = Color4(r, g, b, a);
					i++;
				}
			}

			Texture2D* texture = new Texture2D();
			texture->SetData(data, width, height);
			
			return texture;
		}

		return nullptr;
	}

	Texture2D* ContentManager::LoadTGA(const char* filename)
	{
		std::fstream fin (filename, std::ios::in | std::ios::binary);
		TGAFileHeader header;

		char* data;

		if (fin.is_open())
		{
			// Pull in file header data.
			fin.read((char*)&header, sizeof(TGAFileHeader));

			// Read pixel data.
			const int imageSize = header.width * header.height * header.bpp;
			data = (char*)malloc(imageSize);
			fin.read((char*)data, imageSize);

			int internalFormat = 4;

			Texture2D* texture = new Texture2D();

			delete [] data;
			fin.close();

			return texture;
		}
		fin.close();

		return nullptr;
	}

	#pragma endregion
};