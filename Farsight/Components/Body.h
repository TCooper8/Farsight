#pragma once

#include "Sprite.h"

namespace Farsight
{
	class Body : public Sprite
	{
		typedef Sprite base;

	public:
		Vector3 Velocity;
		float Mass;

		Body()
			: base()
		{ }

		Body(const Texture2D& texture, const Vector3& position)
			: base(texture, position)
		{ }
	};
};