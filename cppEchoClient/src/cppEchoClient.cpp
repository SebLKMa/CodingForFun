//============================================================================
// Name        : cppEchoClient.cpp
// Author      : seblkma
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <future> // for async
#include <functional> // for reference_wrapper
#include "WinsockHelper.h"
#include "Socket.h"
//#include <winsock2.h> // The dll libws2_32.a is found in (remove the prefix "lib" and ".o" in Libraries setting
//#include <WS2tcpip.h> // C:\msys64\mingw64\x86_64-w64-mingw32\lib

using namespace std;

void SendString(std::reference_wrapper<Socket> socketRef, const string& message)
{
	/*
	string wait;
	cout << "wait send...";
	cin >> wait;
    */

	stringstream requestStream{ message } ;
	socketRef.get().Send(move(requestStream)); // send request

	//socketRef.get().ShutdownSend();

	/*
	cout << "wait receive...";
	cin >> wait;

	while (wait != "quit")
	{
		stringstream responseStream{ connectingSocket.Receive() }; // wait for respond
		if (responseStream.rdbuf()->in_avail() > 0)
		{
			string result;
			getline(responseStream, result, '\0');
			cout << result << endl;
			break;
		}
	}
	*/
}

void ReceiveString(std::reference_wrapper<Socket> socketRef)
{
	cout << "ReceiveString starting" << endl;
	//socketRef.get().SetBlockingMode(1);
	//for (int i=0; i<2; i++)
	while (true)
	{
		stringstream responseStream{ socketRef.get().Receive() }; // wait for respond

		if (responseStream.rdbuf()->in_avail() == 0)
		{
			break;
		}

		if (!socketRef.get().IsValid()) // socket could be closed by peer
		{
			break;
		}

		string result;
		getline(responseStream, result, '\0');
		cout << result << endl;
		responseStream.clear();

	}
	cout << "ReceiveString completed" << endl;
}

void StartProtocolClient()
{
	WinsockHelper myWinsockHelper;

	string address{"localhost"};
	string port{"3000"};
	Socket connectingSocket(address, port);
	int connectionResult{ connectingSocket.Connect() };
	if (connectionResult == -1)
	{
		return;
	}

	//async(launch::async, &ReceiveString, ref(connectingSocket));
	std::thread myThread;
	myThread = std::thread(ReceiveString, ref(connectingSocket));
	myThread.detach();

	string myString;
	while (true)
	{
		myString.clear();
		cout << "Message to send: ";
		getline(cin, myString);
		if (myString == "quit")
		{
			cout << "Quiting..." << endl;
			break;
		}
		else
		{
			SendString(ref(connectingSocket), myString);
		}
	}

	//connectingSocket.Close();
}

void StartQuizClient()
{
	WinsockHelper myWinsockHelper;

	string address{"localhost"};
	string port{"3000"};
	Socket connectingSocket(address, port);
	int connectionResult{ connectingSocket.Connect() };
	if (connectionResult == -1)
	{
		return;
	}

	stringstream requestStream{ "QUESTION" } ;
	connectingSocket.Send(move(requestStream)); // send request for QUESTION

	stringstream responseStream{ connectingSocket.Receive() }; // wait for respond
	if (responseStream.rdbuf()->in_avail() > 0)
	{
		string question;
		getline(responseStream, question, '\0');
		responseStream.clear();

		while (question != "FINISHED")
		{
			cout << question << endl;

			string answer;
			cin >> answer;

			requestStream << "ANSWER ";
			requestStream << answer;
			connectingSocket.Send(move(requestStream)); // send ANSWER in request

			responseStream = connectingSocket.Receive(); // wait for respond
			if (responseStream.rdbuf()->in_avail() == 0)
			{
				break;
			}

			string result;
			getline(responseStream, result, '\0');
			cout << result << endl;

			//requestStream << "QUIT";
			requestStream << "QUESTION";
			connectingSocket.Send(move(requestStream)); // send request for next QUESTION

			responseStream = connectingSocket.Receive(); // wait for respond
			getline(responseStream, question, '\0');
			responseStream.clear();
		}
	}
}

void StartClient()
{
	WinsockHelper myWinsockHelper;

	string address{"localhost"};
	string port{"3000"};
	Socket connectingSocket(address, port);
	connectingSocket.Connect();

	string messageSent{"Beauty is only skin deep."};
	stringstream dataSent;
	dataSent << messageSent;
	connectingSocket.Send(move(dataSent));

	cout << "Sent message." << endl;
}

void StartConnect()
{
	WinsockHelper myWinsockHelper;

	string address{"localhost"};
	string port{"3000"};
	Socket connectingSocket(address, port);
	connectingSocket.Connect();
	connectingSocket.Close();

	string myString;
	cout << "Waiting...";
	getline(cin, myString);

}

int main(int argc, char* argv[])
{
	// Check the number of command line arguments
	if (argc == 2)
	{
		//SendString(argv[1]);
	}
	else
	{
		//StartConnect();
		//StartClient();
		StartProtocolClient();
		//StartQuizClient();
	}
	return 0;
}
