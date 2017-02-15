/*
 * Protocol.h
 *
 *  Created on: Feb 6, 2017
 *      Author: LMA
 */

#ifndef PROTOCOLTASK_H_
#define PROTOCOLTASK_H_
#include "EchoTask.h"
#include "Socket.h"

/**
 * This task will receive messages based on the message string format:
 *     "<LicenceID> <Message>"
 */
class ProtocolTask : public virtual EchoTask
{
public:
	/**
	 * The constructor takes ownership of the socket reference.
	 * @connectionSocketRef The reference object of the Socket.
	 */
	ProtocolTask(std::reference_wrapper<Socket> connectionSocketRef);
	virtual ~ProtocolTask();

	/**
	 * Overrides EchoTask::Execute().
	 * Performs the socket receive and broadcast.
	 */
	bool Execute();
};

#endif /* PROTOCOLTASK_H_ */
