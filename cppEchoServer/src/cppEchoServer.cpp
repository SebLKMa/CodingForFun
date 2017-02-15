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
#include "WinsockHelper.h"
#include "Socket.h"
#include "BaseTask.h"
#include "EchoTask.h"
#include "ProtocolTask.h"
#include "Common.h"
//#include "BaseTaskThread.h"
//#include "ProtocolTaskThread.h"
//#include <winsock2.h> // The dll libws2_32.a is found in (remove the prefix "lib" and ".o" in Libraries setting
//#include <WS2tcpip.h> // C:\msys64\mingw64\x86_64-w64-mingw32\lib

using namespace std;

void StartProtocolServerThread(string& port)
{
	WinsockHelper myWinsockHelper;

	string address{"localhost"}; // default
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

	while (true) // main thread loops, launches 1 thread per accepted socket from client
	{
		cout << "Accepting..." << endl;
		Socket acceptingSocket{ bindngSocket.Accept() };
		if (!acceptingSocket.IsValid())
		{
			Common::ErrorMessage("Accept failed. Invalid socket detected.");
			break;
		}

		cout << "Accepted socket handle: " << acceptingSocket.GetSocketHandleID() << endl;

		shared_ptr<BaseTask> pTask(new ProtocolTask(ref(acceptingSocket)));
		std::thread myThread(&BaseTask::Execute, pTask);
		myThread.detach();
	}
}

/**
 * Main entry point
 */
int main(int argc, char* argv[])
{
	// Check the number of command line arguments
	if (argc != 2) {
		// display Usage message
		std::cerr << "Usage: " << argv[0] << " <port>" << std::endl;
		std::cerr << "where <port> is the port number this process will accept requests on." << std::endl;
		return 1;
	}

	string port{argv[1]};
	StartProtocolServerThread(port);

	return 0;
}



