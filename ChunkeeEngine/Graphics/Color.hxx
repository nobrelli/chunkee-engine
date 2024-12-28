#pragma once

#include <SDL_pixels.h>
#include "../Types.hxx"


namespace Chunkee
{
	namespace Graphics
	{
		constexpr UInt8 OPAQUE = 0xffu;
		constexpr UInt8 TRANSPARENT = 0x0u;
		
		enum class RGBA : UInt8
		{
			RED,
			GREEN,
			BLUE,
			ALPHA
		};

		using ColorBase = SDL_Color;

		class Color
		{
		public:
			//////////////////////////////////////////////////////////////////
			Color();
			Color(const Color& color);
			Color(UInt8 red,
				  UInt8 green,
				  UInt8 blue,
				  UInt8 alpha = OPAQUE);

			//////////////////////////////////////////////////////////////////
			UInt8 getChannel(const RGBA& channel) const;
			void setChannel(const RGBA& channel, UInt8 value);
			ColorBase getBase() const;

		private:
			UInt8 m_r, m_g, m_b, m_a;
		};

		//////////////////////////////////////////////////////////////////
		struct
		{
			Color WHITE{ Color(0xffu, 0xffu, 0xffu, 0xffu) };
			Color BLACK{ Color(0x00u, 0x00u, 0x00u, 0x00u) };
		} Colors;
	}
}