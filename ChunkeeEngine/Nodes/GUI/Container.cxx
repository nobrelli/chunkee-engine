#include "Container.hxx"


namespace Chunkee
{
	namespace GUI
	{
		Container::Container(float spacing) : m_spacing(spacing), m_innerHeight(0.f)
		{
		}

		void Container::addChild(const String& id, Node* node)
		{
			// center each component
			auto castedNode = dynamic_cast<Transformable*>(node);
			castedNode->setPosition(getSize().getX() / 2.f - castedNode->getRect().getWidth() / 2.f, m_innerHeight);
			m_innerHeight += castedNode->getSize().getY() + m_spacing;

			Node::addChild(id, node);

			//m_rect.setSize(m_rect.getSize().getX(), totalHeight);
		}
	}
}