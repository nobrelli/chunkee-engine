#pragma once

#include <SDL.h>
#include "ImageServer.hxx"

class Game
{
public:
	Game();
	~Game();

	void init(SDL_Renderer* renderer);
	void handleEvents(SDL_Event& ev);
	void render();

private:
	SDL_Renderer* m_renderer;
	ImageServer* m_imgServer;
};

