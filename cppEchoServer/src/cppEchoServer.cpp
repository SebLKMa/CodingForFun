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
#include "ProtocolTask.h"
//#include <winsock2.h> // The dll libws2_32.a is found in (remove the prefix "lib" and ".o" in Libraries setting
//#include <WS2tcpip.h> // C:\msys64\mingw64\x86_64-w64-mingw32\lib

using namespace std;
/*
namespace
{
	const int NUM_QUESTIONS{2};
	const array<string, NUM_QUESTIONS> QUESTIONS
	{
		"Pomerol is from?", "Malbec is from?"
	};
	const array<string, NUM_QUESTIONS> ANSWERS
	{
		"France", "Argentina"
	};
}

bool ProtocolTaskExecute(reference_wrapper<Socket> connectionSocketRef)
{
	Socket connectionSocket{ move(connectionSocketRef.get()) };
	int questionIndex{0};
	string messageReceived{""};
	while (messageReceived != "QUIT")
	{
		// this socket is used for both receive and send
		stringstream socketStream{ connectionSocket.Receive() };

		if (socketStream.rdbuf()->in_avail() == 0)
		{
			break;
		}

		socketStream >> messageReceived;
		//getline(socketStream, messageReceived, '\0');

		cout << "messageReceived: " << messageReceived << endl;

		stringstream outputStream;
		if (messageReceived == "QUESTION") // will send back current question if quiz not completed
		{
			if (questionIndex >= NUM_QUESTIONS)
			{
				outputStream << "FINISHED";
				connectionSocket.Send(move(outputStream)); // send message to client we are finished

				cout << "Protocol Task completed" << endl;
				break;
			}

			outputStream << QUESTIONS[questionIndex];
		}
		else if (messageReceived == "ANSWER") // will send back answer based previous currentQuestion sent
		{
			string answer;
			socketStream >> answer;
			if (answer == ANSWERS[questionIndex])
			{
				outputStream << "You are correct";
			}
			else
			{
				outputStream << "Sorry, the correct answer is " <<  ANSWERS[questionIndex];
			}
			++questionIndex;
		}
		else
		{
			outputStream << "Unrecognized message! - " << messageReceived;
		}

		connectionSocket.Send(move(outputStream));
	}

	cout << "ProtocolTask::Execute exiting" << endl;
	return true;
}
*/

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
/*
	int res = bindngSocket.SetBlockingMode(1);
	if (res != NO_ERROR)
	{
		cout << "SetBlockingMode failed with error: " << res << endl;
		return ;
	}
*/
	while (true) // calling thread loops, launches 1 thread per accepted socket from client
	{
		Socket acceptingSocket{ bindngSocket.Accept() };
		if (!acceptingSocket.IsValid())
		{
			break;
		}
		ProtocolTask task;
		//task.Execute(ref(acceptingSocket)); // comment out while-loop and below if to test in single-thread
		//async(launch::async, ProtocolTaskExecute, ref(acceptingSocket));
		async(launch::async, &ProtocolTask::Execute, &task, ref(acceptingSocket));
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



