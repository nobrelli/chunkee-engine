#include "Component.hxx"


namespace Chunkee
{
	namespace GUI
	{
		void Component::setPosition(const Vector2F& position)
		{
			auto oldPos = m_rect.getPosition();
			Transformable::setPosition(position);
			for (auto&& child : m_children)
			{
				auto current = dynamic_cast<Component*>(child.second);
				Vector2F newPos(
					current->getPosition().getX() - getPosition().getX(),
					0.f
				);
				current->translate(newPos);
			}
		}

		void Component::setPosition(const float& x, const float& y)
		{
			auto oldPos = getPosition();
			Transformable::setPosition(x, y);
			for (auto&& child : m_children)
			{
				auto current = dynamic_cast<Component*>(child.second);
				current->setPosition(getPosition().getX() + (current->getPosition().getX() - oldPos.getX()),
									 getPosition().getY() + (current->getPosition().getY() - oldPos.getY()));
			}
		}
	}
}