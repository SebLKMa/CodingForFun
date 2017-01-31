/*
 * DerivedC.h
 *
 *  Created on: Nov 30, 2016
 *      Author: LMA
 */

#ifndef DERIVEDC_H_
#define DERIVEDC_H_

#include "DerivedA.h"
#include "DerivedB.h"

class DerivedC : public /*DerivedA,*/ DerivedB
{
public:
	DerivedC(void);
	virtual ~DerivedC(void);

	void sayHello();
};

#endif /* DERIVEDC_H_ */
