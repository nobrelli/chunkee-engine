#include "RectF.hxx"
#include <type_traits>


namespace Chunkee
{
	namespace Math
	{
		/////////////////////////////////////////////////////////////////////////////////////
		RectF::RectF(const RectF& rect)
		{
			setRect(rect);
		}

		/////////////////////////////////////////////////////////////////////////////////////
		RectF::RectF(const float& positionX,
					 const float& positionY,
					 const float& width,
					 const float& height)
		{
			m_rect.x = positionX;
			m_rect.y = positionY;
			m_rect.w = width;
			m_rect.h = height;
		}

		/////////////////////////////////////////////////////////////////////////////////////
		void RectF::setSize(const float& width, const float& height)
		{
			m_rect.w = width;
			m_rect.h = height;
		}

		/////////////////////////////////////////////////////////////////////////////////////
		void RectF::setSize(const Vector2F& size)
		{
			m_rect.w = size.getX();
			m_rect.h = size.getY();
		}

		/////////////////////////////////////////////////////////////////////////////////////
		void RectF::setPosition(const float& positionX, const float& positionY)
		{
			m_rect.x = positionX;
			m_rect.y = positionY;
		}

		/////////////////////////////////////////////////////////////////////////////////////
		void RectF::setPosition(const Vector2F& position)
		{
			m_rect.x = position.getX();
			m_rect.y = position.getY();
		}

		void RectF::offset(const Vector2F& offset)
		{
			m_rect.x += offset.getX();
			m_rect.y += offset.getY();
		}

		/////////////////////////////////////////////////////////////////////////////////////
		Vector2F RectF::getPosition() const
		{
			return Vector2F(m_rect.x, m_rect.y);
		}

		/////////////////////////////////////////////////////////////////////////////////////
		Vector2F RectF::getSize() const
		{
			return Vector2F(m_rect.w, m_rect.h);
		}

		/////////////////////////////////////////////////////////////////////////////////////
		float RectF::getWidth() const
		{
			return m_rect.w;
		}

		/////////////////////////////////////////////////////////////////////////////////////
		float RectF::getHeight() const
		{
			return m_rect.h;
		}

		/////////////////////////////////////////////////////////////////////////////////////
		bool RectF::hasPoint(const Vector2F& point)
		{
			float&& px = point.getX();
			float&& py = point.getY();

			float& rx = m_rect.x;
			float& ry = m_rect.y;

			return ((px >= rx) && (px < (rx + getWidth())) &&
					(py >= ry) && (py < (ry + getHeight())));
		}

		/////////////////////////////////////////////////////////////////////////////////////
		bool RectF::hasPoint(const Vector2& point)
		{
			return hasPoint(Vector2F(point));
		}

		bool RectF::hasPoint(const float& positionX, const float& positionY)
		{
			return hasPoint(Vector2F(positionX, positionY));
		}

		/////////////////////////////////////////////////////////////////////////////////////
		void RectF::operator=(const RectF& other)
		{
			setRect(other);
		}

		void RectF::setRect(const RectF& other)
		{
			m_rect.x = other.getPosition().getX();
			m_rect.y = other.getPosition().getY();

			m_rect.w = other.getWidth();
			m_rect.h = other.getHeight();
		}

		RectFBase* RectF::getBase()
		{
			return &m_rect;
		}
	}
}