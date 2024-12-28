#include "Color.hxx"


namespace Chunkee
{
	namespace Graphics
	{
		/////////////////////////////////////////////////////////////////////////////////////
		Color::Color() : m_r(0xffu), m_g(0xffu), m_b(0xffu), m_a(OPAQUE)
		{
		}

		/////////////////////////////////////////////////////////////////////////////////////
		Color::Color(const Color& color) : 
			m_r(color.m_r), m_g(color.m_g), 
			m_b(color.m_b), m_a(color.m_a)
		{
		}

		/////////////////////////////////////////////////////////////////////////////////////
		Color::Color(UInt8 red,
					 UInt8 green,
					 UInt8 blue,
					 UInt8 alpha) :
			m_r(red), m_g(green),
			m_b(blue), m_a(alpha)
		{
		}

		/////////////////////////////////////////////////////////////////////////////////////
		UInt8 Color::getChannel(const RGBA& channel) const
		{
			switch (channel)
			{
				case RGBA::RED:
					return m_r;
				case RGBA::BLUE:
					return m_b;
				case RGBA::GREEN:
					return m_g;
				case RGBA::ALPHA:
					return m_a;
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////
		void Color::setChannel(const RGBA& channel, UInt8 value)
		{
			switch (channel)
			{
				case RGBA::RED:
					m_r = value;
					break;
				case RGBA::BLUE:
					m_b = value;
					break;
				case RGBA::GREEN:
					m_g = value;
					break;
				case RGBA::ALPHA:
					m_a = value;
					break;
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////
		ColorBase Color::getBase() const
		{
			return ColorBase{ m_r, m_g, m_b, m_a };
		}
	}
}