#include "Image.hxx"
#include "../Logger.hxx"
#include "../Graphics/Renderer.hxx"


namespace Chunkee
{
	namespace Graphics
	{
		using Graphics::Renderer;

		//////////////////////////////////////////////////////////////////
		Image::Image(SurfaceBase* surface) : Texture(surface)
		{
			Logger::log("Image created");
		}

		//////////////////////////////////////////////////////////////////
		Image::Image(TextureBase* texture)
		{
			setTexture(texture);
		
			Logger::log("Image created");
		}

		//////////////////////////////////////////////////////////////////
		Image::~Image()
		{
			SDL_DestroyTexture(m_texture);
			m_texture = nullptr;

			Logger::log("Image destroyed");
		}

		//////////////////////////////////////////////////////////////////
		void Image::setFileName(const String&& fileName)
		{
			m_fileName = fileName;
		}
	}
}