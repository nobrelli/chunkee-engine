#include "PlayScene.hxx"
#include "../Logger.hxx"
#include "../Servers/ImageServer.hxx"
#include "../Servers/FontServer.hxx"
#include "../Graphics/Renderer.hxx"
#include "../Graphics/Color.hxx"
#include "../Nodes/GUI/SolidButton.hxx"
#include "../Game.hxx"


using Chunkee::Logger;

using Chunkee::ImageServer;
using Chunkee::FontServer;
using Chunkee::ImageType;
using Chunkee::Graphics::Renderer;
using Chunkee::Graphics::Color;
using Chunkee::Game;

using namespace Chunkee::GUI;


PlayScene::PlayScene() : m_tween(nullptr)
{

	Logger::log("PlayScene instance created");

}

PlayScene::~PlayScene()
{

	Logger::log("PlayScene instance destroyed");

}

void PlayScene::init()
{
	ImageServer::getInstance()->load(ImageType::BMP, "mainbg.bmp", "mainbg");
}

void PlayScene::cleanup()
{
}

void PlayScene::onReady()
{
}

bool PlayScene::onEnter()
{
	//m_tween->start();
	return false;
}

bool PlayScene::onExit()
{
	return false;
}

void PlayScene::handleEvents(SDL_Event* ev)
{
	//getChild("play_btn")->handleEvents(ev);
	//dynamic_cast<Component*>(getChild("play_btn"))->setPosition(Vector2F(ev->motion.x, ev->motion.y));
	//getChild("exit_btn")->handleEvents(ev);
}

void PlayScene::update()
{
	//m_tween->update();
	//if (m_tween->isAnimating())
	//	Logger::log(tostr(m_tween->getValue()));
	//getChild("play_btn")->update();
	//getChild("exit_btn")->update();
}

void PlayScene::render()
{
	Renderer::getInstance()->render(ImageServer::getInstance()->getItem("mainbg"));
	//getChild("play_btn")->render();
	//getChild("exit_btn")->render();
}
