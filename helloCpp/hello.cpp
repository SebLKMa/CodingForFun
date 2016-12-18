// helloCppConsole.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h" not using pre-compiled headers
#include <iostream>
#include <memory>
#include <utility>
#include <iomanip>
#include <thread>
#include <chrono>
#include <mutex>
#include "Greet.h"
#include "HelloContainers.h"
#include "inheritance\DerivedC.h"
#include "copymove\MemoryPage.h"
#include "loops\Loops.h"

using namespace std;

void testLoops()
{
	Loops myLoops;
	myLoops.DoLoop1();
}

void testInheritanceInStack()
{
	cout << "testInheritanceInStack" << endl;
	DerivedC myC;
	myC.sayHello();

	DerivedB myB = static_cast<DerivedB>(myC);
	myB.sayHello();
}

void testInheritanceInHeap()
{
	cout << "testInheritanceInHeap" << endl;

	Base* pBase = new DerivedC();
	cout << "pBase created" << endl;
	if (nullptr != pBase)
	{
		DerivedC* pDerivedC = dynamic_cast<DerivedC*>(pBase);
		if (pDerivedC)
		{
			pDerivedC->sayHello();
		}

		delete pBase;
		cout << "pBase destroyed" << endl;
	}
}

void testCpp11()
{
	cout << "testCpp11" << endl;

	//auto text = unique_ptr<char[]>(new char[42]);

	unique_ptr<DerivedC> p1(new DerivedC);  // p1 owns DerivedC
	/*
	if (p1) p1->bar();
	{
	std::unique_ptr<Foo> p2(std::move(p1));  // now p2 owns Foo
	f(*p2);

	p1 = std::move(p2);  // ownership returns to p1
	std::cout << "destroying p2...\n";
	}

	if (p1) p1->bar();
	*/

	// Foo instance is destroyed when p1 goes out of scope

}

void testCopy()
{
	cout << "testCopy" << endl;
	MemoryPage myPage(1024);
	MemoryPage myPage1 = myPage; // copy ctor
}

void testAssignment()
{
	cout << "testAssignment" << endl;
	MemoryPage myPage2(1024);
	MemoryPage myPage3(512);
	cout << "myPage2: " << myPage2.getSize() << endl;
	cout << "myPage3: " << myPage3.getSize() << endl;
	myPage2 = myPage3; // assignment ctor
	cout << "myPage2: " << myPage2.getSize() << endl;
}

void testMove()
{
	cout << "testMove" << endl;
	MemoryPage myPage(1024);
	MemoryPage myPage1 = std::move(myPage); // force move ctor
}

void testByteOrder()
{
	unsigned long lNumber;
	unsigned char* pChar;

	// 11 22 33 44 => big-endian
	// 44 33 22 11 => little-endian
	// lNumber = 0x1122334455667788UL for long 64-bit

	lNumber = 0x11223344UL;
	pChar = (unsigned char*)&lNumber;
	for (int i = 0; i<sizeof(long); i++)
	{
		//cout << std::hex << setw(4) << *pChar++;
		printf("%x ", *pChar++);
	}
	cout << endl;
	//printf("\n");
}

void sayHello(int secs)
{
	cout << "Hello started" << endl;
	for (int i = 0; i<secs; ++i)
	{
		cout << i << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	cout << "Hello completed " << endl;
}

void testThread()
{
	std::thread myThread;
	myThread = std::thread(sayHello, 3);
	//myThread.join();
	myThread.detach();
}

mutex myMutex;
void threadSafeCout(int i)
{
	lock_guard<mutex> myGuard(myMutex);
	cout << " " << i << "";
}

void doForLoop(int max)
{
	for (int i = 10 * (max - 1); i < 10 * max; i++)
	{
		threadSafeCout(i);
	}
}

void testThreads()
{
	cout << endl;
	cout << "testThreads()" << endl;
	thread t1(doForLoop, 1); //  0 - 9
	thread t2(doForLoop, 2); // 10 - 19
	thread t3(doForLoop, 3); // 20 - 29
	thread t4(doForLoop, 4); // 30 - 39
	thread t5(doForLoop, 5); // 40 - 49

	for (int i = 0; i > -50; i--)
	{
		threadSafeCout(i);   // 0, -49
	}

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	// NOTE that deadlock can also happen without locks.
	// Example:
	// thread 1 calls join on thread 2
	// thread 2 calls join on thread 1
	// Therefore, do not wait for another thread of there is a chance
	// the other thread is waiting for you.
}

mutex myMutex1, myMutex2;
void deadlockableCoutEven(int i)
{
	// attempt to acquire lock 1
	lock_guard<mutex> myGuard1(myMutex1);
	// ... do some operations here

	// attempt to acquire lock 2
	lock_guard<mutex> myGuard2(myMutex2);

	cout << " " << i << " ";
}

void deadlockableCoutOdd(int i)
{
	// attempt to acquire lock 2
	lock_guard<mutex> myGuard2(myMutex2);
	// ... do some operations here

	// attempt to acquire lock 1
	lock_guard<mutex> myGuard1(myMutex1);
	
	cout << " " << i << " ";
}

void doForLoopEvenOdd(int max)
{
	for (int i = 10 * (max - 1); i < 10 * max; i++)
	{
		if (i % 2 == 0)
		{
			deadlockableCoutEven(i);
		}
		else
		{
			deadlockableCoutOdd(i);
		}
	}
}

void testDeadlockThreads()
{
	cout << endl;
	cout << "testDeadlockThreads()" << endl;

	thread t1(doForLoopEvenOdd, 1); //  0 - 9
	thread t2(doForLoopEvenOdd, 2); // 10 - 19
	thread t3(doForLoopEvenOdd, 3); // 20 - 29
	thread t4(doForLoopEvenOdd, 4); // 30 - 39
	thread t5(doForLoopEvenOdd, 5); // 40 - 49

	for (int i = 0; i > -50; i--)
	{
		threadSafeCout(i);   // 0, -49
	}

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	// Prevent deadlock by acquiring locks in the same order.
}

int main() {

	testLoops();

	//Greet greeter;
	//greeter.sayHello();

	//HelloContainers myContainers;
	//myContainers.helloVector();

	//testInheritanceInStack();
	//testInheritanceInHeap();
	//testCpp11();

	//testCopy();
	//testAssignment();
	//testMove();

	//testByteOrder();
	//testThread();

	//testThreads();
	//testDeadlockThreads();
	
	cout << endl;
	cout << "Q or q key to quit...";
	char chWait;
	cin >> chWait;

	return 0;
}