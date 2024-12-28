#pragma once

#include <SDL.h>
#include "../Types.hxx"
#include "../Math/Vector2F.hxx"


namespace Chunkee
{
	using Math::Vector2F;

	class Node
	{
	public:
		Node();
		virtual ~Node();

		virtual void init();
		virtual void cleanup();
		
		virtual void handleEvents(SDL_Event* ev);
		virtual void update();
		virtual void render();

		virtual void addChild(const String& id, Node* node);
		void addChildToNode(String&& id,
							Node*&& node,
							Node*&& dest);
		Node* findNode(const String& id) const;
		UInt32 getChildCount() const;
		UInt32 getNodeCount() const;
		Node* getChild(const String&& id);

	protected:
		String m_id;
		Node* m_parent;
		UMap<String, Node*> m_children;
	};
}
