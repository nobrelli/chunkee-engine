#include "MenuScene.hxx"
#include "../Logger.hxx"
#include "../Servers/ImageServer.hxx"
#include "../Servers/FontServer.hxx"
#include "../Graphics/Renderer.hxx"
#include "../Graphics/Color.hxx"
#include "../Nodes/GUI/SolidButton.hxx"
#include "../Nodes/GUI/Container.hxx"
#include "../Game.hxx"


using Chunkee::Logger;

using Chunkee::ImageServer;
using Chunkee::FontServer;
using Chunkee::ImageType;
using Chunkee::Graphics::Renderer;
using Chunkee::Graphics::Color;
using Chunkee::Game;

using namespace Chunkee::GUI;


MenuScene::MenuScene() : m_tween(nullptr)
{
	m_hasTransition = true;
	Logger::log("MenuScene instance created");
}

MenuScene::~MenuScene()
{
	Logger::log("MenuScene instance destroyed");
}

void MenuScene::cleanup()
{
	if (m_tween)
		delete m_tween;
	m_tween = nullptr;
}

void MenuScene::onReady()
{
	ImageServer::getInstance()->load(ImageType::BMP, "mainbg.bmp", "mainbg");
	FontServer::getInstance()->load("florsn.ttf", 32, "f1");
	auto&& font1 = FontServer::getInstance()->getItem("f1");

	Container* cont = new Container(20.f);
	cont->setSize(600.f, 600.f);

	SolidButton* btn1 = new SolidButton("btn1");
	btn1->setFont(font1);
	btn1->setText("Play", Color(0x65, 0xd4, 0x79));
	btn1->setPosition(100.f, 100.f);
	btn1->setPadding(PADDING_TOP | PADDING_BOTTOM, 10.f);
	btn1->setPadding(PADDING_LEFT | PADDING_RIGHT, 17.f);
	btn1->onPress([&]() {
		Game::getInstance()->getSceneTree()->changeScene("play");
				  });
	cont->addChild("btn1", btn1);
	//auto&& font2 = FontServer::getInstance()->getItem("f2");
	SolidButton* btn2 = new SolidButton("btn2");
	btn2->setFont(font1);
	btn2->setText("Exit", Color(0xff, 0xff, 0xff));
	btn2->setPosition(120.f, 170.f);
	btn2->setPadding(PADDING_TOP | PADDING_BOTTOM, 10.f);
	btn2->setPadding(PADDING_LEFT | PADDING_RIGHT, 17.f);
	btn2->setStateColor(ButtonState::DEFAULT, Color(0x69, 0x70, 0xd7));
	btn2->setStateColor(ButtonState::HOVERED, Color(0x4d, 0x54, 0xb5));
	btn2->setStateColor(ButtonState::CLICKED, Color(0x30, 0x35, 0x8c));
	cont->addChild("btn2", btn2);
	//btn2->onPress([btn2]() {
	//	btn2->setPosition(btn2->getPosition().getX() + 10.f, 170.f);
	//			  });
	//SolidButton* btn3 = new SolidButton("btn3");
	//btn3->setFont(font2);
	//btn3->setText("Eyyy", Color(0xff, 0xff, 0xff));
	//btn3->setPosition(130.f, 220.f);
	//btn2->setPadding(PADDING_TOP | PADDING_BOTTOM, 10.f);
	//btn2->setPadding(PADDING_LEFT | PADDING_RIGHT, 17.f);
	//btn3->setStateColor(ButtonState::DEFAULT, Color(0x69, 0x70, 0xd7));
	//btn3->setStateColor(ButtonState::HOVERED, Color(0x4d, 0x54, 0xb5));
	//btn3->setStateColor(ButtonState::CLICKED, Color(0x30, 0x35, 0x8c));
	//btn3->onPress([&]() {
	//	requestQuit();
	//			  });
	//btn2->addChild("exit_btn", btn3);
	//btn1->addChild("eyyyy", btn2);
	addChild("cont", cont);
	m_tween = new Tween(0.f, 1.f, 1000u, Easing::BACK, EasingMode::IN_OUT);
}

bool MenuScene::onEnter()
{
	return false;
}

bool MenuScene::onExit()
{
	m_tween->start();
	return false;
}

void MenuScene::handleEvents(SDL_Event* ev)
{
	getChild("cont")->handleEvents(ev);
	//dynamic_cast<Component*>(getChild("play_btn"))->setPosition(Vector2F(ev->motion.x, ev->motion.y));
	//getChild("exit_btn")->handleEvents(ev);
}

void MenuScene::update()
{
	//if (m_tween->isAnimating())
	//{
	//	m_tween->update();
	//	ImageServer::getInstance()->getItem("mainbg")->setPosition(600.f * m_tween->getValue(), 0.f);
	//	Logger::log(tostr(m_tween->getValue()));
	//}
	getChild("cont")->update();
	//getChild("exit_btn")->update();
}

void MenuScene::render()
{
	Renderer::getInstance()->render(ImageServer::getInstance()->getItem("mainbg"));
	getChild("cont")->render();
	//getChild("exit_btn")->render();
	//Renderer::getInstance()->clear();
}
