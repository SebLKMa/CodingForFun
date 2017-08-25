/*
 * main_test.cpp
 *
 *  Created on: Aug 25, 2017
 *      Author: LMA
 */

#include "tests\ClassA.h"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( my_test )
{
	A::doSimpleTest();
    A myA;
    //BOOST_CHECK( test_object.is_valid() );
	BOOST_CHECK_EQUAL( myA.getHello(), "Beauty is only skin deep" );
}




