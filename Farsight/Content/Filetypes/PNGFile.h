#pragma once

namespace Farsight
{
	namespace PNGFileChunkNames
	{
		enum CriticalChunks
		{
			IHDR = 0,
			PLTE,
			IDAT,
			IEND
		};

		enum AncillaryChunks
		{
			cHRM = 0,
			qAMA,
			iCPP,
			sBIT,
			sRGB,
			bKGD,
			hIST,
			tRNS,
			pHYs,
			sPLT,
			tIME,
			iTXt,
			tEXt,
			zTXt
		};
	};

	struct PNGFile
	{
	public:
		// Defines a 4 part PNG chunk. 
		struct Chunk
		{
			// Represents the byte-length of the chunk data-part.
			unsigned __int32 Length;
			// Represents the Type/Name of the chunk. See online reference : Chunk naming conventions.
			char TypeName[4];
			// Represents the Cyclic Redundancy code to be calculated on the preceding bytes in the chunk.
			char CRC[4];
			/* Represents the data bytes appropriate to the chunk type, if any.
			This field can be zero in length. */
			char* Data;
		};

		char Header[8];
		Chunk* Chunks;

		void LoadFromFile(const char* filename);
	};
};