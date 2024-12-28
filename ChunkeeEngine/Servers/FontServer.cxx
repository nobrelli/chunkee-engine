#include "FontServer.hxx"
#include "../Logger.hxx"
#include "../Config.hxx"
#include "../Graphics/Renderer.hxx"
#include <SDL_ttf.h>


namespace Chunkee
{
	using Graphics::Renderer;

	//////////////////////////////////////////////////////////////////
	FontServer* FontServer::m_instance{ nullptr };
	std::mutex FontServer::m_mutex;

	//////////////////////////////////////////////////////////////////
	FontServer* FontServer::getInstance()
	{
		std::lock_guard lock(m_mutex);

		if (!m_instance)
		{
			if (TTF_Init() < 0)
			{
				Logger::logException(std::format("TTF init error: {}", TTF_GetError()));
			}
			else
				m_instance = new FontServer();
		}

		return m_instance;
	}

	//////////////////////////////////////////////////////////////////
	void FontServer::cleanup()
	{
		for (auto&& font : m_fonts)
		{
			delete font.second;
			font.second = nullptr;
		}
		m_fonts.clear();

		TTF_Quit();

		if (m_instance)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}

	//////////////////////////////////////////////////////////////////
	void FontServer::load(const String& fileName,
						  int fontSize,
						  const String& id)
	{
		String fullPath = String(FONTS_PATH + fileName);
		TTF_Font* cache = TTF_OpenFont(fullPath.c_str(), fontSize);
		
		if (cache)
		{
			Font* font = new Font(cache);
			m_fonts[id] = font;
		}
		else
			Logger::logException(std::format("Failed to load font {}", fileName));
	}

	//////////////////////////////////////////////////////////////////
	Font* FontServer::getItem(const String& id) const
	{
		return m_fonts.at(id);
	}

	//////////////////////////////////////////////////////////////////
	FontServer::FontServer()
	{
		Logger::log("FontServer instance created");
	}

	//////////////////////////////////////////////////////////////////
	FontServer::~FontServer()
	{
		Logger::log("FontServer instance destroyed");
	}
}