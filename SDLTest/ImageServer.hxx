#pragma once

#include <SDL.h>
#include <unordered_map>


class ImageServer
{
public:
	ImageServer(SDL_Renderer* renderer);
	~ImageServer();

	void load(const std::string& fileId,
			  const std::string& fileName);
	SDL_Texture* getImageTexture(const std::string& fileId) const;

private:
	SDL_Renderer* m_renderer;
	std::unordered_map<std::string, SDL_Texture*> m_imageTextures;
};

