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
#include <sstream>  // for istringstream
#include <typeinfo> // for typeid()
#include <vector>
#include <algorithm>
#include "FileWordsCounter.h"

using std::string;
using std::ios;

const std::string NON_WORD_SYMBOLS = ",;.:-()\t!¡¿?\"[]{}&<>+-*/=#'";

FileWordsCounter::FileWordsCounter(const std::string& fileName) : m_FileName{fileName}
{
}

void FileWordsCounter::startCount()
{
	try
	{
		validateFile(m_FileName);

        std::ifstream inStream{ m_FileName, ios::in | ios::binary };

        if (inStream.is_open())
        {
            std::string lineRead;
            std::string wordRead;

            while (std::getline(inStream, lineRead))
            {
                // replace non-wordRead symbols with space for work subsequent tokenization
                for(std::string::iterator it = lineRead.begin(); it != lineRead.end(); ++it)
                {
                    if (NON_WORD_SYMBOLS.find(*it) != std::string::npos)
                    {
                        *it = ' ';
                    }
                }

                // tokenize line into words using  std::operator>> separate by spaces
                std::istringstream filter{lineRead};
                while( filter >> wordRead )
                {
                    ++( m_WordFrequencies[wordRead] );
                }
            }
        }

        std::cout << "startCount() completed." << std::endl;
	}
	catch (const ios::failure& ex)
	{
		std::cout << std::endl << ex.what();
	}
	catch (const std::exception& ex)
	{
		std::cout << std::endl << typeid(ex).name() << ": " << ex.what();
	}
}

void FileWordsCounter::showTopBySearch(const unsigned int& max)
{
    //Get the largest and smallest values from map
	unsigned int beginPos = smallest_map_value();
	unsigned int endPos = largest_map_value();

	unsigned int count = 1;
	// Decrement through largest value to smallest values found
	for(unsigned int i = endPos; i >= beginPos; --i)
    {
        //For each increment, go through the map...
        //for(std::map<std::string, unsigned int>::const_iterator it = m_WordFrequencies.begin(); it != m_WordFrequencies.end(); ++it)
        for(std::map<std::string, unsigned int>::const_iterator it = m_WordFrequencies.begin(); it != m_WordFrequencies.end(); ++it)
        {
            // cout any pairs with matching values
            if(it->second == i)
            {
                std::cout << it->second << "\t" << it->first << std::endl;

        		++count;
        		if (count > max)
        		{
        			return;
        		}
            }
        }
    }
}

void FileWordsCounter::showTopBySort(const unsigned int& max)
{
	std::vector<WordFrequencyPair> frequencyList;
	for (auto const& entry : m_WordFrequencies)
	{
		WordFrequencyPair kvp{entry.second, entry.first};
		frequencyList.push_back(kvp);
	}
	std::sort(frequencyList.rbegin(), frequencyList.rend()); // sort descending

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
}

void FileWordsCounter::validateFile(const std::string& inFile)
{
	// error if input file does not exist
	std::ifstream in{ inFile, ios::in | ios::binary };
	if (!in)
	{
		throw ios::failure{ string("Input file ") + inFile + " not found!" };
	}

	// error if a text line cannot be read
    if (in.is_open())
    {
        std::string lineRead;

        if (!std::getline(in, lineRead))
        {
        	throw ios::failure{ string("Input file ") + inFile + ": text/line cannot be read" };
        }
    }
}

unsigned int FileWordsCounter::smallest_map_value()
{
    std::map<std::string, unsigned int>::const_iterator it = m_WordFrequencies.begin();
    int lowest = it->second;
    for(std::map<std::string, unsigned int>::const_iterator it = m_WordFrequencies.begin(); it != m_WordFrequencies.end(); ++it)
    {
        if(it->second < lowest)
            lowest = it->second;
    }
    return lowest;
}

unsigned int FileWordsCounter::largest_map_value()
{
	std::map<std::string, unsigned int>::const_iterator it = m_WordFrequencies.begin();
    int highest = it->second;
    for(std::map<std::string, unsigned int>::const_iterator it = m_WordFrequencies.begin(); it != m_WordFrequencies.end(); ++it)
    {
        if(it->second > highest)
            highest = it->second;
    }
    return highest;
}

