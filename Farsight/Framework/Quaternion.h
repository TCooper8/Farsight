#pragma once

#include "Vector3.h"

namespace Farsight
{
	class Quaternion
	{
	public:
		float X;
		float Y;
		float Z;
		float W;

		static const Quaternion Identity;

		Quaternion();
		Quaternion(const Vector3 &vector, const float w);
		Quaternion(const float x, const float y, const float z, const float w);
		Quaternion(const Quaternion &quaternion);

		static Quaternion Inverse(const Quaternion &quaternion);

		Quaternion operator*(const Vector3 &vector) const;
		Quaternion operator*(const Quaternion &quaternion) const;
		void operator=(const Quaternion &quaternion);
	};
};