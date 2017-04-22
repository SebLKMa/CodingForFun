package com.seb.CoreJava.Interfaces;

/**
 * Java 8 interfaces are almost the same as abstract classes.
 * @author likke
 *
 */
public interface Java8Example {
	void alpha(); // to be implemented
	
	int beta default { return 6; } // interface can have default implementation
	
	String omega final { return "Cannot override"; } // interface method can be final
}
