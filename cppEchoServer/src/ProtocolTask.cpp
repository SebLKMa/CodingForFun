/*
 * ProtocolTask.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: LMA
 */
#include <sstream>
#include <iostream>
#include <array>
#include <functional> // for reference_wrapper
#include "ProtocolTask.h"
#include "Socket.h"

using namespace std;

const string QUIT{"QUIT"};

bool ProtocolTask::Execute(reference_wrapper<Socket> connectionSocketRef)
{
	Socket connectionSocket{ move(connectionSocketRef.get()) };

	// this socket is used for both receive and send
	stringstream inputStream{ connectionSocket.Receive() };
	if (inputStream.rdbuf()->in_avail() == 0)
	{
		return false;
	}

	string messageReceived;
	getline(inputStream, messageReceived, '\0');
	//socketStream >> messageReceived;

	cout << "Received message: " << messageReceived << endl;

	stringstream outputStream;
	outputStream << messageReceived;

	connectionSocket.Send(move(outputStream));

	cout << "ProtocolTask::Execute exiting" << endl;
	return true;
}



