#pragma once

namespace Farsight
{
	class GameWindow sealed
	{
		bool allowUserResizing;
		int handle;
		char* title;

	protected:
		void OnClientSizeChanged();

	public:
		GameWindow();

		bool GetAllowUserResizing() const;
		int GetHandle() const;
		const char* GetTitle() const;

		void SetHandle(int handle);
		void SetTitle(const char* title);
	};
};