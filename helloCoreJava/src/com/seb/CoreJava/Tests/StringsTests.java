package com.seb.CoreJava.Tests;

import static org.junit.Assert.*;

import org.junit.Test;

public class StringsTests {

	/**
	 * Prefer to just use string literals when creating Strings.
	 */
	@Test
	public void stringCreation() {
		// using "new" not recommended for String as it is created in the PermGen space.
        // in fact the literal "Hello" string is constructed
        // then copied to myString1. String(char[]) makes a full copy of the char array.
	    String myString1 = new String("Hello"); 
	    
	    // created in String pool, recommended
	    // as same strings are stored in same location
	    String myString2 = "Hello";
	    
	    assertEquals(myString1, myString2);
	}

	@Test
	public void stringImmutable() {
		final String greeting = "Guten Tag!";
		final String subGreeting = greeting.substring(4); // new copy of string is returned
		
		assertTrue(subGreeting.equals("Gute"));
		assertFalse(greeting.equals(subGreeting));
		assertTrue(greeting.equals("Guten Tag!"));		
	}
	
	/**
	 * String constant pool is an implementation of the Flyweight Pattern.
	 */
	@Test
	public void intEquality()
	{
		// Explicitly calling "new" String so the instances
		// are in different memory locations
		final Integer int1 = Integer.valueOf(new String("100"));
		final Integer int2 = Integer.valueOf(new String("100"));
		
		// Integer.valueOf will return the same instance of the Integer object for
		// values between -127 and 127.
		
		assertTrue(int1 == int2);
	}
}
