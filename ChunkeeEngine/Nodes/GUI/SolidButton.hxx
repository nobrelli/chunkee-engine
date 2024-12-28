#pragma once

#include "Button.hxx"
#include "../../Graphics/Color.hxx"
#include "../../Graphics/Font.hxx"


namespace Chunkee
{
	using namespace Chunkee::Graphics;

	namespace GUI
	{
		constexpr UInt8 PADDING_LEFT = 0x1u;
		constexpr UInt8 PADDING_RIGHT = 0x2u;
		constexpr UInt8 PADDING_TOP = 0x4u;
		constexpr UInt8 PADDING_BOTTOM = 0x8u;
		constexpr UInt8 PADDING_ALL = 0xfu;

		class SolidButton : public Button
		{
		public:
			SolidButton(const String& id);
			~SolidButton();

			void update() override;
			void render() override;

			void setStateColor(const ButtonState& state,
							   const Color& color);
			void setText(const String& text,
						 const Color& color);
			void setFont(Font* font);
			void setPosition(const Vector2F& position) override;
			void setPosition(const float& x, const float& y) override;
			void setPadding(const UInt8& flags, const float& padding);

		private:
			String m_text;
			Font* m_font;
			Color* m_currentState;
			std::vector<Color> m_stateColors;
		};
	}
}