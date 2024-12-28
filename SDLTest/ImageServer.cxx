#include "ImageServer.hxx"
#include "Logger.hxx"


ImageServer::ImageServer(SDL_Renderer* renderer) : m_renderer(renderer)
{
	Logger::log("ImageInstance instance created");
}

ImageServer::~ImageServer()
{
	for (auto& item : m_imageTextures)
	{
		SDL_DestroyTexture(item.second);
		item.second = nullptr;
	}
	m_imageTextures.clear();
	m_renderer = nullptr;

	Logger::log("ImageInstance instance destroyed");
}

void ImageServer::load(const std::string& fileId, 
					   const std::string& fileName)
{
	SDL_Surface* temp = SDL_LoadBMP(fileName.c_str());

	if (!temp)
	{
		Logger::log(std::format("Could not load image: {}", SDL_GetError()));
		return;
	}

	SDL_Texture* imageTex = SDL_CreateTextureFromSurface(m_renderer, temp);

	if (!imageTex)
	{
		Logger::log(std::format("Can't create an image texture: {}", SDL_GetError()));
		return;
	}

	m_imageTextures[fileId] = imageTex;
	SDL_FreeSurface(temp);
	temp = nullptr;
}

SDL_Texture* ImageServer::getImageTexture(const std::string& fileId) const
{
	if (m_imageTextures.contains(fileId))
		return m_imageTextures.at(fileId);
	
	return nullptr;
}