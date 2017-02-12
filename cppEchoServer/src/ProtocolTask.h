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

// forwards
//class Socket;

class ProtocolTask : public virtual EchoTask
{
public:
	ProtocolTask(std::reference_wrapper<Socket> connectionSocketRef);
	virtual ~ProtocolTask() {}

	/**
	 * Implements BaseTask::Execute().
	 */
	bool Execute();
};

#endif /* PROTOCOLTASK_H_ */
