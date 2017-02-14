/*
 * ProtocolTaskThread.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: LMA
 */
#include <sstream>
#include <iostream>
#include <functional> // for reference_wrapper
#include "ProtocolTaskThread.h"
#include "Sessions.h"

using namespace std;

ProtocolTaskThread::ProtocolTaskThread(std::reference_wrapper<Socket> connectionSocketRef)
	: m_Socket{ move(connectionSocketRef.get()) }
{
}

ProtocolTaskThread::~ProtocolTaskThread()
{
	cout << "ProtocolTaskThread::~ProtocolTaskThread()" << endl;
	m_Socket.Close();
}


bool ProtocolTaskThread::DoExecute()
{
	cout << "rotocolTaskThread::DoExecute entering" << endl;

	// this socket is used for both receive and send
	//Socket connectionSocket{ move(connectionSocketRef.get()) };
	//reference_wrapper<Socket> socketRef = Sessions::instance().GetSession("42");
	//Socket sessionSocket{move(socketRef.get())};

	string licenceId;
	string messageReceived;
	while (true)
	{
		licenceId.clear();
		messageReceived.clear();

		stringstream inputStream{ m_Socket.Receive() };
		if (inputStream.rdbuf()->in_avail() == 0)
		{
			break;
		}

		if (!m_Socket.IsValid())
		{
			break;
		}

		//string messageReceived;
		//getline(inputStream, messageReceived, '\0'); // get whole input stream until null-terminator

		inputStream >> licenceId; // get first string until white-space

		//cout << "Licence ID: " << licenceId << endl;
		//cout << "Licence ID: " << licenceId.length() << endl;

		inputStream >> messageReceived; // get next string until white-space
		//cout << "Message: " << messageReceived << endl;
		//cout << "Message: " << messageReceived.length() << endl;

		if (!licenceId.empty() && !messageReceived.empty())
		{
			Sessions::instance().Update(licenceId, ref(m_Socket));
			Sessions::instance().Broadcast(messageReceived);
			//break;
		}
	}

	cout << "rotocolTaskThread::DoExecute exiting" << endl;
	return true;
}
