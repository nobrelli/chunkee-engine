#include "Window.hxx"
#include "Logger.hxx"
#include <SDL.h>


namespace Chunkee
{
	//////////////////////////////////////////////////////////////////
	Window* Window::m_instance{ nullptr };
	std::mutex Window::m_mutex;

	//////////////////////////////////////////////////////////////////
	Window* Window::getInstance(WindowProperties* props)
	{
		std::lock_guard lock(m_mutex);

		if (!m_instance)
			m_instance = new Window(props);

		return m_instance;
	}

	//////////////////////////////////////////////////////////////////
	void Window::cleanup()
	{
		if (m_window)
		{
			SDL_DestroyWindow(m_window);
			m_window = nullptr;

			Logger::log("Window destroyed");
		}

		SDL_QuitSubSystem(SDL_INIT_VIDEO);

		if (m_instance)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}

	//////////////////////////////////////////////////////////////////
	WindowBase* Window::getBase() const
	{
		return m_window;
	}

	//////////////////////////////////////////////////////////////////
	WindowProperties& Window::getProperties()
	{
		return m_props;
	}

	//////////////////////////////////////////////////////////////////
	Window::Window(WindowProperties* props) :
		m_window(nullptr), m_props(*props)
	{		
		Logger::log("Window instance created");
		
		if (!SDL_InitSubSystem(SDL_INIT_VIDEO))
		{
			int flags = m_props.fullScreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_SHOWN;
			flags |= SDL_WINDOW_ALLOW_HIGHDPI;

			int&& x = m_props.position.getX();
			int&& y = m_props.position.getX();

			int positionX = x < 0 ? SDL_WINDOWPOS_CENTERED : x;
			int positionY = y < 0 ? SDL_WINDOWPOS_CENTERED : y;

			m_window = SDL_CreateWindow(m_props.title.c_str(),
										positionX,
										positionY,
										m_props.size.getX(),
										m_props.size.getY(),
										flags);

			if (!m_window)
				Logger::logException(std::format("Window creation error: {}", SDL_GetError()));
			else
				Logger::log("Window created");
		}
	
		else
		{
			Logger::logException(std::format("Init error: {}", SDL_GetError()));
		}
	}

	//////////////////////////////////////////////////////////////////
	Window::~Window()
	{
		Logger::log("Window instance destroyed");
	}
}