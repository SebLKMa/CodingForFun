package com.seb.WeakReferences;

import com.seb.CoreJava.Basics.PersonDefectFixed;

public class ValueContainer {
	@SuppressWarnings("unused")
	private final String value;
	
	public ValueContainer(final String value) {
		this.value = value;
	}
	
	@Override
	protected void finalize() throws Throwable {
		super.finalize();
		System.out.printf("Finalizing for [%s]%n", toString());
	}
	
	@Override
	public int hashCode() {
		return this.value.hashCode();
	}
	
	@Override
	public boolean equals(Object other) {
		if (this == other) return true;
		if (other == null || getClass() != other.getClass()) return false;
		
		ValueContainer otherContainer = (ValueContainer)other;
		if (!this.value.equals(otherContainer.value)) return false;
		
		return true;
	}
	
	/* toString omitted */
}