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
#include <vector>
#include <functional> // for reference_wrapper
#include "WinsockHelper.h"
#include "Socket.h"
//#include <winsock2.h> // The dll libws2_32.a is found in (remove the prefix "lib" and ".o" in Libraries setting
//#include <WS2tcpip.h> // C:\msys64\mingw64\x86_64-w64-mingw32\lib

using namespace std;

bool keepRunning = true;
void SetRunning(const bool& run)
{
	keepRunning = run;
}

bool SendString(std::reference_wrapper<Socket> socketRef, const string& message)
{
	stringstream requestStream{ message } ;
	SSIZE_T result = socketRef.get().Send(move(requestStream)); // send request
	if (result == -1)
	{
		return false;
	}
	return true;
}

void ReceiveString(std::reference_wrapper<Socket> socketRef)
{
	cout << "ReceiveString starting" << endl;
	//socketRef.get().SetBlockingMode(1);
	//for (int i=0; i<2; i++)
	while (true)
	{
		stringstream responseStream{ socketRef.get().Receive() }; // wait for respond

		// TODO: detect disconnection

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

std::vector<string> connectionStrings;
void StartProtocolClient()
{
	if (connectionStrings.size() == 0)
	{
		cout << "Connection strings are emoty." << endl;
		return;
	}

	string address;
	string port;
	string connectionString;

	//async(launch::async, &ReceiveString, ref(connectingSocket));
	std::thread myThread;

	vector<string>::iterator connectionsIter = connectionStrings.begin();
	while (keepRunning)
	{
		connectionString = (*connectionsIter);//connectionStrings[0];
		istringstream stream(connectionString);
		getline(stream, address, ':');
		getline(stream, port, ':');

		if (address.empty() || port.empty())
		{
			cout << "connection string error" << endl;
			return;
		}

		WinsockHelper myWinsockHelper;
		Socket connectingSocket(address, port);
		int connectionResult{ connectingSocket.Connect() };
		if (connectionResult == -1)
		{
			return;
		}


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
				SetRunning(false);
				break;
			}
			else
			{
				if (!SendString(ref(connectingSocket), myString))
				{
					break; // break for next connection
				}
			}
		}

		++connectionsIter;
		if (connectionsIter == connectionStrings.end())
		{
			connectionsIter = connectionStrings.begin(); // round-robin
		}
	}

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
	if (argc != 3) {
		// display Usage message
		std::cerr << "Usage: " << argv[0] << " <server1 Hostname:port> <sserer2 Hostname:port>" << std::endl;
		return 1;
	}

	connectionStrings.push_back(argv[1]);
	connectionStrings.push_back(argv[2]);
	StartProtocolClient();

	/*
	else
	{
		//StartConnect();
		//StartClient();
		StartProtocolClient();
		//StartQuizClient();
	}
	*/
	return 0;
}
