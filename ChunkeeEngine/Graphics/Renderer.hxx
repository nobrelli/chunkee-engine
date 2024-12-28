#pragma once

#include <mutex>
#include <SDL_render.h>
#include "Color.hxx"
#include "Image.hxx"
#include "../Math/RectF.hxx"


namespace Chunkee
{
	namespace Graphics
	{
		using RendererBase = SDL_Renderer;

		class Renderer
		{
		public:
			//////////////////////////////////////////////////////////////////
			static Renderer* getInstance(bool accelerated = true);

			//////////////////////////////////////////////////////////////////
			void cleanup();

			//////////////////////////////////////////////////////////////////
			Renderer(const Renderer&) = delete;
			void operator=(const Renderer&) = delete;

			//////////////////////////////////////////////////////////////////
			RendererBase* getBase() const;

			//////////////////////////////////////////////////////////////////
			void clear();
			void display();
			void setRenderColor(const Color& color);
			void render(Texture* texture);
			void fill(RectF& rect, const Color& color);
			void setTarget(Texture* texture = nullptr);

		private:
			Renderer(bool accelerated = true);
			~Renderer();

		private:
			static Renderer* m_instance;
			static std::mutex m_mutex;

			RendererBase* m_renderer;
			int m_flags;
		};
	}
}