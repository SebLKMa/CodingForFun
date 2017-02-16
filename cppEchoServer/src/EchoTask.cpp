/*
 * ProtocolTask.cpp
 *
 *  Created on: 15 Feb 2017
 *      Author: seblkma
 */
#include <sstream>
#include <iostream>
#include <array>
#include <functional> // for reference_wrapper
#include "EchoTask.h"
#include "Socket.h"
#include "Common.h"

using namespace std;

EchoTask::EchoTask(std::reference_wrapper<Socket> connectionSocketRef)
	: m_Socket{ move(connectionSocketRef.get()) }
{
}

bool EchoTask::Execute()
{
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

	Common::DebugMessage("EchoTask::Execute exiting");
	return true;
}



