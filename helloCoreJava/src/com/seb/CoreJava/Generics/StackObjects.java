package com.seb.CoreJava.Generics;

import java.util.LinkedList;
import java.util.List;

/**
 * Stack class for raw Objects.
 * @author seblkma
 *
 */
public class StackObjects {
	@SuppressWarnings("rawtypes")
	private final List values;
	
	@SuppressWarnings("rawtypes")
	public StackObjects() {
		values = new LinkedList();
	}
	
	@SuppressWarnings("unchecked")
	public void push(Object obj) {
		values.add(0, obj); // add to front
	}
	
	public Object pop() {
		if (values.size() == 0) return null;
		
		return values.remove(0); // get and delete from front
	}
}
