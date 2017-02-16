/*
 * ProtocolTask.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: LMA
 */
#include <sstream>
#include <iostream>
#include <functional> // for reference_wrapper
#include <exception>
#include "EchoTask.h"
#include "ProtocolTask.h"
#include "Socket.h"
#include "Sessions.h"
#include "Common.h"

using namespace std;

ProtocolTask::~ProtocolTask()
{
	Common::DebugMessage("ProtocolTask::~ProtocolTask()");
	m_Socket.Close();
}

ProtocolTask::ProtocolTask(std::reference_wrapper<Socket> connectionSocketRef)
	: EchoTask(connectionSocketRef)
{
}

bool ProtocolTask::Execute()
{
	Common::DebugMessage("ProtocolTask::Execute entering");
	try
	{
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

			inputStream >> messageReceived; // get next string until white-space

			// Broadcast the received message if licenceId is valid
			if (!licenceId.empty() && !messageReceived.empty())
			{
				Sessions::instance().Update(licenceId, ref(m_Socket));
				Sessions::instance().Broadcast(messageReceived);
			}
		}
	}
	catch (const std::exception& ex)
	{
		Common::ErrorMessage(ex.what());
		return false;
	}

	Common::DebugMessage("ProtocolTask::Execute exiting");
	return true;
}



