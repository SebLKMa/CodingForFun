/*
 * WinsockWrapper.cpp

 *
 *  Created on: 5 Feb 2017
 *      Author: likke
 */
#include <iostream>
//#include <type_traits>
//#include <vector>
//#include <sstream> // for debugging
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "WinsockHelper.h"

using namespace std;

WinsockHelper::WinsockHelper()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "Windows Socket startup failed!" << endl;
		exit(1);
	}
	cout << "Windows Socket started" << endl;
}

WinsockHelper::~WinsockHelper()
{
	WSACleanup();
	cout << "Windows Socket shutdown" << endl;
}

