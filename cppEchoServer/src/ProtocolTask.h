/*
 * Protocol.h
 *
 *  Created on: Feb 6, 2017
 *      Author: LMA
 */

#ifndef PROTOCOLTASK_H_
#define PROTOCOLTASK_H_

// forwards
class Socket;

class ProtocolTask
{
public:
	ProtocolTask() {}
	bool Execute(std::reference_wrapper<Socket> connectionSocketRef);
};

#endif /* PROTOCOLTASK_H_ */
