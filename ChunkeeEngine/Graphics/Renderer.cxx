#include "Renderer.hxx"
#include "../Window.hxx"
#include "../Logger.hxx"


namespace Chunkee
{
	namespace Graphics
	{
		//////////////////////////////////////////////////////////////////
		Renderer* Renderer::m_instance{ nullptr };
		std::mutex Renderer::m_mutex;

		//////////////////////////////////////////////////////////////////
		Renderer* Renderer::getInstance(bool accelerated)
		{
			std::lock_guard lock(m_mutex);

			if (!m_instance)
				m_instance = new Renderer(accelerated);
			
			return m_instance;
		}

		//////////////////////////////////////////////////////////////////
		void Renderer::cleanup()
		{
			if (m_renderer)
			{
				SDL_DestroyRenderer(m_renderer);
				m_renderer = nullptr;

				Logger::log("Renderer destroyed");
			}

			if (m_instance)
			{
				delete m_instance;
				m_instance = nullptr;
			}
		}

		//////////////////////////////////////////////////////////////////
		Renderer::Renderer(bool accelerated)
		{
			Logger::log("Renderer instance created");
		
			m_flags = accelerated ? SDL_RENDERER_ACCELERATED : SDL_RENDERER_SOFTWARE;
			m_flags |= SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE;

			m_renderer = SDL_CreateRenderer(Window::getInstance()->getBase(), -1, m_flags);
		
			if (!m_renderer)
				Logger::logException(std::format("Renderer creation error: {}", SDL_GetError()));
			else
				Logger::log("Renderer created");
		
		}

		//////////////////////////////////////////////////////////////////
		Renderer::~Renderer()
		{
			Logger::log("Renderer instance destroyed");
		}

		//////////////////////////////////////////////////////////////////
		RendererBase* Renderer::getBase() const
		{
			return m_renderer;
		}

		//////////////////////////////////////////////////////////////////
		void Renderer::clear()
		{
			SDL_RenderClear(m_renderer);
		}

		//////////////////////////////////////////////////////////////////
		void Renderer::display()
		{
			SDL_RenderPresent(m_renderer);
		}

		//////////////////////////////////////////////////////////////////
		void Renderer::setRenderColor(const Color& color)
		{
			SDL_SetRenderDrawColor(m_renderer,
								   color.getChannel(RGBA::RED),
								   color.getChannel(RGBA::GREEN),
								   color.getChannel(RGBA::BLUE),
								   color.getChannel(RGBA::ALPHA));
		}

		//////////////////////////////////////////////////////////////////
		void Renderer::render(Texture* texture)
		{
			SDL_RenderCopyExF(
				m_renderer,
				texture->getTexture(),
				nullptr,
				texture->getRect().getBase(),
				texture->getAngle(),
				nullptr, SDL_FLIP_NONE
			);
		}

		//////////////////////////////////////////////////////////////////
		void Renderer::fill(RectF& rect, const Color& color)
		{
			setRenderColor(color);
			SDL_RenderFillRectF(m_renderer, rect.getBase());
		}

		//////////////////////////////////////////////////////////////////
		void Renderer::setTarget(Texture* texture)
		{
			SDL_SetRenderTarget(m_renderer, !texture ? nullptr : texture->getTexture());
		}
	}
}