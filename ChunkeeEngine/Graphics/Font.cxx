#include "Font.hxx"
#include "../Logger.hxx"
#include "../Graphics/Renderer.hxx"


namespace Chunkee
{
	namespace Graphics
	{
		using Graphics::Renderer;

		//////////////////////////////////////////////////////////////////
		Font::Font() : m_font(nullptr)
		{
			Logger::log("Font created");
		}

		//////////////////////////////////////////////////////////////////
		Font::Font(TTF_Font* font) : m_font(font)
		{
			Logger::log("Font created");
		}

		//////////////////////////////////////////////////////////////////
		Font::~Font()
		{
			TTF_CloseFont(m_font);
			m_font = nullptr;

			SDL_DestroyTexture(m_texture);
			m_texture = nullptr;

			Logger::log("Font destroyed");
		}

		//////////////////////////////////////////////////////////////////
		void Font::setFileName(const String& fileName)
		{
			m_fileName = fileName;
		}

		//////////////////////////////////////////////////////////////////
		void Font::renderText(const String& text,
							  const Color& color)
		{
			auto renderer = Renderer::getInstance()->getBase();
			SDL_Color col{
				color.getChannel(RGBA::RED),
				color.getChannel(RGBA::GREEN),
				color.getChannel(RGBA::BLUE),
				color.getChannel(RGBA::ALPHA)
			};
			SDL_Surface* temp = TTF_RenderText_Blended(m_font, text.c_str(), col);
			setTexture(SDL_CreateTextureFromSurface(renderer, temp));
			_applyText();
			SDL_FreeSurface(temp);
			temp = nullptr;
		}

		//////////////////////////////////////////////////////////////////
		void Font::_applyText()
		{
			int x, y;
			if (!SDL_QueryTexture(m_texture, nullptr, nullptr, &x, &y))
				m_rect.setSize(x, y);
		}
	}
}