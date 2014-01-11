#include <iostream>
#include <math.h>
#include "Vector3.h"
#include "Quaternion.h"

namespace Farsight
{
	const Vector3 Vector3::Backward (0, 0, 1);
	const Vector3 Vector3::Down	(0, -1, 0);
	const Vector3 Vector3::Forward (0, 0, -1);
	const Vector3 Vector3::One (1, 1, 1);
	const Vector3 Vector3::UnitX(1, 0, 0);
	const Vector3 Vector3::UnitY(0, 1, 0);
	const Vector3 Vector3::UnitZ(0, 0, 1);
	const Vector3 Vector3::Up (0, 1, 0);
	const Vector3 Vector3::Zero(0, 0, 0);

	Vector3::Vector3()
		: X(0), Y(0), Z(0)
	{ }

	Vector3::Vector3(const Vector3 &vector)
		: X(vector.X), Y(vector.Y), Z(vector.Z)
	{ }

	Vector3::Vector3(const float value)
		: X(value), Y(value), Z(value)
	{ }

	Vector3::Vector3(const float x, const float y)
		: X(x), Y(y), Z(0)
	{ }

	Vector3::Vector3(const float x, const float y, const float z)
		: X(x), Y(y), Z(z)
	{ }

	const float Vector3::LengthSquared() const
	{
		return powf(X, 2) + powf(Y, 2) + powf(Z, 2);
	}

	const float Vector3::Length() const
	{
		return sqrtf(this->LengthSquared());
	}

	void Vector3::Normalize()
	{
		const float length = this->Length();

		X /= length;
		Y /= length;
		Z /= length;
	}

	void Vector3::Sqrt()
	{
		X = sqrtf(X);
		Y = sqrtf(Y);
		Z = sqrtf(Z);
	}

	const float Vector3::Distance(const Vector3 &a, const Vector3 &b)
	{
		return sqrtf(Vector3::DistanceSquared(a, b));
	}

	const float Vector3::DistanceSquared(const Vector3 &a, const Vector3 &b)
	{
		return powf(b.X - a.X, 2) + powf(b.Y - a.Y, 2) + powf(b.Z - a.Z, 2);
	}

	const float Vector3::Dot(const Vector3 &a, const Vector3 &b)
	{
		return a.X * b.X + a.Y + b.Y + a.Z + b.Z;
	}

	Vector3 Vector3::Normalize(const Vector3& v)
	{
		const float length = v.Length();
		return v / length;
	}

	Vector3 Vector3::Transform(const Vector3 &vector, const Quaternion &quaternion)
	{
		Quaternion tQ = (quaternion * vector) * Quaternion::Inverse(quaternion);

		//fprintf(stdout, "<%f, %f, %f, %f> \n", tQ.X, tQ.Y, tQ.Z, tQ.W);

		return Vector3(tQ.X, tQ.Y, tQ.Z);
	}

	Vector3 Vector3::operator*(const Vector3 &v) const
	{
		return Vector3(X * v.X, Y * v.Y, Z * v.Z);
	}

	void Vector3::operator*=(const Vector3 &v)
	{
		X *= v.X;
		Y *= v.Y;
		Z *= v.Z;
	}

	Vector3 Vector3::operator+(const Vector3 &v) const
	{
		return Vector3(X + v.X, Y + v.Y, Z + v.Z);
	}

	void Vector3::operator+=(const Vector3 &v)
	{
		X += v.X;
		Y += v.Y;
		Z += v.Z;
	}

	Vector3 Vector3::operator-() const
	{
		return Vector3(-X, -Y, -Z);
	}

	Vector3 Vector3::operator-(const Vector3 &v) const
	{
		return Vector3(X - v.X, Y - v.Y, Z - v.Z);
	}

	void Vector3::operator-=(const Vector3 &v)
	{
		X -= v.X;
		Y -= v.Y;
		Z -= v.Z;
	}

	Vector3 Vector3::operator/(const Vector3 &v) const
	{
		return Vector3(X / v.X, Y / v.Y, Z / v.Z);
	}

	void Vector3::operator/=(const Vector3 &v) 
	{
		X /= v.X;
		Y /= v.Y;
		Z /= v.Z;
	}

	Vector3 &Vector3::operator=(const Vector3 &v)
	{
		X = v.X;
		Y = v.Y;
		Z = v.Z;

		return *this;
	}
};