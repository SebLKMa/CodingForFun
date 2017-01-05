/*
 * Test03.h
 *
 *  Created on: Jan 5, 2017
 *      Author: LMA
 */

#ifndef TEST03_H_
#define TEST03_H_

class Test03
{
public:
	void testTruckloadList();
private:
	// gemerate a random integer 1 to count
	inline size_t random(size_t count)
	{
		return 1 + static_cast<size_t>(count * static_cast<double>(std::rand()) / RAND_MAX+1.0);
	}
};

#endif /* TEST03_H_ */
