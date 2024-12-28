#include "Button.hxx"
#include "../../Logger.hxx"


namespace Chunkee
{
	namespace GUI
	{
		Button::Button(const String& id) : m_hovering(false), m_pressing(false)
		{
			m_id = id;
		}

		Button::~Button()
		{
		}

		void Button::handleEvents(SDL_Event* ev)
		{
			bool interacted = false;

			if (m_rect.hasPoint(ev->motion.x, 
								ev->motion.y))
			{
				if (!m_hovering)
				{
					m_hovering = true;

					if (m_onCursorIn) 
						m_onCursorIn();
				}

				if (ev->type == SDL_MOUSEBUTTONDOWN && ev->button.button == SDL_BUTTON_LEFT)
				{
					if (!m_pressing)
					{
						m_pressing = true;

						if (m_onPress)
						{
							interacted = true;
							m_onPress();
						}
					}
				}
				else if (ev->type == SDL_MOUSEBUTTONUP && ev->button.button == SDL_BUTTON_LEFT)
				{
					if (m_pressing)
					{
						m_pressing = false;

						if (m_onRelease)
							m_onRelease();
					}
				}
			}
			else
			{
				if (m_hovering)
				{
					m_hovering = false;
					m_pressing = false;

					if (m_onCursorOut) 
						m_onCursorOut();
				}
			}

			if (!interacted)
				Node::handleEvents(ev);
		}

		void Button::onPress(const Method& func)
		{
			m_onPress = func;
		}

		void Button::onRelease(const Method& func)
		{
			m_onRelease = func;
		}

		void Button::onCursorIn(const Method& func)
		{
			m_onCursorIn = func;
		}

		void Button::onCursorOut(const Method& func)
		{
			m_onCursorOut = func;
		}
	}
}