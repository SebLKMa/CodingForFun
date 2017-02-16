/*
 * Common.h
 *
 *  Created on: 15 Feb 2017
 *      Author: likke
 */

#ifndef COMMON_H_
#define COMMON_H_

class Common
{
public:
	static void DebugMessage(const std::string& str);

	static void ErrorMessage(const std::string& str);

	static bool PortIsValid(const std::string& port);
};


#endif /* COMMON_H_ */
