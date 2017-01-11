/*
 * InterfaceSegregation.h
 *
 *  Created on: Jan 11, 2017
 *      Author: LMA
 */

#ifndef INTERFACESEGREGATION_H_
#define INTERFACESEGREGATION_H_

/**
http://www.tomdalling.com/blog/software-design/solid-class-design-the-interface-segregation-principle/

The Interface Segregation Principle (ISP):
Clients should not be forced to depend upon interfaces that they do not use.

 */
class A
{
public:
   void func1();
   void func2();
   // more methods
   void func3();
   void func4();
   void func5();
   void func6();
   void func7();
};

// BAD - class B now knows func3 to func7 that it does not need.
class B
{
	// Needs to perform func1 and func2 from A only
	void doSomething()
	{
		A* a = new A();
		a->func1();
		a->func2();
		delete a;
	}
};

class BaseA
{
	virtual ~BaseA();
    virtual void func1() = 0;
    virtual void func2() = 0;
};

class NewA : public BaseA
{
	   void func1();
	   void func2();
	   // more methods
	   void func3();
	   void func4();
	   void func5();
	   void func6();
	   void func7();
  };

// FIX - class NewB now knows func1 and func2 from BaseA only
class NewB
{
	// Needs to perform func1 and func2 from A only
	void doSomething()
	{
		BaseA* a = new NewA();
		a->func1();
		a->func2();
		delete a;
	}
};
#endif /* INTERFACESEGREGATION_H_ */
