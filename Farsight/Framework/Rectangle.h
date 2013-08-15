#pragma

namespace Farsight
{
	// Defines a rectangle.
	class Rectangle
	{
	public:
		int Height;
		int Width;
		int X;
		int Y;

		// Represents a Rectangle with all of its values set to zero.
		static Rectangle Empty;

		// Initializes a new instance of an empty rectangle.
		Rectangle();
		// Initializes a new instance of Rectangle.
		Rectangle(int x, int y, int width, int height);
		// Initializes a new copied instance of Rectangle.
		Rectangle(const Rectangle& rect);

		int GetBottom() const;
		bool GetIsEmpty() const;
		int GetLeft() const;
		int GetRight() const;
		int GetTop() const;

		__declspec ( property ( get = GetBottom ) ) 
			// Gets the y-coordinate of the bottom of the rectangle.
			int Bottom;
		__declspec ( property ( get = GetIsEmpty ) )
			// Gets a value that indicates whether the rectangle is empty.
			bool IsEmpty;
		__declspec ( property ( get = GetLeft ) )
			// Gets the x-coordinate of the left side of the rectangle.
			int Left;
		__declspec ( property ( get = GetRight ) )
			// Gets the x-coordinate of the right side of the rectangle.
			int Right;
		__declspec ( property ( get = GetTop ) )
			// Gets the y-coordinate of the top of the rectangle.
			int Top;

		bool operator==(const Rectangle& rect);
		bool operator!=(const Rectangle& rect);
	};
};