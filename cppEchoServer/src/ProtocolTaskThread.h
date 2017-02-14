/*
 * ProtocolTaskThread.h
 *
 *  Created on: Feb 14, 2017
 *      Author: LMA
 */

#ifndef PROTOCOLTASKTHREAD_H_
#define PROTOCOLTASKTHREAD_H_
#include "BaseTaskThread.h"
#include "Socket.h"

class ProtocolTaskThread : public virtual BaseTaskThread
{
public:
	ProtocolTaskThread(std::reference_wrapper<Socket> connectionSocketRef);
	virtual ~ProtocolTaskThread();

protected:
	/**
	 * Implements BaseTaskThread::DoExecute().
	 */
	bool DoExecute();

private:
	Socket m_Socket;
};




#endif /* PROTOCOLTASKTHREAD_H_ */
