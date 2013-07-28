#include <iostream>
#include <glut.h>
#include "Camera.h"

namespace Farsight
{
	std::ostream &operator<<(std::ostream &stream, const Vector3 &v)
	{
		stream << "<" << v.x << ", " << v.y << ", " << v.z << ">";

		return stream;
	}

	Camera::Camera(const Vector3 &position, const Vector3 &target, const Vector3 &upDirection)
		: Position(position), Target(target), UpDirection(upDirection)
	{ 
		Speed = 1;
		RotationSpeed = 1;
		FieldOfView = 45.0f;
		NearPlane = 0.1f;
		FarPlane = 100.0f;
	}

	void Camera::AddForce(const Vector3 &force)
	{
		Vector3 rotatedVector = Vector3::Transform(force, Rotation);
		Position += rotatedVector * Speed;

		fprintf(stdout, "<%f, %f, %f>", rotatedVector.x, rotatedVector.y, rotatedVector.z);
		//PushView();
	}

	void Camera::PushPerspective(const float fieldOfView, const int viewportWidth, const int viewportHeight) const
	{
		float viewRatio;
		if (viewportHeight == 0)
		{
			viewRatio = viewportWidth;
		}
		else
		{
			viewRatio = viewportWidth * 1.0f / viewportHeight;
		}

		gluPerspective(fieldOfView, viewRatio, NearPlane, FarPlane);
		glMatrixMode(GL_MODELVIEW);
	}

	void Camera::PushView() const
	{
		glLoadIdentity();
		gluLookAt(
			Position.x, Position.y, Position.z,
			Target.x, Target.y, Target.z,
			UpDirection.x, UpDirection.y, UpDirection.z);
	}
};
