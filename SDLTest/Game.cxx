#include "Game.hxx"
#include "Logger.hxx"

Game::Game() : m_renderer(nullptr), m_imgServer(nullptr)
{
	Logger::log("GameInstance instance created");
}

Game::~Game()
{
	if (m_imgServer)
	{
		delete m_imgServer;
		m_imgServer = nullptr;
	}

	m_renderer = nullptr;

	Logger::log("GameInstance instance created");
}

void Game::init(SDL_Renderer* renderer)
{
	m_imgServer = new ImageServer(renderer);
	m_imgServer->load("mainbg", "assets/images/mainbg.bmp");
}

void Game::handleEvents(SDL_Event& ev)
{

}

void Game::render()
{
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_imgServer->getImageTexture("mainbg"), nullptr, nullptr);
	SDL_RenderPresent(m_renderer);
}