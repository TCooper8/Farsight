#pragma once

#include "FarSystem.h"
#include "Framework.h"
#include "Graphics.h"
#include "Content.h"
#include "Input.h"

namespace Farsight
{
	class Game
	{
	private:
		static Game* activeGame;

	protected:
		ContentManager* content;
		IGraphicsDevice* graphicsDevice;

	public:
		struct Window
		{
			static int Width, Height;
		};

		int targetElapsedTime;

		Game();

		virtual bool Initialize(int argc, char** argv);
		virtual bool LoadContent();
		virtual void Reshape(const int width, const int height);
		void Run();
		virtual void Tick();
		virtual void Update(const TimeSpan &timeSpan);
		virtual void Draw(const TimeSpan &timeSpan);

	private:
		static void DisplayCallback(void);
		static void ReshapeCallback(const int width, const int height);
		static void TimerCallback(int elapsedTime);
	};
};