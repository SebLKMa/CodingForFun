package com.seb.CoreJava.Tests;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

public class PrimitiveTypesTest {

	@Test
	public void absMostNegativeInteger() {
		final int mostNegative = Integer.MIN_VALUE;
		final int negated = Math.abs(mostNegative);
		assertFalse("No positive equivalent of Integer.MIN_VALUE", negated > 0);
	}
	
	@Test(expected = NullPointerException.class)
	public void expectNullPointerException() {
		final String s = null;
		final int len = s.length();
	}

	/**
	 * Test object in memory and assignments
	 */
	@Test
	public void objectAssignment() {
		List<String> list1 = new ArrayList<>();
		
		list1.add("entry 1");
		assertTrue(list1.size() == 1);
		
		List<String> list2 = list1;
		list2.add("entry 2");
		assertTrue(list1.size() == 2);
	}
	
	/**
	 * Test object reference and the object being referenced.
	 * Object reference cannot change, but the values of the object being referenced can change.
	 */
	@Test
	public void finalReferenceChanges() {
		final int i = 42;
		
		final List<String> list = new ArrayList<>(20);
		//list = new ArrayList<>(20); you cannot change the object reference to point to another object
		assertEquals(0, list.size());
		
		// but you can still change the values within object being referenced
		list.add("entry 1");
		assertEquals(1, list.size());
		
		list.clear();
		assertEquals(0, list.size());
	}
}
