#include "Engine.hxx"
#include <memory>

int main(int argc, char* argv[])
{
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	std::unique_ptr<Game> game = std::make_unique<Game>();
	game->init(engine->getRenderer());
	engine->setGame(game.get());
	engine->start();

	return 0;
}