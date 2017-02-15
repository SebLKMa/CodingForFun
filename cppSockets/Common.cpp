/*
 * Common.cpp
 *
 *  Created on: 15 Feb 2017
 *      Author: likke
 */
#include <string>
#include <iostream>
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


