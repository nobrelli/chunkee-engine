#pragma once

#include "../Node.hxx"
#include "../Transformable.hxx"


namespace Chunkee
{
	namespace GUI
	{
		class Component : public Node, public Transformable
		{
		public:
			//Component();
			//~Component();
			virtual void setPosition(const Vector2F& position) override;
			virtual void setPosition(const float& x, const float& y) override;
		};
	}
}