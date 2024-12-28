#pragma once

#include "../Math/Vector2.hxx"


namespace Chunkee
{
	namespace Math
	{
		class Rect
		{
		public:
			Rect() = default;
			Rect(const Rect& rect);
			Rect(const int& positionX,
				 const int& positionY,
				 const int& width,
				 const int& height);
			Rect(const Vector2& position,
				 const int& width,
				 const int& height);
			Rect(const int& positionX,
				 const int& positionY,
				 const Vector2& size);
			Rect(const Vector2& position,
				 const Vector2& size);

			void setSize(const int& width,
						 const int& height);
			void setSize(const Vector2& size);
			void setPosition(const int& positionX,
							 const int& positionY);
			void setPosition(const Vector2& position);

			Vector2 getPosition() const;
			Vector2 getSize() const;
			int getWidth() const;
			int getHeight() const;
			bool hasPoint(const Vector2& point);

		private:
			Vector2 m_position;
			Vector2 m_size;
		};
	}
}