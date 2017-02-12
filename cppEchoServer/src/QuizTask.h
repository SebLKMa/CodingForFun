/*
 * Protocol.h
 *
 *  Created on: Feb 6, 2017
 *      Author: LMA
 */

#ifndef QUIZTASK_H_
#define QUIZTASK_H_

// forwards
class Socket;

class QuizTask
{
public:
	QuizTask() {}
	bool Execute(std::reference_wrapper<Socket> connectionSocketRef);
};

#endif /* QUIZTASK_H_ */
