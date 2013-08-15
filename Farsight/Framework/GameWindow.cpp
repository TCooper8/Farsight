#include <cstring>
#include "GameWindow.h"

namespace Farsight
{
	GameWindow::GameWindow()
		: allowUserResizing(false),
		  handle(0),
		  title(nullptr)
	{ }

	bool GameWindow::GetAllowUserResizing() const
	{
		return allowUserResizing;
	}

	int GameWindow::GetHandle() const
	{
		return handle;
	}

	const char* GameWindow::GetTitle() const
	{
		return title; 
	}

	void GameWindow::SetHandle(int handle)
	{
		this->handle = handle;
	}

	void GameWindow::SetTitle(const char* title)
	{
		if (strlen(this->title) != 0)
			delete [] this->title;

		this->title = new char[strlen(title)];
		strcpy(this->title, title);
	}
};