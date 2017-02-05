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
#include "WinsockWrapper.h"

using namespace std;

WinsockWrapper::WinsockWrapper()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "Windows Socket startup failed!" << endl;
		exit(1);
	}
	cout << "Windows Socket started" << endl;
}

WinsockWrapper::~WinsockWrapper()
{
	WSACleanup();
	cout << "Windows Socket shutdown" << endl;
}

