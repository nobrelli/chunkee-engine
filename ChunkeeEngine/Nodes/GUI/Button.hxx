#pragma once

#include "Component.hxx"
#include <functional>


namespace Chunkee
{
	namespace GUI
	{
		using Method = std::function<void()>;

		enum class ButtonState
		{
			DEFAULT, HOVERED, CLICKED, LEN_
		};

		class Button : public Component
		{
		public:
			Button(const String& id);
			~Button();

			void handleEvents(SDL_Event* ev) override;

			void onPress(const Method& func);
			void onRelease(const Method& func);
			void onCursorIn(const Method& func);
			void onCursorOut(const Method& func);

		protected:
			Method m_onPress;
			Method m_onRelease;
			Method m_onCursorIn;
			Method m_onCursorOut;

			bool m_hovering;
			bool m_pressing;
		};
	}
}