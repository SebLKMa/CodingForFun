/*
 * Device.h
 *
 *  Created on: Jan 24, 2017
 *      Author: LMA
 */

#ifndef DEVICE_H_
#define DEVICE_H_

class Device
{
public:
	Device() {}

	Device(const char* pName, size_t noOfStars);

	~Device();

	char* getName();

	size_t getNoOfStars();

	//Device(const Device& other) = default;
	//Device& operator=(const Device& other) = default;

	Device(const Device& other);
	Device& operator=(const Device& other);

private:
	char* m_pName{};
	size_t m_NoOfStars{0};

};


#endif /* DEVICE_H_ */
