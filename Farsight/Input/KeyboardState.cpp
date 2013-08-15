#include <cstring>
#include <Windows.h>
#include "KeyboardState.h"

namespace Farsight
{
	KeyboardState::KeyboardState()
	{
		memset(keys, 0, sizeof(keys));
	}

	KeyboardState::KeyboardState(const uchar keys[256])
	{
		SetKeys(keys);
	}

	KeyboardState::KeyboardState(const KeyboardState &state)
	{
		SetKeys(state.keys);
	}

	bool KeyboardState::IsKeyDown(const uchar key) const
	{
		return keys[key] != 0;
	}

	bool KeyboardState::IsKeyUp(const uchar key) const
	{
		return keys[key] == 0;
	}

	void KeyboardState::SetKeys(const uchar keys[256])
	{
		memcpy(this->keys, keys, sizeof(this->keys));
	}

	void KeyboardState::operator=(const KeyboardState &state)
	{
		SetKeys(state.keys);
	}

	bool KeyboardState::operator==(const KeyboardState& state) const
	{
		return memcmp(this->keys, state.keys, sizeof(this->keys)) == 0;
	}

	bool KeyboardState::operator!=(const KeyboardState& state) const
	{
		return !(*this == state);
	}
};