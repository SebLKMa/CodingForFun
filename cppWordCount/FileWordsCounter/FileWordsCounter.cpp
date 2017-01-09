/*
 * FileWordsCounter.cpp
 *
 *  Created on: Jan 6, 2017
 *      Author: LMA
 */
#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>		// for istringstream
#include <vector>
#include <algorithm>
#include <functional>	// for std::greater
#include "FileWordsCounter.h"

using std::string;
using std::ios;

const std::string NON_WORD_SYMBOLS = ",;.:-()\t!¡¿?\"[]{}&<>+-*/=#'";

FileWordsCounter::FileWordsCounter(const std::string& fileName) : m_FileName{fileName}
{
}

void FileWordsCounter::startProcess(const unsigned int& topWords)
{
	try
	{
		validateFile();
		populateWordFrequencies();
		showTop(topWords);
	}
	catch (const ios::failure& ex)
	{
		std::cout << std::endl << ex.what() << std::endl;
	}
}

void FileWordsCounter::populateWordFrequencies()
{
	// for platform independence, open file in binary mode
	std::ifstream inStream{ m_FileName, ios::in | ios::binary };

	if (inStream.is_open())
	{
		std::string lineRead; // line read from file
		std::string wordRead; // word read from line

		while (std::getline(inStream, lineRead))
		{
			// replace non-word symbols with space for work subsequent tokenization
			for (std::string::iterator it = lineRead.begin(); it != lineRead.end(); ++it)
			{
				if (NON_WORD_SYMBOLS.find(*it) != std::string::npos)
				{
					*it = ' ';
				}
			}

			// tokenize line into words using std::operator>> separate by spaces
			std::istringstream filter{lineRead};
			while (filter >> wordRead)
			{
				++(m_WordFrequencies[wordRead]); // add or update word frequency count
			}
		}
	}
}

void FileWordsCounter::showTop(const unsigned int& max)
{
	// m_WordFrequencies is a map containing word-frequency-pair, and already sorted by Keys, i.e. word
	// we will transfer the map's key-value pairs as value-key pairs into a vector.
	// this is so that we can sort the vector by value, i.e. frequency

	std::vector<WordFrequencyPair> frequencyList;
	for (auto const& entry : m_WordFrequencies)
	{
		WordFrequencyPair kvp{entry.second, entry.first};
		frequencyList.push_back(kvp);
	}

	// sort the vector in descending order
	std::sort(frequencyList.begin(), frequencyList.end(), std::greater<WordFrequencyPair>());

	std::cout << "The top " << max << " words frequency are:" << std::endl;
	unsigned int count = 1;
	for (auto const& entry : frequencyList)
	{
		std::cout << entry.first << "\t" << entry.second << std::endl;
		++count;
		if (count > max)
		{
			break;
		}
	}

	frequencyList.clear(); // we no longer need this list
}

void FileWordsCounter::validateFile()
{
	// error if input file does not exist
	std::ifstream in{m_FileName, ios::in | ios::binary};
	if (!in)
	{
		throw ios::failure{ string("Input file ") + m_FileName + " not found!" };
	}

	// error if a text line cannot be read
    if (in.is_open())
    {
        std::string lineRead;
        if (!std::getline(in, lineRead))
        {
        	throw ios::failure{ string("Input file ") + m_FileName + ": text/line cannot be read" };
        }
    }
}

