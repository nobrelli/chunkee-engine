#include "Texture.hxx"
#include "Renderer.hxx"
#include "../Window.hxx"


namespace Chunkee
{
	namespace Graphics
	{
		using Graphics::Renderer;

		//////////////////////////////////////////////////////////////////
		Texture::Texture(bool create) : m_texture(nullptr)
		{
			if (create)
			{
				m_texture = SDL_CreateTexture(Renderer::getInstance()->getBase(),
											  SDL_PIXELFORMAT_RGBA8888,
											  SDL_TEXTUREACCESS_TARGET,
											  Window::getInstance()->getProperties().size.getX(),
											  Window::getInstance()->getProperties().size.getY());
			}
		}

		//////////////////////////////////////////////////////////////////
		Texture::Texture(SurfaceBase* surface)
		{
			convertSurface(surface);
		}

		//////////////////////////////////////////////////////////////////
		Texture::~Texture()
		{
			if (m_texture)
			{
				SDL_DestroyTexture(m_texture);
				m_texture = nullptr;
			}
		}

		//////////////////////////////////////////////////////////////////
		void Texture::convertSurface(SurfaceBase* surface)
		{
			auto renderer = Renderer::getInstance()->getBase();
			setTexture(SDL_CreateTextureFromSurface(renderer, surface));
			SDL_FreeSurface(surface);
			surface = nullptr;
		}

		//////////////////////////////////////////////////////////////////
		void Texture::setTexture(TextureBase* texture)
		{
			m_texture = texture;
			
			int x, y;
			if (!SDL_QueryTexture(m_texture, nullptr, nullptr, &x, &y))
				m_rect.setSize(x, y);
		}

		//////////////////////////////////////////////////////////////////
		TextureBase* Texture::getTexture() const
		{
			return m_texture;
		}
	}
}