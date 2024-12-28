#pragma once

#include "../Nodes/Scene.hxx"
#include "../Math/Tweener.hxx"


using Chunkee::Scene;
using namespace Chunkee::Math;

class PlayScene final : public Scene
{
public:
    PlayScene();
    ~PlayScene();

    void init() override final;
    void cleanup() override final;

    void onReady() override final;
    bool onEnter() override final;
    bool onExit() override final;

    void handleEvents(SDL_Event* ev) override final;
    void update() override final;
    void render() override final;

private:
    Tween* m_tween;
};