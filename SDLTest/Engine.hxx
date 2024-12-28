#pragma once

#include <SDL.h>
#include "Game.hxx"


class Engine
{
public:
	Engine();
	~Engine();

	void start();
	void setGame(Game* game);
	SDL_Renderer* getRenderer() const;

private:
	void _loop();
	bool _handleEvents();
	void _render();

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	Game* m_game;
};

