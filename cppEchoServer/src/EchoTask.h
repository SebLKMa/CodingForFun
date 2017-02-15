/*
 * Protocol.h
 *
 *  Created on: Feb 6, 2017
 *      Author: LMA
 */

#ifndef ECHOTASK_H_
#define ECHOTASK_H_
#include "BaseTask.h"
#include "Socket.h"

// forwards
//class Socket;

/**
 * This task merely performs a echo message back to the same socket connection.
 * This class takes ownership of the socket reference.
 */
class EchoTask : public virtual BaseTask
{
public:
	/**
	 * The constructor takes ownership of the socket reference.
	 * @connectionSocketRef The reference object of the Socket.
	 */
	EchoTask(std::reference_wrapper<Socket> connectionSocketRef);
	virtual ~EchoTask() {}

	/**
	 * Implements BaseTask::Execute().
	 * Performs the socket receive and sends echo.
	 */
	bool Execute();

protected:
	// TODO:
	// implement Socket copy ctor and assignment
	// then make this private and provide getter
	Socket m_Socket;
};

#endif /* ECHOTASK_H_ */
