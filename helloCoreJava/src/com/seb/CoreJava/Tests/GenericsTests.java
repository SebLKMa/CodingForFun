package com.seb.CoreJava.Tests;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

import com.seb.CoreJava.Generics.StackGenerics;

class BaseA {}
class DerivedA extends BaseA {}

public class GenericsTests {

	/**
	 * Helper method to create StackGenerics of type BaseA
	 * @param listOfBaseA
	 * @return
	 */
	public static StackGenerics<BaseA> createStackOfBaseA(final List<? extends BaseA> listOfBaseA) {
		final StackGenerics<BaseA> stack = new StackGenerics<>();
		for (BaseA a : listOfBaseA) {
			stack.push(a);
		}
		
		return stack;
	}
	
	@Test
	public void useCreateStackOfBaseA() {
		final ArrayList<BaseA> myList = new ArrayList<>();
		for (int i=0; i<10; i++) {
			myList.add(new BaseA());
		}
		
		final StackGenerics<BaseA> stack = createStackOfBaseA(myList);
		assertNotNull(stack.pop());
	}
	
	@Test
	public void useCreateStackOfDerivedA() {
		final ArrayList<DerivedA> myList = new ArrayList<>();
		for (int i=0; i<10; i++) {
			myList.add(new DerivedA());
		}
		
		// cannot compile, List<DerivedA> is not subtype of List<BaseA)
		//final StackGenerics<DerivedA> stack = createStackOfBaseA(myList);
		
		// createStackOfBaseA changed to accept List<? extends BaseA>
		final StackGenerics<BaseA> stack = createStackOfBaseA(myList);
		
		assertNotNull(stack.pop());
	}

}
