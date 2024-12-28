#pragma once

#include "Types.hxx"
#include "Nodes/Scene.hxx"
#include <SDL_events.h>


namespace Chunkee
{
	class SceneTree
	{
	public:
		//////////////////////////////////////////////////////////////////
		SceneTree();
		~SceneTree();

		//////////////////////////////////////////////////////////////////
		void addScene(const String& sceneID, Scene* scene);
		void changeScene(const String& sceneID);
		void removeScene(const String& sceneID);

		//////////////////////////////////////////////////////////////////
		void handleEvents(SDL_Event* ev);
		void update();
		void render();

		//////////////////////////////////////////////////////////////////
		UInt32 getNodeCount() const;
		Scene* getCurrentScene() const;

	private:
		UMap<String, Scene*> m_scenes;
		Scene* m_currentScene;
		Scene* m_nextScene;
	};
}
