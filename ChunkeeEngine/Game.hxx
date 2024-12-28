#pragma once

#include <mutex>
#include "SceneTree.hxx"
#include <SDL_events.h>


namespace Chunkee
{
	class Game
	{
	public:
		//////////////////////////////////////////////////////////////////
		static Game* getInstance();

		//////////////////////////////////////////////////////////////////
		void cleanup();

		//////////////////////////////////////////////////////////////////
		Game(const Game&) = delete;
		void operator=(const Game&) = delete;

		//////////////////////////////////////////////////////////////////
		bool handleEvents(SDL_Event* ev);
		void update();
		void render();
		void requestQuit();

		//////////////////////////////////////////////////////////////////
		SceneTree* getSceneTree() const;

	private:
		Game();
		~Game();

	private:
		static Game* m_instance;
		static std::mutex m_mutex;

		SceneTree* m_sceneTree;
		bool m_isQuit;
	};
}