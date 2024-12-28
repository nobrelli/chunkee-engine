#pragma once

#include <SDL_render.h>
#include "../Nodes/Transformable.hxx"


namespace Chunkee
{
	namespace Graphics
	{
		using TextureBase = SDL_Texture;
		using SurfaceBase = SDL_Surface;

		class Texture : public Transformable
		{
		public:
			//////////////////////////////////////////////////////////////////
			Texture(bool create = false);
			Texture(SurfaceBase* surface);
			~Texture();

			//////////////////////////////////////////////////////////////////
			Texture(const Texture&) = delete;
			void operator=(const Texture&) = delete;

			//////////////////////////////////////////////////////////////////
			void convertSurface(SurfaceBase* surface);
			void setTexture(TextureBase* texture);

			//////////////////////////////////////////////////////////////////
			TextureBase* getTexture() const;

		protected:
			TextureBase* m_texture;
		};
	}
}