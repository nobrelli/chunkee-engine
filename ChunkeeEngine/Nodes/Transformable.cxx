#include "Transformable.hxx"


namespace Chunkee
{
    Transformable::Transformable() : 
        m_rect(0.f, 0.f, 0.f, 0.f), m_angle(0.f)
    {
    }

    void Transformable::translate(const Vector2F& offset)
    {
        m_rect.offset(offset);
    }

    void Transformable::rotate(const float& offset)
    {
        m_angle += offset;
    }

    void Transformable::setSize(float width, float height)
    {
        m_rect.setSize(width, height);
    }

    void Transformable::setRotation(const float& angle)
    {
        m_angle = angle;
    }

    void Transformable::setPosition(const Vector2F& position)
    {
        m_rect.setPosition(position);
    }

    void Transformable::setPosition(const float& x, const float& y)
    {
        m_rect.setPosition(x, y);
    }

    Vector2F Transformable::getPosition() const
    {
        return m_rect.getPosition();
    }

    Vector2F Transformable::getSize() const
    {
        return m_rect.getSize();
    }

    RectF& Transformable::getRect()
    {
        return m_rect;
    }

    float Transformable::getAngle() const
    {
        return m_angle;
    }
}