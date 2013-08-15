#pragma once

#include "../FarSystem.h"

namespace Farsight
{
	class KeyboardState
	{
		uchar keys[256];

	public:
		KeyboardState();
		KeyboardState(const uchar keys[256]);
		KeyboardState(const KeyboardState &state);

		bool IsKeyDown(const uchar key) const;
		bool IsKeyUp(const uchar key) const;

		void operator=(const KeyboardState &state);
		bool operator==(const KeyboardState& state) const;
		bool operator!=(const KeyboardState& state) const;

	private:
		void SetKeys(const uchar keys[256]);
	};
};