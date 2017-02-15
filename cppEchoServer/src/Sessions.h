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
	/**
	 * Singleton instance accessor.
	 */
	static Sessions& instance()
	{
		static Sessions s_Instance; // instantiated on first use, guaranteed to be destroyed
		return s_Instance;
	}

	~Sessions();

	Sessions(const Sessions& other) = delete; // no copy
	Sessions& operator=(const Sessions& other) = delete; // no assignment

	/**
	 * Update sessions. If licenceId not found, entry will be added.
	 * @licenceId The ID as key
	 * @socketRef The reference object of the Socket.
	 */
	void Update(std::string licenceId, SocketRef socketRef);

	/**
	 * Broadcast the message to all connected licenced sockets.
	 * #message The message to send.
	 */
	void Broadcast(const std::string& message);

private:
	Sessions() {} // cannot be publicly instantiated

	SocketRef GetSession(std::string licenceId);
	bool GetSession(std::string licenceId, SocketRef socketRef);

	SessionsMap m_Sessions; // holds a map of licensed IDs and their connected sockets.
	std::mutex m_SessionsMutex; // for locking m_Sessions
};

#endif /* SESSIONS_H_ */
