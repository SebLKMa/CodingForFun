package com.seb.Algorithms;

import static org.junit.Assert.*;

import org.junit.Test;

public class Reverse {
	
	public static String inPlaceReverse(final String sourceStr) {
		final StringBuilder builder = new StringBuilder(sourceStr);
		for (int i=0; i < sourceStr.length()/2; i++) {
			final char tmp = sourceStr.charAt(i);
			final int otherEnd = sourceStr.length() - i - 1;
			builder.setCharAt(i, builder.charAt(otherEnd));
			builder.setCharAt(otherEnd, tmp);
		}
		return builder.toString();
	}
	
	public class SimpleLinkedList<T> {
		private T element;
		private SimpleLinkedList<T> next;
		
		public SimpleLinkedList(T element, SimpleLinkedList<T> next) {
			this.element = element;
			this.next = next;
		}
		
		public T getElement() {
			return this.element;
		}
		
		public SimpleLinkedList<T> getNext() {
			return this.next;
		}
	}
	
	public static <T> SimpleLinkedList<T> reverse(final SimpleLinkedList<T> source) {
		if (source == null) {
			throw new NullPointerException("Cannot reverse a null list");
		}
		
		if (source.getNext() == null) {
			return source;
		}
		
		final SimpleLinkedList<T> myNext = source.getNext(); // remember my next
		source.next = null; // un-link me
		
		final SimpleLinkedList<T> othersReversed = reverse(myNext); // recursive reverse next
		
		myNext.next = source; // re-link me to original source, note that we are playing with the stack memory
		
		return othersReversed;
	}

	@Test
	public void testInPlaceReverse() {
		String original = "hello";
		String actual = inPlaceReverse(original);
		String expected = "olleh";
		System.out.println("Original: " + original + " Reversed: " + actual);
		assertEquals(expected, actual);
	}
	
	@Test
	public void testReverseLinkedList() {
		// creating a linked list
		// One -> Two -> Three -> null
		final SimpleLinkedList<String> three = new SimpleLinkedList<>("3", null);
		final SimpleLinkedList<String> two = new SimpleLinkedList<>("2", three);		
		final SimpleLinkedList<String> one = new SimpleLinkedList<>("1", two);
		
		final SimpleLinkedList<String> reversed = reverse(one);
		
		assertEquals("3", reversed.getElement());
		assertEquals("2", reversed.getNext().getElement());
		assertEquals("1", reversed.getNext().getNext().getElement());
	}
	
}
