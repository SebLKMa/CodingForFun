/*
 * BaseTaskThread.h
 *
 *  Created on: Feb 14, 2017
 *      Author: LMA
 */

#ifndef BASETASKTHREAD_H_
#define BASETASKTHREAD_H_

/**
 *
 * Using template method design pattern, this class represents a task
 * to be executed in an independent thread.
 */
class BaseTaskThread
{
public:
	BaseTaskThread() {}
	virtual ~BaseTaskThread() {}

	/**
	 * This function will be DoExecute() function in a detached thread.
	 */
	void Execute();

protected:

	/**
	 * To be implemented by derived class.
	 */
	virtual bool DoExecute() = 0;

};

#endif /* BASETASKTHREAD_H_ */
