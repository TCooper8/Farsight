#include "Quaternion.h"

namespace Farsight
{
	const Quaternion Quaternion::Identity (0, 0, 0, 1);

	Quaternion::Quaternion()
		: X(0), Y(0), Z(0), W(0)
	{ }

	Quaternion::Quaternion(const Vector3 &vector, const float w)
		: X(vector.X), Y(vector.Y), Z(vector.Z), W(w)
	{ }

	Quaternion::Quaternion(const float x, const float y, const float z, const float w)
		: X(x), Y(y), Z(z), W(w)
	{ }

	Quaternion::Quaternion(const Quaternion &quaternion)
		: X(quaternion.X), Y(quaternion.Y), Z(quaternion.Z), W(quaternion.W)
	{ }

	Quaternion Quaternion::Inverse(const Quaternion &q)
	{
		return Quaternion(-q.X, -q.Y, -q.Z, q.W);
	}

	Quaternion Quaternion::operator*(const Vector3 &v) const
	{
		return Quaternion(
			W * v.X + Z * v.Y - Y * v.Z, 
			W * v.Y + X * v.Z - Z * v.X,
			W * v.Z + Y * v.X - X * v.Y,
			-(X * v.X + Y * v.Y + Z * v.Z));
	}

	Quaternion Quaternion::operator*(const Quaternion &q) const
	{
		return Quaternion(
			W * q.X + X * q.W + Y * q.Z - Z * q.Y,
			W * q.Y + Y * q.W + Z * q.X - X * q.Z,
			W * q.Z + Z * q.W + X * q.Y - Y * q.X,
			W * q.W - X * q.X - Y * q.Y - Z * q.Z);
	}

	void Quaternion::operator=(const Quaternion &quaternion)
	{
		X = quaternion.X;
		Y = quaternion.Y;
		Z = quaternion.Z;
		W = quaternion.W;
	}
};