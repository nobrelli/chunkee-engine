#pragma once

#include <iostream>
#include <format>


class Logger
{
public:
	static void log(const std::string& message)
	{
		std::cout << message << std::endl;
	}
};