#pragma once

#include "../Math/Vector2F.hxx"
#include "Rect.hxx"
#include <SDL.h>


namespace Chunkee
{
	namespace Math
	{
		using RectFBase = SDL_FRect;

		class RectF
		{
		public:
			RectF() = default;
			RectF(const RectF& rect);
			RectF(const float& positionX,
				  const float& positionY,
				  const float& width,
				  const float& height);
			RectF(const Vector2F& position,
				  const float& width,
				  const float& height);
			RectF(const float& positionX,
				  const float& positionY,
				  const Vector2F& size);
			RectF(const Vector2F& position,
				  const Vector2F& size);

			void setSize(const float& width,
						 const float& height);
			void setSize(const Vector2F& size);
			void setPosition(const float& positionX,
							 const float& positionY);
			void setPosition(const Vector2F& position);
			void offset(const Vector2F& offset);

			Vector2F getPosition() const;
			Vector2F getSize() const;
			float getWidth() const;
			float getHeight() const;
			bool hasPoint(const Vector2F& point);
			bool hasPoint(const Vector2& point);
			bool hasPoint(const float& positionX,
						  const float& positionY);

			void operator=(const RectF& other);
			void setRect(const RectF& other);
			RectFBase* getBase();

		private:
			RectFBase m_rect;
		};
	}
}