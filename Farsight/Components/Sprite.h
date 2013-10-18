#pragma once

#include "../Game.h"

namespace Farsight
{
	class Sprite 
	{
	public:
		Vector3 Position;
		Vector3 Origin;
		Vector3 Scale;
		float Rotation;
		Texture2D Texture;
		Rectangle Bounds;

		Sprite()
			: Position(),
			  Origin(),
			  Scale(1.0),
			  Rotation(0),
			  Texture(),
			  Bounds()
		{ }

		Sprite(const Texture2D& texture, const Vector3& position)
		{
			Texture = texture;
			Position = position;
			Scale = Vector3(1);
			Rotation = 0;

			Bounds = Rectangle(
				(int)position.X,
				(int)position.Y,
				texture.GetWidth(),
				texture.GetHeight());

			Origin = Vector3(
				texture.GetWidth(),
				texture.GetHeight()) / 2.0f;
		}
	};
};