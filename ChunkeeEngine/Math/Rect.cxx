#include "Rect.hxx"
#include <SDL_rect.h>


namespace Chunkee
{
	namespace Math
	{
		/////////////////////////////////////////////////////////////////////////////////////
		Rect::Rect(const Rect& rect) :
			m_position(rect.m_position),
			m_size(rect.m_size)
		{
		}

		/////////////////////////////////////////////////////////////////////////////////////
		Rect::Rect(const int& positionX, 
				   const int& positionY, 
				   const int& width, 
				   const int& height) :
			m_position(positionX, positionY),
			m_size(width, height)
		{
		}

		/////////////////////////////////////////////////////////////////////////////////////
		Rect::Rect(const Vector2& position, 
				   const int& width, 
				   const int& height) :
			m_position(position),
			m_size(width, height)
		{
		}

		/////////////////////////////////////////////////////////////////////////////////////
		Rect::Rect(const int& positionX,
				   const int& positionY,
				   const Vector2& size) :
			m_position(positionX, positionY),
			m_size(size)
		{
		}

		/////////////////////////////////////////////////////////////////////////////////////
		Rect::Rect(const Vector2& position,
				   const Vector2& size) :
			m_position(position),
			m_size(size)
		{
		}

		/////////////////////////////////////////////////////////////////////////////////////
		void Rect::setSize(const int& width, const int& height)
		{
			m_size.setX(width);
			m_size.setY(height);
		}

		/////////////////////////////////////////////////////////////////////////////////////
		void Rect::setSize(const Vector2& size)
		{
			m_size = size;
		}

		/////////////////////////////////////////////////////////////////////////////////////
		void Rect::setPosition(const int& positionX, const int& positionY)
		{
			m_position.setX(positionX);
			m_position.setY(positionY);
		}

		/////////////////////////////////////////////////////////////////////////////////////
		void Rect::setPosition(const Vector2& position)
		{
			m_position = position;
		}

		/////////////////////////////////////////////////////////////////////////////////////
		Vector2 Rect::getPosition() const
		{
			return m_position;
		}

		/////////////////////////////////////////////////////////////////////////////////////
		Vector2 Rect::getSize() const
		{
			return m_size;
		}

		/////////////////////////////////////////////////////////////////////////////////////
		int Rect::getWidth() const
		{
			return m_size.getX();
		}

		/////////////////////////////////////////////////////////////////////////////////////
		int Rect::getHeight() const
		{
			return m_size.getY();
		}

		/////////////////////////////////////////////////////////////////////////////////////
		bool Rect::hasPoint(const Vector2& point)
		{
			int&& px = point.getX();
			int&& py = point.getY();

			int&& rx = m_position.getX();
			int&& ry = m_position.getY();

			return ((px >= rx) && (px < (rx + getWidth())) &&
					(py >= ry) && (py < (ry + getHeight())));
		}
	}
}