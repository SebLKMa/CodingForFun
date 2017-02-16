/*
 * Common.cpp
 *
 *  Created on: 15 Feb 2017
 *      Author: seblkma
 */
#include <string>
#include <iostream>
#include <exception>
#include "Common.h"

void Common::DebugMessage(const std::string& str)
{
#ifdef DEBUG
	std::cout << str << std::endl;
#endif
}

void Common::ErrorMessage(const std::string& str)
{
	std::cerr << str << std::endl;
}

bool Common::PortIsValid(const std::string& port)
{
	int checkPort{0};
	try
	{
		checkPort = std::stoi(port);
	}
	catch (const std::invalid_argument&)
	{
		Common::ErrorMessage("Port is invalid.");
		return false;
	}
	catch (const std::out_of_range&)
	{
		Common::ErrorMessage("Port number error.");
		return false;
	}

	if (checkPort <= 1024)
	{
		Common::ErrorMessage("Port number must be greater than 1024.");
		return false;
	}
	return true;
}

