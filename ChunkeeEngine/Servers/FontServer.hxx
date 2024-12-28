#pragma once

#include <mutex>
#include "../Graphics/Font.hxx"
#include "../Types.hxx"


namespace Chunkee
{
	using Graphics::Font;

	class FontServer
	{
	public:
		//////////////////////////////////////////////////////////////////
		static FontServer* getInstance();

		//////////////////////////////////////////////////////////////////
		void cleanup();

		//////////////////////////////////////////////////////////////////
		FontServer(const FontServer&) = delete;
		void operator=(const FontServer&) = delete;

		//////////////////////////////////////////////////////////////////
		void load(const String& fileName,
				  int fontSize,
				  const String& id);

		//////////////////////////////////////////////////////////////////
		Font* getItem(const String& id) const;

	private:
		FontServer();
		~FontServer();

	private:
		static FontServer* m_instance;
		static std::mutex m_mutex;

		UMap<String, Font*> m_fonts;
	};
}