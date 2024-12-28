#include "Game.hxx"
#include "Logger.hxx"
#include "Servers/ImageServer.hxx"
#include "Servers/FontServer.hxx"


namespace Chunkee
{
	//////////////////////////////////////////////////////////////////
	Game* Game::m_instance{ nullptr };
	std::mutex Game::m_mutex;

	//////////////////////////////////////////////////////////////////
	Game* Game::getInstance()
	{
		std::lock_guard lock(m_mutex);

		if (!m_instance)
			m_instance = new Game();

		return m_instance;
	}

	//////////////////////////////////////////////////////////////////
	void Game::cleanup()
	{
		if (m_sceneTree)
		{
			delete m_sceneTree;
			m_sceneTree = nullptr;
		}

		FontServer::getInstance()->cleanup();
		ImageServer::getInstance()->cleanup();

		if (m_instance)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}

	//////////////////////////////////////////////////////////////////
	bool Game::handleEvents(SDL_Event* ev)
	{
		m_sceneTree->handleEvents(ev);
		return m_isQuit;
	}

	//////////////////////////////////////////////////////////////////
	void Game::update()
	{
		m_sceneTree->update();
	}

	//////////////////////////////////////////////////////////////////
	void Game::requestQuit()
	{
		m_isQuit = true;
	}

	//////////////////////////////////////////////////////////////////
	void Game::render()
	{
		m_sceneTree->render();
	}

	//////////////////////////////////////////////////////////////////
	SceneTree* Game::getSceneTree() const
	{
		return m_sceneTree;
	}

	//////////////////////////////////////////////////////////////////
	Game::Game() : m_sceneTree(nullptr), m_isQuit(false)
	{
		Logger::log("Game instance created");

		ImageServer::getInstance();
		FontServer::getInstance();

		m_sceneTree = new SceneTree();
	}

	//////////////////////////////////////////////////////////////////
	Game::~Game()
	{
		Logger::log("Game instance destroyed");
	}
}