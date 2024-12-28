#pragma once

#include "../Math/RectF.hxx"


namespace Chunkee
{
	using Math::RectF;
	using Math::Vector2F;

	class Transformable
	{
	public:
		Transformable();
		virtual ~Transformable() {};

		void translate(const Vector2F& offset);
		void rotate(const float& offset);

		void setSize(float width, float height);
		void setRotation(const float& angle);
		virtual void setPosition(const Vector2F& position);
		virtual void setPosition(const float& x, const float& y);

		Vector2F getPosition() const;
		Vector2F getSize() const;
		RectF& getRect();
		float getAngle() const;

	protected:
		RectF m_rect;
		float m_angle;
	};
}
