#pragma once

#include <mutex>
#include "../Graphics/Image.hxx"
#include "../Types.hxx"


namespace Chunkee
{
	using Graphics::Image;

	//////////////////////////////////////////////////////////////////
	enum class ImageType
	{
		BMP, JPG, PNG
	};

	//////////////////////////////////////////////////////////////////
	class ImageServer
	{
	public:
		//////////////////////////////////////////////////////////////////
		static ImageServer* getInstance();

		//////////////////////////////////////////////////////////////////
		void cleanup();

		//////////////////////////////////////////////////////////////////
		ImageServer(const ImageServer&) = delete;
		void operator=(const ImageServer&) = delete;

		//////////////////////////////////////////////////////////////////
		void load(ImageType type,
				  const String& fileName,
				  const String& id);

		//////////////////////////////////////////////////////////////////
		Image* getItem(const String& id) const;

	private:
		ImageServer();
		~ImageServer();

	private:
		static ImageServer* m_instance;
		static std::mutex m_mutex;

		UMap<String, Image*> m_images;
	};
}