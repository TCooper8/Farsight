#include <iostream>
#include <glut.h>
#include "Camera.h"

namespace Farsight
{
	Camera::Camera(const Vector3 &position, const Vector3 &target, const Vector3 &upDirection)
		: Position(position), Target(target), UpDirection(upDirection)
	{ 
		Speed = 1;
		RotationSpeed = 1;
		FieldOfView = 45.0f;
		NearPlane = 0.1f;
		FarPlane = 100.0f;
	}

	Camera::Camera(const Camera &camera)
		: Position(camera.Position), Target(camera.Target), UpDirection(camera.UpDirection),
		  Speed(camera.Speed), RotationSpeed(camera.RotationSpeed),
		  FieldOfView(camera.FieldOfView), NearPlane(camera.NearPlane),
		  FarPlane(camera.FarPlane)
	{ }

	void Camera::AddForce(const Vector3 &force)
	{
		Vector3 rotatedVector = Vector3::Transform(force, Rotation);
		Position += rotatedVector * Speed;
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
			Position.X, Position.Y, Position.Z,
			Target.X, Target.Y, Target.Z,
			UpDirection.X, UpDirection.Y, UpDirection.Z);
	}
};
