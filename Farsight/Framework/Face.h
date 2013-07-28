#pragma once

#include "../FarSystem.h"

namespace Farsight
{
	class Face
	{
	public:
		uint Count;
		bool Four;
		uint Faces[4];

		Face(const uint count, const uint faceA, const uint faceB, const uint faceC)
			: Count(count), Four(false)
		{
			Faces[0] = faceA;
			Faces[1] = faceB;
			Faces[2] = faceC;
		}
		
		Face(const uint count, const uint faceA, const uint faceB, const uint faceC, const uint faceD)
			: Count(count), Four(false)
		{
			Faces[0] = faceA;
			Faces[1] = faceB;
			Faces[2] = faceC;
			Faces[3] = faceD;
		}
	};
};