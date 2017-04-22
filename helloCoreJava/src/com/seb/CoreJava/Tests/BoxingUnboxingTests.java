package com.seb.CoreJava.Tests;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

public class BoxingUnboxingTests {
	
	@Test
	public void referenceTypesGenericsOnly() {
		// compile error - generics cannot work for primitive types
		//List<int> numbers = new ArrayList<int>();

		// generics work for reference types only
		List<Integer> numbers = new ArrayList<>();
		assertNotNull(numbers);
	}
	
	/**
	 * Caveats on boxing and unboxing - unboxed can return null
	 */
	@Test
	public void boxUnboxError() {
		final Integer intObject = 42; // box primitive type to reference type
		assert(intObject == 42);
		
		try {
			final int intValue = methodMayReturnNull(intObject); // will throw if method returns null
			fail("assign null to primitive should throw NPE");
		} catch (NullPointerException ex) {
			// expected, test passed
		}
	}

	private Integer methodMayReturnNull(Integer intObj) {
		return null; // hardcoded to simulate unboxing becomes null
	}
}
