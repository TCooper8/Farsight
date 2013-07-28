#pragma once

#include "../Framework/Vector3.h"
#include "../Framework/Quaternion.h"

namespace Farsight
{
	class Camera
	{
	public:
		Vector3 Position;
		Vector3 Target;
		Vector3 UpDirection;

		float FieldOfView;
		float NearPlane;
		float FarPlane;

		Quaternion Rotation;
		float Speed;
		float RotationSpeed;

		Camera(const Vector3 &position, const Vector3 &target, const Vector3 &upDirect);

		void AddForce(const Vector3 &force);
		void PushPerspective(const float fieldOfView, const int viewportWidth, const int viewportHeight) const;
		void PushView() const;

	private:
		Camera(const Camera &camera);
	};
};