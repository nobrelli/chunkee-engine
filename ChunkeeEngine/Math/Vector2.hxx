#pragma once


namespace Chunkee
{
    namespace Math
    {
        class Vector2
        {
        public:
            Vector2(const Vector2& vec);
            Vector2(const int& x = 0.f, const int& y = 0.f);

            int getX() const;
            int getY() const;

            void setX(const int& x);
            void setY(const int& y);

            float length() const;
            Vector2 normalize();

            Vector2 operator+(const Vector2& v2) const;
            Vector2 operator-(const Vector2& v2) const;
            Vector2 operator*(const int& scalar) const;
            Vector2 operator/(const int& scalar) const;
            Vector2& operator*=(const int& scalar);
            Vector2& operator/=(const int& scalar);

            friend Vector2& operator+=(Vector2& v1, const Vector2& v2);
            friend Vector2& operator-=(Vector2& v1, const Vector2& v2);

        private:
            int m_x;
            int m_y;
        };
    }
}
