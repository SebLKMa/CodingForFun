/*
 * SessionsMap.h
 *
 *  Created on: 12 Feb 2017
 *      Author: likke
 */

#ifndef SESSIONS_H_
#define SESSIONS_H_
#include <map>
#include <string>
#include <functional> // for reference_wrapper
#include <mutex>
#include "Socket.h"

// alias typedefs
using SocketRef = std::reference_wrapper<Socket>;
using SessionPair = std::pair<std::string, SocketRef>;
using SessionsMap = std::map<std::string, SocketRef>;
using SessionsMapIter = std::map<std::string, SocketRef>::const_iterator;

/**
 * This class is a singleton holding connected licensed sessions.
 */
class Sessions
{
public:
	static Sessions& instance()
	{
		static Sessions s_Instance; // instantiated on first use, guaranteed to be destroyed
		return s_Instance;
	}

	~Sessions() {}

	Sessions(const Sessions& other) = delete; // no copy
	Sessions& operator=(const Sessions& other) = delete; // no assignment

	void Update(std::string licenceId, SocketRef);

	SocketRef GetSession(std::string licenceId);
	bool GetSession(std::string licenceId, SocketRef socketRef);

	void Broadcast(const std::string& message);

private:
	Sessions() {} // cannot be publicly instantiated

	SessionsMap m_Sessions; // holds a map of licensed IDs and their connected sockets.
	std::mutex m_SessionsMutex; // for locking m_Sessions
};

#endif /* SESSIONS_H_ */
