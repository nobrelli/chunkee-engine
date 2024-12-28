#pragma once

#include <mutex>
#include <SDL_video.h>
#include "Math/Vector2.hxx"


namespace Chunkee
{
	using WindowBase = SDL_Window;

	//////////////////////////////////////////////////////////////////
	struct WindowProperties
	{
		std::string title;
		Math::Vector2 size;
		Math::Vector2 position{ -1, -1 };
		bool fullScreen{ false };
	};

	//////////////////////////////////////////////////////////////////
	class Window
	{
	public:
		//////////////////////////////////////////////////////////////////
		static Window* getInstance(WindowProperties* = nullptr);

		//////////////////////////////////////////////////////////////////
		void cleanup();

		//////////////////////////////////////////////////////////////////
		Window(const Window&) = delete;
		void operator=(const Window&) = delete;

		//////////////////////////////////////////////////////////////////
		WindowBase* getBase() const;
		WindowProperties& getProperties();

	private:
		Window(WindowProperties*);
		~Window();

	private:
		static Window* m_instance;
		static std::mutex m_mutex;

		WindowBase* m_window;
		WindowProperties m_props;
	};
}