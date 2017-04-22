package com.seb.CoreJava.Generics;

import java.util.LinkedList;
import java.util.List;

/**
 * Stack class using generics.
 * @author seblkma
 *
 * @param <T>
 */
public class StackGenerics<T> {
	private final List<T> values;
	
	public StackGenerics() {
		values = new LinkedList<T>();
	}
	
	public void push(T obj) {
		values.add(0, obj); // add to front
	}
	
	public T pop() {
		if (values.size() == 0) return null;
		
		return values.remove(0); // get and delete from front
	}
}
