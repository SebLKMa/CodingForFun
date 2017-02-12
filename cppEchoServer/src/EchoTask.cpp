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
#include "EchoTask.h"
#include "Socket.h"

using namespace std;

EchoTask::EchoTask(std::reference_wrapper<Socket> connectionSocketRef)
	: m_Socket{ move(connectionSocketRef.get()) }
{
}

bool EchoTask::Execute()
{
	//Socket connectionSocket{ move(connectionSocketRef.get()) };

	// this socket is used for both receive and send
	stringstream inputStream{ m_Socket.Receive() };
	if (inputStream.rdbuf()->in_avail() == 0)
	{
		return false;
	}

	string messageReceived;
	getline(inputStream, messageReceived, '\0');
	//socketStream >> messageReceived;

	cout
		<< "Socket handle ID: " << m_Socket.GetSocketHandleID()
		<< ", Received message: " << messageReceived << endl;

	stringstream outputStream;
	outputStream << messageReceived;

	m_Socket.Send(move(outputStream));

	cout << "EchoTask::Execute exiting" << endl;
	return true;
}



