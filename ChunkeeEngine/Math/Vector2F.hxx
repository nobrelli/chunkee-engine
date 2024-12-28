#pragma once

#include "Vector2.hxx"


namespace Chunkee
{
	namespace Math
	{
        class Vector2F
        {
        public:
            Vector2F(const Vector2F& vec);
            Vector2F(const Vector2& vec);
            Vector2F(const float& x = 0.f, const float& y = 0.f);

            float getX() const;
            float getY() const;

            void setX(const float& x);
            void setY(const float& y);

            float length() const;
            Vector2F normalize();

            Vector2F& operator=(const Vector2& v2);
            Vector2F& operator=(const Vector2F& v2);

            Vector2F operator+(const Vector2F& v2) const;
            Vector2F operator-(const Vector2F& v2) const;
            Vector2F operator*(const float& scalar) const;
            Vector2F operator/(const float& scalar) const;
            Vector2F& operator*=(const float& scalar);
            Vector2F& operator/=(const float& scalar);

            void operator+=(const Vector2F& v2);
            friend Vector2F& operator-=(Vector2F& v1, const Vector2F& v2);

        private:
            float m_x;
            float m_y;
        };
	}
}