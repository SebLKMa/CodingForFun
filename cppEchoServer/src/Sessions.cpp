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

void Sessions::Update(std::string licenceId, SocketRef socketRef)
{
	//_Sessions[id] = move(socketRef.get());
	m_Sessions.emplace(licenceId, move(socketRef));
	cout << "Sessions::Update session Id - " << licenceId << endl;
}

SocketRef Sessions::GetSession(std::string licenceId)
{
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
	for (auto const& entry : m_Sessions)
	{
		//Socket sessionSocket{move(entry.second.get())};
		cout << "Sessions::Broadcast attempt to " << entry.first << endl;
		if (entry.second.get().IsValid())
		{
			stringstream outputStream;
			outputStream << message;
			entry.second.get().Send(move(outputStream));
			cout << "Sessions::Broadcast sending " << entry.first << " " << message << endl;
		}
		else
		{
			cout << "Sessions::Broadcast Invalid socket " << entry.first << endl;
		}
	}
}
