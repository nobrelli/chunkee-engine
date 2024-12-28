#pragma once

#include "Node.hxx"
#include "../Graphics/Texture.hxx"
#include "../Math/Tweener.hxx"


namespace Chunkee
{
    class SceneTree;

    class Scene : public Node
    {
    public:
        Scene();
        virtual ~Scene() override;

        virtual void onReady() {}
        virtual bool onEnter() { return false; }
        virtual bool onExit() { return false; }

        void requestQuit();

    protected:
        bool m_hasTransition;
        bool m_transitioning;
        Graphics::Texture* m_canvas;

    private:
        //void _doTransition();
        void init() override;
        void _render();

        friend class SceneTree;
    };
}
