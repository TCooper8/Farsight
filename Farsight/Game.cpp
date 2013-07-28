#include "Game.h"

#if defined(WIN32)
#include <glut.h>
#elif defined(UNIX)
#include <GL/glut.h>
#endif

namespace Farsight
{
	Game* Game::activeGame = nullptr;

	int Game::Window::Width = 512;
	int Game::Window::Height = 512;

	Game::Game()
		: graphicsDevice(nullptr), 
		  content(nullptr),
		  targetElapsedTime(16)
	{ }

	bool Game::Initialize(int argc, char** argv)
	{
		activeGame = this;

		graphicsDevice = new glGraphicsDevice();
		graphicsDevice->Initialize(argc, argv);

		glutDisplayFunc(DisplayCallback);
		glutReshapeFunc(ReshapeCallback);
		glutTimerFunc(targetElapsedTime, TimerCallback, 1);

		Keyboard::BindToGlut();

		glClearColor(1, 1, 1, 1);

		return LoadContent();
	}

	bool Game::LoadContent()
	{
		return true;
	}

	void Game::Reshape(const int width, const int height)
	{
		Window::Width = width;
		Window::Height = height;

		const float ratio = width * 1.0f / height;

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glViewport(0, 0, width, height);
		gluOrtho2D(0, width, 0, height);
		glMatrixMode(GL_MODELVIEW);
	}

	void Game::Run()
	{
		glutMainLoop();
	}

	void Game::Tick()
	{
		TimeSpan gameTime (0, targetElapsedTime);

		Update(gameTime);
		Draw(gameTime);
	}

	void Game::Update(const TimeSpan &timeSpan)
	{
	}

	void Game::Draw(const TimeSpan &timeSpan)
	{
		glutSwapBuffers();
	}

	void Game::DisplayCallback(void)
	{
		activeGame->Tick();
	}

	void Game::ReshapeCallback(const int width, const int height)
	{
		activeGame->Reshape(width, height);
	}

	void Game::TimerCallback(int elapsedTime)
	{
		glutPostRedisplay();
		glutTimerFunc(activeGame->targetElapsedTime, TimerCallback, 1);
	}
};