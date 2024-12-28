#pragma once

#include "Component.hxx"
#include "../../Types.hxx"
#include "../../Graphics/Font.hxx"


namespace Chunkee
{
	using Graphics::Font;
	using Graphics::Color;

	namespace GUI
	{
		class Label : public Component
		{
		public:
			Label(const String& id);
			~Label();

			void render() override;

			void setText(const String& text,
						 const Color& color);
			void setFont(Font* font);
			void setPosition(const Vector2F& position) override;
			void setPosition(const float& x, const float& y) override;

			String getText() const;
			Font* getFont() const;

		private:
			String m_text;
			Font* m_font;
		};
	}
}