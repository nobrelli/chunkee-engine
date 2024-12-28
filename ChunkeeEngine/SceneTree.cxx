#include "SceneTree.hxx"
#include "Logger.hxx"


namespace Chunkee
{
	//////////////////////////////////////////////////////////////////
	SceneTree::SceneTree() : m_currentScene(nullptr), m_nextScene(nullptr)
	{
		Logger::log("SceneTree instance created");
	}

	//////////////////////////////////////////////////////////////////
	SceneTree::~SceneTree()
	{
		m_currentScene = nullptr;

		for (auto& scene : m_scenes)
		{
			scene.second->cleanup();
			delete scene.second;
			scene.second = nullptr;
		}

		m_scenes.clear();

		Logger::log("SceneTree instance destroyed");
	}

	//////////////////////////////////////////////////////////////////
	void SceneTree::addScene(const String& sceneID, Scene* scene)
	{
		auto& newScene = m_scenes.insert(
			std::make_pair(sceneID, scene)).first->second;
		newScene->onReady();
	}

	//////////////////////////////////////////////////////////////////
	void SceneTree::changeScene(const String& sceneID)
	{
		if (m_scenes.contains(sceneID))
		{
			m_nextScene = m_scenes[sceneID];
			m_nextScene->init();

			if (m_currentScene)
			{
				m_currentScene->onExit();

				//if (m_currentScene->m_hasTransition)
				//{
				//	m_currentScene->m_transitioning = true;
				//	return;
				//}
			}

			m_currentScene = m_scenes[sceneID];
			m_currentScene->onEnter();
		}
	}

	//////////////////////////////////////////////////////////////////
	void SceneTree::removeScene(const String& sceneID)
	{
		if (m_scenes.contains(sceneID))
		{
			auto& toRemove = m_scenes[sceneID];
			// Is this the current scene?
			if (m_currentScene == toRemove)
				m_currentScene = nullptr;

			toRemove->cleanup();

			if (m_scenes.size() > 1)
				m_scenes.erase(sceneID);
			else
				m_scenes.clear();
		}
	}

	//////////////////////////////////////////////////////////////////
	void SceneTree::handleEvents(SDL_Event* ev)
	{
		if (m_currentScene)
			m_currentScene->handleEvents(ev);
	}

	//////////////////////////////////////////////////////////////////
	void SceneTree::update()
	{
		if (m_currentScene)
			m_currentScene->update();
	}

	//////////////////////////////////////////////////////////////////
	void SceneTree::render()
	{
		if (m_currentScene)
		{
			//if (m_currentScene->m_transitioning)
			//	m_nextScene->_render();

			m_currentScene->_render();
		}
	}

	//////////////////////////////////////////////////////////////////
	UInt32 SceneTree::getNodeCount() const
	{
		return m_currentScene->getNodeCount();
	}

	//////////////////////////////////////////////////////////////////
	Scene* SceneTree::getCurrentScene() const
	{
		return m_currentScene;
	}
}