#pragma once

#include "../Framework.h"
#include "MouseState.h"

namespace Farsight
{
	class MouseState
	{
	private:
		bool leftButtonState;
		bool rightButtonState;
		Vector3 position;

	public:
		MouseState();
		MouseState(const MouseState& state);
		MouseState(bool leftState, bool rightState, const Vector3& position);

		bool IsLeftDown() const;
		bool IsRightDown() const;
		Vector3 GetPosition() const;

		void operator=(const MouseState& value);
		bool operator==(const MouseState& value) const;
		bool operator!=(const MouseState& value) const;
	};
};