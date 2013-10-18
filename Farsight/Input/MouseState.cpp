#include <windows.h>
#include <memory>
#include "MouseState.h"

namespace Farsight
{
	MouseState::MouseState()
	{ }

	MouseState::MouseState(const MouseState& state)
	{
		*this = state;
	}

	MouseState::MouseState(bool leftState, bool rightState, const Vector3& position)
		: leftButtonState(leftState),
		  rightButtonState(rightState),
		  position(position)
	{ }

	bool MouseState::IsLeftDown() const
	{
		return leftButtonState;
	}

	bool MouseState::IsRightDown() const
	{
		return rightButtonState;
	}

	Vector3 MouseState::GetPosition() const
	{
		return position;
	}

	bool MouseState::operator==(const MouseState& value) const
	{
		return (std::memcmp(this, &value, sizeof(MouseState)) == 0);
	}

	bool MouseState::operator!=(const MouseState& value) const
	{
		return (*this == value);
	}
};