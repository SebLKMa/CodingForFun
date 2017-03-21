/*
 * DerivedA.h
 *
 *  Created on: Nov 30, 2016
 *      Author: LMA
 */

#ifndef DERIVEDA_H_
#define DERIVEDA_H_

#include "Base.h"

class DerivedA : public Base
{
public:
	DerivedA(void);
	virtual ~DerivedA(void);

	// overrides Base
	virtual void sayHi();
};

#endif /* DERIVEDA_H_ */
