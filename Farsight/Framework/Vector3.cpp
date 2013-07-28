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
		: x(0), y(0), z(0)
	{ }

	Vector3::Vector3(const Vector3 &vector)
		: x(vector.x), y(vector.y), z(vector.z)
	{ }

	Vector3::Vector3(const float value)
		: x(value), y(value), z(value)
	{ }

	Vector3::Vector3(const float x, const float y)
		: x(x), y(y), z(0)
	{ }

	Vector3::Vector3(const float x, const float y, const float z)
		: x(x), y(y), z(z)
	{ }

	const float Vector3::LengthSquared() const
	{
		return powf(x, 2) + powf(y, 2) + powf(z, 2);
	}

	const float Vector3::Length() const
	{
		return sqrtf(this->LengthSquared());
	}

	void Vector3::Normalize()
	{
		const float length = this->Length();

		x /= length;
		y /= length;
		z /= length;
	}

	void Vector3::Sqrt()
	{
		x = sqrtf(x);
		y = sqrtf(y);
		z = sqrtf(z);
	}

	const float Vector3::Distance(const Vector3 &a, const Vector3 &b)
	{
		return sqrtf(Vector3::DistanceSquared(a, b));
	}

	const float Vector3::DistanceSquared(const Vector3 &a, const Vector3 &b)
	{
		return powf(b.x - a.x, 2) + powf(b.y - a.y, 2) + powf(b.z - a.z, 2);
	}

	const float Vector3::Dot(const Vector3 &a, const Vector3 &b)
	{
		return a.x * b.x + a.y + b.y + a.z + b.z;
	}

	Vector3 Vector3::Transform(const Vector3 &vector, const Quaternion &quaternion)
	{
		Quaternion tQ = (quaternion * vector) * Quaternion::Inverse(quaternion);

		//fprintf(stdout, "<%f, %f, %f, %f> \n", tQ.X, tQ.Y, tQ.Z, tQ.W);

		return Vector3(tQ.X, tQ.Y, tQ.Z);
	}

	Vector3 Vector3::operator*(const Vector3 &v) const
	{
		return Vector3(x * v.x, y * v.y, z * v.z);
	}

	void Vector3::operator*=(const Vector3 &v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
	}

	Vector3 Vector3::operator+(const Vector3 &v) const
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	void Vector3::operator+=(const Vector3 &v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

	Vector3 Vector3::operator-() const
	{
		return Vector3(-x, -y, -z);
	}

	Vector3 Vector3::operator-(const Vector3 &v) const
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	void Vector3::operator-=(const Vector3 &v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	Vector3 Vector3::operator/(const Vector3 &v) const
	{
		return Vector3(x / v.x, y / v.y, z / v.z);
	}

	void Vector3::operator/=(const Vector3 &v) 
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
	}

	Vector3 &Vector3::operator=(const Vector3 &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}
};