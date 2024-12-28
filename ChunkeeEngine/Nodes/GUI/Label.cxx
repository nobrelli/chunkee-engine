#include "Label.hxx"
#include "../../Graphics/Renderer.hxx"
#include "../../Logger.hxx"


namespace Chunkee
{
	using Graphics::Renderer;

	namespace GUI
	{
		Label::Label(const String& id) : m_font(nullptr)
		{
			m_id = id;
		}

		Label::~Label()
		{
			m_font = nullptr;
		}

		void Label::render()
		{
			Renderer::getInstance()->render(m_font);
		}

		void Label::setText(const String& text, const Color& color)
		{
			m_font->renderText(text, color);
		}

		void Label::setFont(Font* font)
		{
			m_font = font;
		}

		void Label::setPosition(const Vector2F& position)
		{
			m_font->setPosition(position);
		}

		void Label::setPosition(const float& x, const float& y)
		{
			m_font->setPosition(x, y);
		}

		String Label::getText() const
		{
			return m_text;
		}

		Font* Label::getFont() const
		{
			return m_font;
		}
	}
}