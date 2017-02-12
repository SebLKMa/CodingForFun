/*
 * ProtocolTask.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: LMA
 */
#include <sstream>
#include <iostream>
#include <functional> // for reference_wrapper
#include "EchoTask.h"
#include "ProtocolTask.h"
#include "Socket.h"
#include "Sessions.h"

using namespace std;

const string QUIT{"QUIT"};

ProtocolTask::ProtocolTask(std::reference_wrapper<Socket> connectionSocketRef)
	: EchoTask(connectionSocketRef)
{
	//Sessions::instance().Update("42", connectionSocketRef);
}

bool ProtocolTask::Execute()
{


	// this socket is used for both receive and send
	//Socket connectionSocket{ move(connectionSocketRef.get()) };
	//reference_wrapper<Socket> socketRef = Sessions::instance().GetSession("42");
	//Socket sessionSocket{move(socketRef.get())};

	stringstream inputStream{ m_Socket.Receive() };
	if (inputStream.rdbuf()->in_avail() == 0)
	{
		return false;
	}

	//string messageReceived;
	//getline(inputStream, messageReceived, '\0'); // get whole input stream until null-terminator
	string licenceId;
	inputStream >> licenceId;

	//cout
	//	<< "Socket handle ID: " << sessionSocket.GetSocketHandleID()
	//	<< ", Received message: " << messageReceived << endl;
	cout << "Licence ID: " << licenceId << endl;

	string messageReceived;
	inputStream >> messageReceived;
	cout << "Message: " << messageReceived << endl;
/*
	stringstream outputStream;
	outputStream << messageReceived;

	m_Socket.Send(move(outputStream));
*/
	Sessions::instance().Update(licenceId, ref(m_Socket));
	Sessions::instance().Broadcast(messageReceived);

	cout << "ProtocolTask::Execute exiting" << endl;
	return true;
}



