/*
 * DerivedB.h
 *
 *  Created on: Nov 30, 2016
 *      Author: LMA
 */

#ifndef DERIVEDB_H_
#define DERIVEDB_H_

#include "Base.h"

//class DerivedB : public Base
class DerivedB : public virtual Base
{
public:
	DerivedB(void);
	virtual ~DerivedB(void);
	void sayHello();
};

#endif /* DERIVEDB_H_ */
