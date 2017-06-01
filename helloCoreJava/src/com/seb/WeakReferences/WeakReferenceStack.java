package com.seb.WeakReferences;

import static org.junit.Assert.*;

import java.io.IOException;
import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

import com.seb.Internet.HTTP.Tests.RequestTests;

public class WeakReferenceStack<E> {
	private final List<WeakReference<E>> stackReferences;
	private int stackPointer = 0;
 
	public WeakReferenceStack() {
		this.stackReferences = new ArrayList<>();
	}
	
	public void push(E element) {
		this.stackReferences.add(stackPointer, new WeakReference<>(element));
		stackPointer++;
	}
	
	public E pop() {
		stackPointer--;
		return this.stackReferences.get(stackPointer).get();
		// returns a WeakReference, if caller no longer holds reference to it, it will be GC'ed.
	}
	
	public E peek() {
		return this.stackReferences.get(stackPointer - 1).get();
	}
	

	@Test
	public void testWeakReferenceStackManipulation() {
		final WeakReferenceStack<ValueContainer> stack = new WeakReferenceStack<>();
		
		// expected must point to a different object in memory, 
		// i.e. not the same reference to the one stored in our stack
		final ValueContainer expected = new ValueContainer("beauty is only skin deep");
		stack.push(new ValueContainer("beauty is only skin deep"));
		
		ValueContainer peekedValue = stack.peek();
		assertEquals(expected, peekedValue);
		assertEquals(expected, stack.peek());
		peekedValue = null; // set to null, we are no longer referencing the WeakReference stored in our stack
		System.gc(); // FOR TESTING ONLY !!! To force GC of weak references
		assertNull(stack.peek());
	}
	
	public static void main(String[] args) {
		final WeakReferenceStack<ValueContainer> stack = new WeakReferenceStack<>();
		
		// expected must point to a different object in memory, 
		// i.e. not the same reference to the one stored in our stack
		final ValueContainer expected = new ValueContainer("beauty is only skin deep");
		stack.push(new ValueContainer("beauty is only skin deep"));
		
		ValueContainer peekedValue = stack.peek();
		assertEquals(expected, peekedValue);
		assertEquals(expected, stack.peek());
		peekedValue = null; // set to null, we are no longer referencing the WeakReference stored in our stack
		System.gc(); // FOR TESTING ONLY !!! To force GC of weak references
		assertNull(stack.peek());
	}
}
