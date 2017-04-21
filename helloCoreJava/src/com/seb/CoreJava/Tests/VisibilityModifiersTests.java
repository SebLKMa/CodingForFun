package com.seb.CoreJava.Tests;

import static org.junit.Assert.*;

import org.junit.Test;

import com.seb.CoreJava.Basics.Complex;

public class VisibilityModifiersTests {

	@Test
	public void complexNumberAddition() {
		final Complex expected = new Complex(6, 2);
		
		final Complex a = new Complex(8, 0);
		final Complex b = new Complex(-2, 2);
		
		assertEquals(a.add(b), expected);
	}

}
