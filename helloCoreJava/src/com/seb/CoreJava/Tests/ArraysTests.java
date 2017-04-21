package com.seb.CoreJava.Tests;

import static org.junit.Assert.*;

import java.util.HashMap;
import java.util.Map;

import org.junit.Test;

public class ArraysTests {

	/**
	 * arrays are objects
	 */
	@Test
	public void arraysAsObjects() {
		Map<String, Object> mappings = new HashMap<>();
		mappings.put("my_key", new int[] {0, 2, 4, 6, 8 , 10}); // array is an Object
		
		assertTrue(mappings.get("my_key") instanceof int[]);
	}

	/**
	 * Arrays are always passed by reference.
	 * Values of in the referenced array can be changed.
	 */
	@Test
	public void arrayReferences() {
		final int[] myArray = new int[] {0, 1, 2, 3, 4, 5};
		int[] myArrayRef = myArray;
		
		myArrayRef[3] = 99;
		
		assertFalse(myArray[3] == 3);
		assertTrue(myArray[3] == 99);
	}
}
