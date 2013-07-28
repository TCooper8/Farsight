#pragma once

namespace Farsight
{
	class Quaternion;

	class Vector3
	{
	public:
		float x;
		float y;
		float z;

		static const Vector3 Backward;
		static const Vector3 Down;
		static const Vector3 Forward;
		static const Vector3 One;
		static const Vector3 UnitX;
		static const Vector3 UnitY;
		static const Vector3 UnitZ;
		static const Vector3 Up;
		static const Vector3 Zero;

		Vector3();
		Vector3(const Vector3 &vector);
		Vector3(const float value);
		Vector3(const float x, const float y);
		Vector3(const float x, const float y, const float z);

		const float Length() const;
		const float LengthSquared() const;
		void Normalize();
		void Sqrt();
		
		static const float Distance(const Vector3 &a, const Vector3 &b);
		static const float DistanceSquared(const Vector3 &a, const Vector3 &b);
		static const float Dot(const Vector3 &a, const Vector3 &b);
		static Vector3 Transform(const Vector3 &vector, const Quaternion &quaternion);

		Vector3 operator*(const Vector3 &v) const;
		void operator*=(const Vector3 &v);
		Vector3 operator+(const Vector3 &v) const;
		void operator+=(const Vector3 &v);
		Vector3 operator-() const;
		Vector3 operator-(const Vector3 &v) const;
		void operator-=(const Vector3 &v);
		Vector3 operator/(const Vector3 &v) const;
		void operator/=(const Vector3 &v);
		Vector3 &operator=(const Vector3 &v);
	};
};