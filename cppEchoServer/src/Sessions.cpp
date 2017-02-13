/*
 * Sessions.cpp
 *
 *  Created on: 12 Feb 2017
 *      Author: likke
 */
#include <iostream>
#include <sstream>
#include "Sessions.h"

using namespace std;

Sessions::~Sessions()
{
	/*
	for (auto const& entry : m_Sessions)
	{
		cout << "Sessions::Broadcast attempt to " << entry.first << endl;
		if (entry.second.get().IsValid())
		{

			entry.second.get().Close();
		}
	}
	*/
	m_Sessions.clear();
}

void Sessions::Update(std::string licenceId, SocketRef socketRef)
{
	lock_guard<mutex> myGuard(m_SessionsMutex);

	//_Sessions[id] = move(socketRef.get());
	//m_Sessions.emplace(licenceId, move(socketRef));
	m_Sessions.emplace(licenceId, socketRef);
	cout << "Sessions::Update session Id - " << licenceId << endl;
}

SocketRef Sessions::GetSession(std::string licenceId)
{
	lock_guard<mutex> myGuard(m_SessionsMutex);

	SessionsMapIter it = m_Sessions.find(licenceId);
	if (it != m_Sessions.end())
	{
		//return it->second.get();
		cout << "Sessions::GetSession Id - " << licenceId << endl;
	}
	return ref(it->second.get());
}

bool Sessions::GetSession(std::string licenceId, SocketRef socketRef)
{
	lock_guard<mutex> myGuard(m_SessionsMutex);

	SessionsMapIter it = m_Sessions.find(licenceId);
	if (it != m_Sessions.end())
	{
		socketRef = ref(it->second.get());
		return true;
	}
	return false;
}

void Sessions::Broadcast(const std::string& message)
{
	lock_guard<mutex> myGuard(m_SessionsMutex);

	for (auto const& entry : m_Sessions)
	{
		//Socket sessionSocket{move(entry.second.get())};
		cout << "Sessions::Broadcast attempt to " << entry.first << endl;
		if (entry.second.get().IsValid())
		{
			stringstream outputStream;
			outputStream << message;
			cout << "Sessions::Broadcast sending " << entry.first << " " << message << endl;
			entry.second.get().Send(move(outputStream));
			//entry.second.get().ShutdownSend();
		}
		else
		{
			cout << "Sessions::Broadcast Invalid socket " << entry.first << endl;
		}
	}
}
