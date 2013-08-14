#include "Game.h"

using namespace Farsight;

class GameManager : public Game
{
	Texture2D* texture;

public:
	GameManager()
	{ }

	virtual bool LoadContent() override
	{ 
		texture = ContentManager::Load<Texture2D>("liveTile.png");

		return Game::LoadContent();
	}
};

int main(int argc, char** argv)
{
	Game* game = new GameManager();
	game->Initialize(argc, argv);
	game->Run();

	return 0;
}