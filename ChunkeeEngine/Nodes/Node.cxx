#include "Node.hxx"
#include "../Logger.hxx"


namespace Chunkee
{
    Node::Node() : m_parent(nullptr)
    {
    
        Logger::log("Node instance created");
    
    }

    Node::~Node()
    {
    
        Logger::log("Node instance destroyed");
    
    }

    void Node::addChild(const String& id, Node* node)
    {
        node->m_parent = this;
        m_children[id] = node;
    }

    void Node::addChildToNode(String&& id,
                              Node*&& node, Node*&& dest)
    {
        node->m_parent = dest;
        dest->addChild(std::move(id), std::move(node));
    }

    Node* Node::findNode(const String& id) const
    {
        Node*&& node = nullptr;

        for (auto&& child : m_children)
        {
            if (child.first == id)
            {
                node = child.second;
                break;
            }
            else
            {
                if (child.second->getNodeCount() > 0)
                    node = child.second->findNode(id);
            }
        }

        return std::move(node);
    }

    UInt32 Node::getChildCount() const
    {
        return m_children.size();
    }

    UInt32 Node::getNodeCount() const
    {
        auto&& total = getChildCount();

        if (total > 0)
            for (auto& child : m_children)
                total += child.second->getNodeCount();

        return total;
    }

    Node* Node::getChild(const String&& id)
    {
        return m_children[id];
    }

    void Node::init()
    {
    }

    void Node::cleanup()
    {
        for (auto&& child : m_children)
        {
            child.second->cleanup();
            delete child.second;
            child.second = nullptr;
        }

        m_children.clear();
    }

    void Node::handleEvents(SDL_Event* ev)
    {
        for (auto&& child : m_children)
            child.second->handleEvents(ev);
    }

    void Node::update()
    {
        for (auto&& child : m_children)
            child.second->update();
    }

    void Node::render()
    {
        for (auto&& child : m_children)
            child.second->render();
    }
}