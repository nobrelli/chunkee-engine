#include "Engine.hxx"
#include "Game.hxx"
#include "Types.hxx"
#include "Config.hxx"

#include "Scenes/MenuScene.hxx"
#include "Scenes/PlayScene.hxx"

using namespace Chunkee;


int main(int argc, char* argv[])
{
	WindowProperties props;
	props.title = WINDOW_TITLE;
	props.size = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);

	auto engine = Engine::getInstance(&props);
	auto sceneTree = Game::getInstance()->getSceneTree();

	sceneTree->addScene("menu", new MenuScene());
	sceneTree->addScene("play", new PlayScene());
	sceneTree->changeScene("menu");

	engine->start();

	return 0;
}