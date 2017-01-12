/*
 * StringUtils.h
 *
 *  Created on: Jan 12, 2017
 *      Author: LMA
 */

#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_
#include <string>

class StringUtils
{
public:
	/**
	 * @param str The string to be reversed.
	 */
	void reverse(std::string& str);

	/**
	 * Checks if string is a palindrome.
	 * @param str The string to check.
	 * @return true if str is palindrome, false otherwise.
	 */
	bool isPalindrome(const std::string& str);

};

#endif /* STRINGUTILS_H_ */
