//============================================================================
// Name        : cppEchoServer.cpp
// Author      : seblkma
// Version     :
// Copyright   : copyright(c) seblkma
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <future>
#include <Hello.h>
#include "WinsockHelper.h"
#include "Socket.h"
#include "BaseTask.h"
#include "EchoTask.h"
#include "ProtocolTask.h"
//#include <winsock2.h> // The dll libws2_32.a is found in (remove the prefix "lib" and ".o" in Libraries setting
//#include <WS2tcpip.h> // C:\msys64\mingw64\x86_64-w64-mingw32\lib

using namespace std;

void StartProtocolServerThread()
{
	WinsockHelper myWinsockHelper;

	string address{"localhost"};
	string port{"3000"};
	Socket bindngSocket(address, port);
	int bindResult{bindngSocket.Bind()};
	if (bindResult == -1)
	{
		return;
	}
	int listenResult{ bindngSocket.Listen(5) };
	if (listenResult == -1)
	{
		return;
	}

	while (true) // calling thread loops, launches 1 thread per accepted socket from client
	{
		Socket acceptingSocket{ bindngSocket.Accept() };
		if (!acceptingSocket.IsValid())
		{
			break;
		}

		cout << "Accepted socket handle: " << acceptingSocket.GetSocketHandleID() << endl;

		ProtocolTask task{ref(acceptingSocket)};
		//shared_ptr<ProtocolTask> pTask(new ProtocolTask);
		//task.Execute(ref(acceptingSocket)); // comment out while-loop and below if to test in single-thread
		//async(launch::async, ProtocolTaskExecute, ref(acceptingSocket));
		async(launch::async, &BaseTask::Execute, &task);

		// See:
		// https://www.codeproject.com/Articles/412511/Simple-client-server-network-using-Cplusplus-and-W
		// http://stackoverflow.com/questions/15382316/where-does-winsock-store-ip-address-of-a-socket
		// http://stackoverflow.com/questions/26454836/winsock2-c-multiple-sockets-stored-as-one
        // https://www.codeproject.com/Articles/4016/Server-Client-Sockets
		// https://www.codeproject.com/Articles/2477/Multi-threaded-Client-Server-Socket-Class
		// http://www.dreamincode.net/forums/topic/228484-server-broadcasting-message-to-all-clients-vs-c/

	}
}

void StartServer()
{
	WinsockHelper myWinsockHelper;

	string address{"localhost"};
	string port{"3000"};
	Socket bindngSocket(address, port);
	bindngSocket.Bind();

	int listenResult{ bindngSocket.Listen(5) };
	if (listenResult == -1)
	{
		return;
	}

	Socket acceptingSocket{ bindngSocket.Accept() };
	if (!acceptingSocket.IsValid())
	{
		return;
	}

	stringstream dataReceived{ acceptingSocket.Receive() };
	string messageReceived;
	getline(dataReceived, messageReceived, '\0');

	cout << "Received message: " << messageReceived << endl;
}

void sayHello()
{
    Hello myHello;
    const string me{"Seb"};
    string greetings = myHello.getHello(me);
	cout << greetings << endl;
}

/*
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
*/

/**
	NOTE:
	remove the prefix "lib" if your DLL name starts with lib...
	the location of DLL has to be in your runtime search PATH
	See:
	http://eclipsesource.com/blogs/2010/03/03/shared-libraries-with-eclipse-cdt-and-cygwin-on-windows/
	https://tayefeh.wordpress.com/2009/07/06/creating-and-using-a-c-shared-library-with-eclipse-cdt-galileo-and-gnu-c-compiler-and-linker/
 */
int main(int argc, char* argv[])
{
	//sayHello();
	//firstConnection();
	//StartServer();
	StartProtocolServerThread();

	return 0;
}



