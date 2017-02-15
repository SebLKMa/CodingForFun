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
#include "Common.h"
//#include <winsock2.h> // The dll libws2_32.a is found in (remove the prefix "lib" and ".o" in Libraries setting
//#include <WS2tcpip.h> // C:\msys64\mingw64\x86_64-w64-mingw32\lib

using namespace std;

bool keepRunning = true;
void SetRunning(const bool& run)
{
	keepRunning = run;
}

bool SendMessage(std::reference_wrapper<Socket> socketRef, const string& message)
{
	stringstream requestStream{ message } ;
	SSIZE_T result = socketRef.get().Send(move(requestStream)); // send request
	if (result == -1)
	{
		return false;
	}
	cout << "Message sent:" << message << endl;
	return true;
}

void ReceiveMessage(std::reference_wrapper<Socket> socketRef)
{
	cout << "ReceiveMessage starting" << endl;

	while (true)
	{
		stringstream responseStream{ socketRef.get().Receive() }; // wait for respond

		if (responseStream.rdbuf()->in_avail() == 0)
		{
			Common::ErrorMessage("Receive detected null stream. ReceiveMessage exiting...");
			break;
		}

		if (!socketRef.get().IsValid()) // socket could be closed by peer
		{
			Common::ErrorMessage("Receive socket invalid. ReceiveMessage exiting...");
			break;
		}

		string result;
		getline(responseStream, result, '\0'); // get the whole string from the stream
		cout << "Message received:" << result << endl;
		responseStream.clear();

	}
	cout << "ReceiveMessage completed" << endl;
}

std::vector<string> connectionStrings; // holds server connection strings
void StartProtocolClient()
{
	Common::DebugMessage("DEBUG StartProtocolClient");

	if (connectionStrings.size() == 0)
	{
		Common::ErrorMessage("Connection strings are empty.");
		return;
	}

	cout << "Enter message (format:\"<LicenceID> <Message>\") to send or \"quit\" to quit: " << endl;

	string address;
	string port;
	string connectionString;
	thread receiveThread;

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

		receiveThread = thread(ReceiveMessage, ref(connectingSocket));
		receiveThread.detach();

		string myString;
		while (true) // loop until "quit"
		{
			myString.clear();
			getline(cin, myString);
			if (myString == "quit")
			{
				cout << "Quiting..." << endl;
				SetRunning(false);
				break;
			}
			else
			{
				if (!SendMessage(ref(connectingSocket), myString))
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

	cout << endl << "Tschuess!" << endl;
	return 0;
}
