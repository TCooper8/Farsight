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
	protected:
		bool isRunning;
		ContentManager* content;
		IGraphicsDevice* graphicsDevice;

	public:
		struct Window
		{
			static int Width, Height;
		};

		int targetElapsedTime;

		Game();
		~Game();
		
		virtual void Dispose();
		// Exits the game.
		void Exit();
		// Called after the Game and GraphicsDevice are created, but before LoadContent.
		virtual bool Initialize();
		/* Call this method to initialize the game, begin running the game loop,
		and start processing events for the game. */
		void Run();
		// Updates the game's clock and calls Update and Draw.
		virtual void Tick();

	protected:
		// Called when graphics resources need to be loaded.
		virtual bool LoadContent();
		virtual void Draw(const TimeSpan &timeSpan);
		virtual void Update(const TimeSpan &timeSpan);
	};
};