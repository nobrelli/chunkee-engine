#include "Scene.hxx"
#include "../Logger.hxx"
#include "../Game.hxx"
#include "../Graphics/Renderer.hxx"

namespace Chunkee
{
    using Graphics::Renderer;
    using Graphics::Texture;

    Scene::Scene() :
        m_hasTransition(false),
        m_canvas(new Texture())
    {
        Logger::log("Scene instance created");
    }

    Scene::~Scene()
    {
        delete m_canvas;
        m_canvas = nullptr;
        Logger::log("Scene instance destroyed");
    
    }

    void Scene::init()
    {
    }

    void Scene::requestQuit()
    {
        Game::getInstance()->requestQuit();
    }

    void Scene::_render()
    {
        Renderer::getInstance()->setTarget(m_canvas);
        Renderer::getInstance()->clear();

        render();

        Renderer::getInstance()->setTarget();
        Renderer::getInstance()->render(m_canvas);
        Renderer::getInstance()->display();
    }
}