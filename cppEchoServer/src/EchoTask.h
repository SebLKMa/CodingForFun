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

class EchoTask : public virtual BaseTask
{
public:
	EchoTask(std::reference_wrapper<Socket> connectionSocketRef);
	virtual ~EchoTask() {}

	/**
	 * Implements BaseTask::Execute().
	 */
	bool Execute();

protected:
	// TODO:
	// implement Socket copy ctor and assignment
	// then make this private and provide getter
	Socket m_Socket;
};

#endif /* ECHOTASK_H_ */
