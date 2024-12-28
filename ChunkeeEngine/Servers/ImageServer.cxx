#include "ImageServer.hxx"
#include "ImageServer.hxx"
#include "../Logger.hxx"
#include "../Config.hxx"
#include "../Graphics/Renderer.hxx"
#include <SDL_image.h>


namespace Chunkee
{
	using Graphics::Renderer;
	using Graphics::RendererBase;

	//////////////////////////////////////////////////////////////////
	ImageServer* ImageServer::m_instance{ nullptr };
	std::mutex ImageServer::m_mutex;

	ImageServer* ImageServer::getInstance()
	{
		std::lock_guard lock(m_mutex);

		if (!m_instance)
		{
			IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
			m_instance = new ImageServer();
		}

		return m_instance;
	}

	//////////////////////////////////////////////////////////////////
	void ImageServer::cleanup()
	{
		IMG_Quit();

		for (auto&& image : m_images)
		{
			delete image.second;
			image.second = nullptr;
		}
		m_images.clear();

		if (m_instance)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}

	//////////////////////////////////////////////////////////////////
	void ImageServer::load(ImageType type, 
						   const String& fileName,
						   const String& id)
	{
		Image* image = nullptr;
		auto renderer = Renderer::getInstance()->getBase();
		String fullPath = String(IMAGES_PATH + fileName);

		if (type == ImageType::BMP)
		{
			SDL_Surface* temp = SDL_LoadBMP(fullPath.c_str());

			if (temp)
				image = new Image(temp);
		
			else
				Logger::logException(std::format("Failed to load image {}", fileName));
		}
		else
		{
			image = new Image(IMG_LoadTexture(renderer, fullPath.c_str()));
		}
		
		if (image)
			m_images[id] = image;
		else
			Logger::logException(std::format("Failed to load image {}", fileName));
	}

	//////////////////////////////////////////////////////////////////
	Image* ImageServer::getItem(const String& id) const
	{
		return m_images.at(id);
	}

	//////////////////////////////////////////////////////////////////
	ImageServer::ImageServer()
	{
		Logger::log("ImageServer instance created");
	}

	//////////////////////////////////////////////////////////////////
	ImageServer::~ImageServer()
	{
		Logger::log("ImageServer instance destroyed");
	}
}