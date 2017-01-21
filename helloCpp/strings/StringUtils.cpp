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

void StringUtils::removeDuplicates(string& str)
{
	if (str.empty()) return;

	unsigned int len = str.size();
	unsigned int stopper = 1; // first point the stopper to second character
	for (unsigned int currentIndex=1; currentIndex < len; ++currentIndex) // main loop to iterate all chars
	{
		unsigned int runnerIndex; // runner always starts from beginning
		for (runnerIndex = 0; runnerIndex < stopper; ++runnerIndex) // start comparing chars from beginning
		{
			if (str[runnerIndex] == str[currentIndex])
			{
				break; // duplicate found, exit from compare loop
			}
		}

		if (runnerIndex == stopper)
		{
			// reaching here means no duplicate found so far
			// we re-assign the str position with non-duplicated string
			str[stopper] = str[currentIndex];
			++stopper;
		}
		// otherwise, duplicate could be found, we ignore the string and continue main loop
	}

	// remove redundant remaining chars, if any
	if (stopper < len)
	{
		str.erase(stopper, len);
	}
}

/*
void Quicksort::swap(size_t srcIndex, size_t destIndex)
{
	PWord temp{m_Words[srcIndex]};
	m_Words[srcIndex] = m_Words[destIndex];
	m_Words[destIndex] = temp;
}
*/


