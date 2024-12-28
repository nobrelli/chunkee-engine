#include "SolidButton.hxx"
#include "../../Graphics/Renderer.hxx"


namespace Chunkee
{
	using Graphics::Renderer;

	namespace GUI
	{
		SolidButton::SolidButton(const String& id) : 
			Button(id), m_font(nullptr), m_currentState(nullptr)
		{
			for (int i = 0; i < static_cast<int>(ButtonState::LEN_); ++i)
				m_stateColors.push_back(Color(Colors.BLACK));
		}

		SolidButton::~SolidButton()
		{
			m_font = nullptr;
			m_stateColors.clear();
		}

		void SolidButton::update()
		{
			if (m_hovering)
			{
				m_currentState = &m_stateColors[static_cast<int>(ButtonState::HOVERED)];

				if (m_pressing)
					m_currentState = &m_stateColors[static_cast<int>(ButtonState::CLICKED)];
			}
			else
				m_currentState = &m_stateColors[static_cast<int>(ButtonState::DEFAULT)];

			Node::update();
		}

		void SolidButton::render()
		{
			Renderer::getInstance()->fill(m_rect, *m_currentState);
			Renderer::getInstance()->render(m_font);

			//Node::render();
		}

		void SolidButton::setStateColor(const ButtonState& state, const Color& color)
		{
			m_stateColors[static_cast<int>(state)] = color;
		}

		void SolidButton::setText(const String& text, const Color& color)
		{
			m_font->renderText(text, color);
			m_rect.setSize(m_font->getRect().getSize());
		}

		void SolidButton::setFont(Font* font)
		{
			m_font = font;
		}

		void SolidButton::setPosition(const Vector2F& position)
		{
			Component::setPosition(position);
			m_font->setPosition(position);
		}

		void SolidButton::setPosition(const float& x, const float& y)
		{
			Component::setPosition(x, y);
			m_font->setPosition(x, y);
		}

		void SolidButton::setPadding(const UInt8& flags, const float& padding)
		{
			if (flags & PADDING_LEFT)
			{
				m_rect.setSize(m_rect.getWidth() + padding, m_rect.getHeight());
				m_font->translate(Vector2F(padding, 0.f));
			}
			if (flags & PADDING_RIGHT)
			{
				m_rect.setSize(m_rect.getWidth() + padding, m_rect.getHeight());
			}
			if (flags & PADDING_TOP)
			{
				m_rect.setSize(m_rect.getWidth(), m_rect.getHeight() + padding);
				m_font->translate(Vector2F(0.f, padding));
			}
			if (flags & PADDING_BOTTOM)
			{
				m_rect.setSize(m_rect.getWidth(), m_rect.getHeight() + padding);
			}
		}
	}
}