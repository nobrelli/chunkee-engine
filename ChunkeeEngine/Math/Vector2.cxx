#include "Vector2.hxx"
#include <cmath>


namespace Chunkee
{
    namespace Math
    {
        /////////////////////////////////////////////////////////////////////////////////////
        Vector2::Vector2(const Vector2& vec) : m_x{ vec.m_x }, m_y{ vec.m_y }
        {
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2::Vector2(const int& x, const int& y) : m_x{ x }, m_y{ y }
        {
        }

        /////////////////////////////////////////////////////////////////////////////////////
        int Vector2::getX() const
        {
            return m_x;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        int Vector2::getY() const
        {
            return m_y;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        void Vector2::setX(const int& x)
        {
            m_x = x;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        void Vector2::setY(const int& y)
        {
            m_y = y;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        float Vector2::length() const
        {
            return std::sqrtf(std::powf(static_cast<float>(m_x), 2.f) + 
                              std::powf(static_cast<float>(m_y), 2.f));
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2 Vector2::normalize()
        {
            float len = length();
            return Vector2(static_cast<int>(std::floor(m_x / len)), 
                           static_cast<int>(std::floor(m_y / len)));
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2 Vector2::operator+(const Vector2& v2) const
        {
            return Vector2(m_x + v2.getX(), m_y + v2.getY());
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2 Vector2::operator-(const Vector2& v2) const
        {
            return Vector2(m_x - v2.getX(), m_y - v2.getY());
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2 Vector2::operator*(const int& scalar) const
        {
            return Vector2(m_x * scalar, m_y * scalar);
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2 Vector2::operator/(const int& scalar) const
        {
            return Vector2(m_x / scalar, m_y / scalar);
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2& Vector2::operator*=(const int& scalar)
        {
            m_x *= scalar;
            m_y *= scalar;

            return *this;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2& Vector2::operator/=(const int& scalar)
        {
            m_x /= scalar;
            m_y /= scalar;

            return *this;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2& operator+=(Vector2& v1, const Vector2& v2)
        {
            v1.m_x += v2.m_x;
            v1.m_y += v2.m_y;

            return v1;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        Vector2& operator-=(Vector2& v1, const Vector2& v2)
        {
            v1.m_x -= v2.m_x;
            v1.m_y -= v2.m_y;

            return v1;
        }
    }
}
