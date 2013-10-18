#include "Rectangle.h"

namespace Farsight
{
	const Rectangle Rectangle::Empty (0, 0, 0, 0);

	Rectangle::Rectangle()
		: Height(0),
		  Width(0),
		  X(0),
		  Y(0)
	{ }

	Rectangle::Rectangle(int x, int y, int width, int height)
		: Height(height),
		  Width(width),
		  X(x),
		  Y(y)
	{ }

	Rectangle::Rectangle(const Rectangle& rect)
		: Height(rect.Height),
		  Width(rect.Width),
		  X(rect.X),
		  Y(rect.Y)
	{ }

	int Rectangle::GetBottom() const
	{
		return (Y + Height);
	}

	bool Rectangle::GetIsEmpty() const
	{
		return (Height || Width || X || Y);
	}

	int Rectangle::GetLeft() const
	{
		return X;
	}

	int Rectangle::GetRight() const
	{
		return (X + Width);
	}

	int Rectangle::GetTop() const
	{
		return Y;
	}
};