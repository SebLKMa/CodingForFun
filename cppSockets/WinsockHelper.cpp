/*
 * WinsockWrapper.cpp

 *
 *  Created on: 15 Feb 2017
 *      Author: seblkma
 */
#include <iostream>
//#include <type_traits>
//#include <vector>
//#include <sstream> // for debugging
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "WinsockHelper.h"
#include "Common.h"

using namespace std;

WinsockHelper::WinsockHelper()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		Common::ErrorMessage("Windows Socket startup failed!");
		exit(1);
	}
	Common::DebugMessage("Windows Socket started");
}

WinsockHelper::~WinsockHelper()
{
	WSACleanup();
	Common::DebugMessage("Windows Socket shutdown");
}

