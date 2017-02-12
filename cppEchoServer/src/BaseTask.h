/*
 * BaseTask.h
 *
 *  Created on: 12 Feb 2017
 *      Author: likke
 */

#ifndef BASETASK_H_
#define BASETASK_H_

/**
 * Abstract class representing a Task to be executed.
 */
class BaseTask
{
public:
	BaseTask() {}
	virtual ~BaseTask() {}

	/**
	 * To be implemented by derived class.
	 */
	virtual bool Execute() = 0;
};

#endif /* BASETASK_H_ */
