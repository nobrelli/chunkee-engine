#include <SDL.h>
#include "Engine.hxx"
#include "Logger.hxx"
#include "Window.hxx"
#include "Graphics/Renderer.hxx"
#include "Game.hxx"
#include "Types.hxx"


namespace Chunkee
{
	using namespace Graphics;

	//////////////////////////////////////////////////////////////////
	Engine* Engine::m_instance{ nullptr };
	std::mutex Engine::m_mutex;

	//////////////////////////////////////////////////////////////////
	Engine* Engine::getInstance(WindowProperties* props)
	{
		std::lock_guard lock(m_mutex);

		if (!m_instance)
			m_instance = new Engine(props);

		return m_instance;
	}

	//////////////////////////////////////////////////////////////////
	void Engine::cleanup()
	{
		Game::getInstance()->cleanup();
		Renderer::getInstance()->cleanup();
		Window::getInstance()->cleanup();

		SDL_QuitSubSystem(SDL_INIT_EVENTS);
		SDL_Quit();

		if (m_instance)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}

	//////////////////////////////////////////////////////////////////
	void Engine::start()
	{
		Logger::log("Engine started");
		_loop();
	}

	//////////////////////////////////////////////////////////////////
	Engine::Engine(WindowProperties* props)
	{
		Logger::log("Engine instance created");

		Window::getInstance(props);
		Renderer::getInstance();
		Game::getInstance();
	}

	//////////////////////////////////////////////////////////////////
	Engine::~Engine()
	{
		Logger::log("Engine instance destroyed");
	}

	//////////////////////////////////////////////////////////////////
	void Engine::_loop()
	{
		SDL_InitSubSystem(SDL_INIT_EVENTS);
		//float timePerFrame = 1000.f / 60.f;

		while (true)
		{
			//UInt64 start = SDL_GetPerformanceCounter();

			if (_handleEvents())
			{
				_update();
				_render();
			}
			else
			{
				break;
			}

			//UInt64 end = SDL_GetPerformanceCounter();
			//float elapsed = (end - start) / static_cast<float>(SDL_GetPerformanceFrequency());
			
			//if (elapsed < timePerFrame)
			//	SDL_Delay(static_cast<UInt32>(timePerFrame - elapsed));
		}

		cleanup();
	}

	//////////////////////////////////////////////////////////////////
	bool Engine::_handleEvents()
	{
		SDL_Event ev;

		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT || Game::getInstance()->handleEvents(&ev))
				return false;
		}

		return true;
	}

	//////////////////////////////////////////////////////////////////
	void Engine::_update()
	{
		Game::getInstance()->update();
	}

	//////////////////////////////////////////////////////////////////
	void Engine::_render()
	{
		Game::getInstance()->render();
	}
}