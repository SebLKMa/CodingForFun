/*
 * HelloContainers.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: LMA
 */
#include <vector>
#include <iostream>
#include "HelloContainers.h"
using namespace std;

void HelloContainers::helloVector()
{
	vector<int> myVect;
	//vector<int>::iterator it;
    //myVect.insert(it, 123);
    //myVect.insert(it, 2, 200);
    //myVect.insert(it, 3, 300);
	myVect.push_back(1);
	myVect.push_back(2);
	myVect.push_back(3);

    cout << "myVector contains:";
    vector<int>::iterator it;
    for (it=myVect.begin(); it<myVect.end(); it++)
    {
    	cout << ' ' << *it;
    }
    cout << '\n';
}


