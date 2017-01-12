/*
 * StringUtils.cpp
 *
 *  Created on: Jan 12, 2017
 *      Author: LMA
 */
#include "StringUtils.h"
using namespace std;

void StringUtils::reverse(string& str)
{
	unsigned int len = str.size();
	unsigned int mid = len / 2;
	for (unsigned int i = 0; i<mid; ++i)
	{
		swap(str[i], str[len - i - 1]);
	}
}

bool StringUtils::isPalindrome(const std::string& str)
{
	string myStr{str}; // copy from const str
	reverse(myStr);
	if (myStr == str)
	{
		return true;
	}
	return false;
}

/*
void Quicksort::swap(size_t srcIndex, size_t destIndex)
{
	PWord temp{m_Words[srcIndex]};
	m_Words[srcIndex] = m_Words[destIndex];
	m_Words[destIndex] = temp;
}
*/


