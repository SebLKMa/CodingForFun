//============================================================================
// Name        : cppEchoServer.cpp
// Author      : seblkma
// Version     :
// Copyright   : copyright(c) seblkma
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <winsock2.h> // The dll libws2_32.a is found in (remove the prefix "lib" and ".o" in Libraries setting
#include <WS2tcpip.h> // C:\msys64\mingw64\x86_64-w64-mingw32\lib
#include <Hello.h>

using namespace std;


void firstConnection()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "Windows Socket startup failed!" << endl;
		return;
	}

	addrinfo hints{};
	hints.ai_family = AF_UNSPEC; // regardless of IPv4 or IPv6
	hints.ai_socktype = SOCK_STREAM; // TCP stream sockets

	// prepare to connect
	addrinfo* pServerInfo{};
	getaddrinfo("localhost", "80", &hints, &pServerInfo);

	SOCKET sockfd{ socket(pServerInfo->ai_family, pServerInfo->ai_socktype, pServerInfo->ai_protocol) };
	int connectionResult{ connect(sockfd, pServerInfo->ai_addr, pServerInfo->ai_addrlen) };
	if (connectionResult == -1)
	{
		cout << "First connection failed!" << endl;
	}
	else
	{
		cout << "First connection successful!" << endl;
	}

	freeaddrinfo(pServerInfo);
	WSACleanup();
}

int main(int argc, char* argv[])
{
	//NOTE: remove the prefix "lib" if your DLL name starts with lib...
	//NOTE: the location of DLL has to be in your runtime search PATH
	//See:
	//http://eclipsesource.com/blogs/2010/03/03/shared-libraries-with-eclipse-cdt-and-cygwin-on-windows/
	//https://tayefeh.wordpress.com/2009/07/06/creating-and-using-a-c-shared-library-with-eclipse-cdt-galileo-and-gnu-c-compiler-and-linker/

    //Hello myHello;
    //const string me{"Seb"};
    //string greetings = myHello.getHello(me);

	//cout << greetings << endl;

	firstConnection();

	return 0;
}



