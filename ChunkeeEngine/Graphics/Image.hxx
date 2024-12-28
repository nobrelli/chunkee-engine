#pragma once

#include "Texture.hxx"
#include "../Types.hxx"


namespace Chunkee
{
	namespace Graphics
	{
		class Image : public Texture
		{
		public:
			//////////////////////////////////////////////////////////////////
			Image(SurfaceBase* surface);
			Image(TextureBase* texture);
			~Image();

			//////////////////////////////////////////////////////////////////
			void setFileName(const String&&);
			//void render();

		private:
			String m_fileName;
		};
	}
}