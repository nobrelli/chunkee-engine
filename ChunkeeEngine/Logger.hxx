#pragma once

#include <iostream>
#include <stdexcept>
#include <format>


namespace Chunkee
{
	class Logger
	{
	public:
		//////////////////////////////////////////////////////////////////
		static void log(const std::string&& message)
		{
		#ifdef _DEBUG
			std::cout << message << std::endl;
		#endif
		}

		//////////////////////////////////////////////////////////////////
		static void logException(const std::string&& message)
		{
		#ifdef _DEBUG
			throw std::runtime_error(message);
		#endif
		}
	};
}