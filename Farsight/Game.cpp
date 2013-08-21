#include <iostream>
#include <Windows.h>
#include "Game.h"

#if defined(WIN32)
#include <gl/GL.h>
#include <gl/GLU.h>
#elif defined(UNIX)
#include <GL/glut.h>
#endif

namespace Farsight
{
	int Game::Window::Width = 512;
	int Game::Window::Height = 512;

	Game::Game()
		: graphicsDevice(nullptr), 
		  content(nullptr),
		  targetElapsedTime(16)
	{
		content = new ContentManager();
	}

	Game::~Game()
	{
		Dispose();
	}

	void Game::Dispose()
	{
		if (content)
			delete content;
		if (graphicsDevice)
			delete graphicsDevice;
	}

	void Game::Exit()
	{
		isRunning = false;
	}

	bool Game::Initialize()
	{
		graphicsDevice = new glGraphicsDevice();
		graphicsDevice->Initialize();

		glClearColor(1, 1, 1, 1);

		return LoadContent();
	}

	void Game::Run()
	{
		MSG msg;

		int totalTime = 0;

		isRunning = true;

		while (isRunning)
		{
			// Check event loop here.
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
					isRunning = false;
				else
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
			else
			{
				TimeSpan timeInitial = FarSystem::GetSystemTime();

				Tick();

				TimeSpan timeFinal = FarSystem::GetSystemTime();
				const int waitTime = targetElapsedTime - (timeFinal - timeInitial).GetMilliseconds();

				if (waitTime > 0)
					Sleep(waitTime);
			}
		}
	}

	void Game::Tick()
	{
		TimeSpan gameTime (0, targetElapsedTime);

		Update(gameTime);
		Draw(gameTime);
	}

	bool Game::LoadContent()
	{
		return true;
	}

	void Game::Update(const TimeSpan &timeSpan)
	{
	}

	void Game::Draw(const TimeSpan &timeSpan)
	{
		graphicsDevice->Present();
	}
};