#pragma once

#include "../Framework/Vector3.h"
#include "../Framework/Quaternion.h"

namespace Farsight
{
	// Defines a camera with a position, target, and up direction.
	class Camera
	{
	public:
		// Represents the position of the camera.
		Vector3 Position;
		// Represents the target of the camera.
		Vector3 Target;
		// Represents the up direction of the camera.
		Vector3 UpDirection;
		// Represents the field of the view of the camera.
		float FieldOfView;
		// Represents the near plane distance of the camera.
		float NearPlane;
		// Represents the far plane distance of the camera.
		float FarPlane;
		// Represents the rotation of the camera.
		Quaternion Rotation;
		// Represents the movement speed of the camera.
		float Speed;
		// Represents the rotation speed of the camera.
		float RotationSpeed;

		// Initializes a new camera with a position, target and up direction.
		Camera(const Vector3 &position, const Vector3 &target, const Vector3 &upDirection);
		// Initializes a new copied instance of a camera.
		Camera(const Camera &camera);

		// Method not implimented properly yet.
		void AddForce(const Vector3 &force);
		// Pushes the current perspective matrix to glut.
		void PushPerspective(const float fieldOfView, const int viewportWidth, const int viewportHeight) const;
		// Pushes the current view matrix to glut.
		void PushView() const;
	};
};