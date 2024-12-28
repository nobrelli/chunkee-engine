#include "Engine.hxx"
#include "Logger.hxx"


Engine::Engine() : m_window(nullptr), m_renderer(nullptr), m_game(nullptr)
{
	Logger::log("Engine instance created");

	SDL_Init(SDL_INIT_EVERYTHING);
	m_window = SDL_CreateWindow("Engine",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								600, 600,
								SDL_WINDOW_SHOWN |
								SDL_WINDOW_ALLOW_HIGHDPI);
	
	if (!m_window)
	{
		Logger::log(std::format("Window creation failed: {}", SDL_GetError()));
		return;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, 
									SDL_RENDERER_ACCELERATED | 
									SDL_RENDERER_PRESENTVSYNC | 
									SDL_RENDERER_TARGETTEXTURE);
	
	if (!m_renderer)
		Logger::log(std::format("Renderer creation failed: {}", SDL_GetError()));
}

Engine::~Engine()
{
	if (m_game)
	{
		delete m_game;
		m_game = nullptr;
	}

	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
	m_window = nullptr;
	m_renderer = nullptr;

	Logger::log("Engine instance destroyed");
}

void Engine::setGame(Game* game)
{
	m_game = game;
}

void Engine::start()
{
	_loop();
}

void Engine::_loop()
{
	while (true)
	{
		if (_handleEvents())
			_render();
		else break;
	}
}

bool Engine::_handleEvents()
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_QUIT)
			return false;

		m_game->handleEvents(ev);
	}

	return true;
}

void Engine::_render()
{
	m_game->render();
}

SDL_Renderer* Engine::getRenderer() const
{
	return m_renderer;
}