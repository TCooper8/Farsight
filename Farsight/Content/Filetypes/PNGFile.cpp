#include <iostream>
#include <fstream>
#include <vector>
#include "PNGFile.h"

namespace Farsight
{
	void PNGFile::LoadFromFile(const char* filename)
	{
		std::fstream fin (filename);

		std::vector<Chunk> chunkVector;

		if (fin.is_open())
		{
			// Pull in PNG header data.
			// The header is an 8-byte signature.
			fin.get(Header, sizeof(Header));

			while (fin.good())
			{
				// Pull in chunk data.
				Chunk chunk = {0};
				fin >> chunk.Length;
				fin >> chunk.TypeName;
			
				// There is no data in this chunk if zero.
				if (chunk.Length != 0)
				{
					chunk.Data = new char[chunk.Length];
					fin >> chunk.Data;
				}
				else
					std::cout << "Chunk length was zero!" << std::endl;

				fin >> chunk.CRC;

				std::cout << chunk.TypeName << std::endl;
				std::cout << chunk.CRC << std::endl;
				for (int i = 0; i < chunk.Length; i++)
				{
					std::cout << chunk.Data[i];
				}
				std::cout << std::endl << std::endl;
			}
		}
	}
};