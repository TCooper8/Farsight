#pragma once

namespace Farsight
{
	class Quaternion;

	// Defines a vector with three components.
	class Vector3
	{
	public:
		// Represents the x-component of the vector.
		float X;
		// Represents the y-component of the vector.
		float Y;
		// Represents the z-component of the vector.
		float Z;

		// Represents a unit Vector3 designating the backward in a right-handed coordinate system <0, 0, 1>.
		static const Vector3 Backward;
		// Represents a unit Vector3 designating down <0, -1, 0>.
		static const Vector3 Down;
		// Represents a unit Vector3 designating forward in a right-handed coordinate system <0, 0, -1>.
		static const Vector3 Forward;
		// Represents a unit Vector3 designating left <-1, 0, 0>.
		static const Vector3 Left;
		// Represents a unit Vector3 <1, 1, 1>.
		static const Vector3 One;
		// Represents a unit Vector3 <1, 0, 0>.
		static const Vector3 UnitX;
		// Represents a unit Vector3 <0, 1, 0>.
		static const Vector3 UnitY;
		// Represents a unit Vector3 <0, 0, 1>.
		static const Vector3 UnitZ;
		// Represents a unit Vector3 designating up <0, 1, 0>.
		static const Vector3 Up;
		// Represents a unit Vector3 <0, 0, 0>.
		static const Vector3 Zero;

		// Initializes a new instance of Vector3 as <0, 0, 0>.
		Vector3();
		// Initializes a new copied instance of Vector3.
		Vector3(const Vector3 &vector);
		// Initializes a new instance of Vector3 as <value, value, value>.
		Vector3(const float value);
		// Initializes a new instance of Vector3 as <x, y, 0>.
		Vector3(const float x, const float y);
		// Initializes a new instance of Vector3 as <x, y, z>.
		Vector3(const float x, const float y, const float z);

		// Calculates the length of the vector.
		const float Length() const;
		// Calculates the length of the vector squared.
		const float LengthSquared() const;
		// Turns the current vector into a unit vector with the length of one pointing in the same direction.
		void Normalize();
		// Performs a square root function on all of the vectors components.
		void Sqrt();
		
		// Calculates the distance between two vectors.
		static const float Distance(const Vector3 &a, const Vector3 &b);
		// Calculates the distance between two vectors squared.
		static const float DistanceSquared(const Vector3 &a, const Vector3 &b);
		// Calculates the dot product of two vectors.
		static const float Dot(const Vector3 &a, const Vector3 &b);
		static Vector3 Normalize(const Vector3& value);
		// Transforms a Vector3 by a specified Quaternion rotation.
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