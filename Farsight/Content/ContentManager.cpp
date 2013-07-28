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
#include "../Framework/Face.h"
#include "../Graphics/VertexBuffer.h"
#include "../Graphics/Model.h"

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
		const int len = std::strlen(filename);
		std::stringstream sstream;

		// Find extension beginning.
		int i = 0;
		while (filename[i] != '.')
			i++;
		i++;

		// Stream rest of filename into stringstream.

		while (i < len)
		{
			sstream << (char)filename[i];
			i++;
		}

		// Determine file extension.

		if (sstream.str() == "tga")
		{
			sstream.clear();
			return LoadTGA(filename);
		}

		if (sstream.str() == "far")
		{
			sstream.clear();
			std::cout << "got it!" << std::endl;
			return LoadFar(filename);
		}

		FarSystem::RaiseException("Unrecognized file format");

		return nullptr;
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
					//int i = x + y * width;
					int r, g, b, a;

					fin 
						>> r
						>> g
						>> b
						>> a;

					data[i] = Color4(r, g, b, a);
					i++;
					//cout <<'(' << r << ", " << g << ", " << b << ", " << a << ')' << endl;
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