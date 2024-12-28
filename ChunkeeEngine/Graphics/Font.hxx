#pragma once

#include <SDL_ttf.h>
#include "../Types.hxx"
#include "Color.hxx"
#include "../Math/Vector2.hxx"
#include "Texture.hxx"


namespace Chunkee
{
	namespace Graphics
	{
		class Font : public Texture
		{
		public:
			//////////////////////////////////////////////////////////////////
			Font();
			Font(TTF_Font* font);
			~Font();

			//////////////////////////////////////////////////////////////////
			void setFileName(const String&);
			void renderText(const String& text,
							const Color& color);

		private:
			void _applyText();

		private:
			String m_fileName;
			TTF_Font* m_font;
		};
	}
}