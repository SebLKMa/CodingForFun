/*
 * BaseTaskThread.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: LMA
 */
#include <thread>
#include "BaseTaskThread.h"

using namespace std;

void BaseTaskThread::Execute()
{
	std::thread myThread(&BaseTaskThread::DoExecute, this);
	myThread.detach();
}



