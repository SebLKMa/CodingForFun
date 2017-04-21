package com.seb.CoreJava.Tests;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

import com.seb.CoreJava.Basics.Rectangle;
import com.seb.CoreJava.Basics.Square;

public class PolymorphismTests {

	@Test
	public void polymorphicList() {
		List<Rectangle> rectangles = new ArrayList<>(3);
		rectangles.add(new Rectangle(5, 1));
		rectangles.add(new Rectangle(2, 10));
		rectangles.add(new Square(9));
		
		assertEquals(rectangles.get(0).area(), 5);
		assertEquals(rectangles.get(1).area(), 20);
		assertEquals(rectangles.get(2).area(), 81);
	}

}
