#include "Vector2F.hxx"
#include <cmath>


namespace Chunkee
{
	namespace Math
	{
        /////////////////////////////////////////////////////////////////////////////////////
        Vector2F::Vector2F(const Vector2F& vec) : m_x{ vec.m_x }, m_y{ vec.m_y }
        {
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2F::Vector2F(const Vector2& vec) : 
            m_x{ static_cast<float>(vec.getX()) }, 
            m_y{ static_cast<float>(vec.getY()) }
        {
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2F::Vector2F(const float& x, const float& y) : m_x{ x }, m_y{ y }
        {
        }

        /////////////////////////////////////////////////////////////////////////////////////
        float Vector2F::getX() const
        {
            return m_x;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        float Vector2F::getY() const
        {
            return m_y;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        void Vector2F::setX(const float& x)
        {
            m_x = x;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        void Vector2F::setY(const float& y)
        {
            m_y = y;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        float Vector2F::length() const
        {
            return std::sqrtf(std::powf(static_cast<float>(m_x), 2.f) +
                              std::powf(static_cast<float>(m_y), 2.f));
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2F Vector2F::normalize()
        {
            float len = length();
            return Vector2F(m_x / len, m_y / len);
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2F& Vector2F::operator=(const Vector2& v2)
        {
            m_x = static_cast<float>(v2.getX());
            m_y = static_cast<float>(v2.getY());

            return *this;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2F& Vector2F::operator=(const Vector2F& v2)
        {
            m_x = v2.getX();
            m_y = v2.getY();

            return *this;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2F Vector2F::operator+(const Vector2F& v2) const
        {
            return Vector2F(m_x + v2.getX(), m_y + v2.getY());
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2F Vector2F::operator-(const Vector2F& v2) const
        {
            return Vector2F(m_x - v2.getX(), m_y - v2.getY());
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2F Vector2F::operator*(const float& scalar) const
        {
            return Vector2F(m_x * scalar, m_y * scalar);
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2F Vector2F::operator/(const float& scalar) const
        {
            return Vector2F(m_x / scalar, m_y / scalar);
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2F& Vector2F::operator*=(const float& scalar)
        {
            m_x *= scalar;
            m_y *= scalar;

            return *this;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2F& Vector2F::operator/=(const float& scalar)
        {
            m_x /= scalar;
            m_y /= scalar;

            return *this;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        void Vector2F::operator+=(const Vector2F& v2)
        {
            m_x += v2.m_x;
            m_y += v2.m_y;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2F& operator-=(Vector2F& v1, const Vector2F& v2)
        {
            v1.m_x -= v2.m_x;
            v1.m_y -= v2.m_y;

            return v1;
        }
	}
}