package com.seb.CoreJava.Basics;

/**
 * Demonstrates that private members can be access by any instance of the same type.
 * See the add() and equals() method.
 * @author seblkma
 *
 */
public class Complex {
	// private members
	private final double real;
	private final double imaginary;
	
	public Complex(final double r, final double i) {
		this.real = r;
		this.imaginary = i;
	}
	
	public Complex add(final Complex other) {
		return new Complex(this.real + other.real, this.imaginary + other.imaginary);
	}
	
	// hashCode omitted for brevity
	
	@Override
	public boolean equals(Object other) {
		if (this == other) return true;
		if (other == null || getClass() != other.getClass()) return false;
		
		Complex otherComplex = (Complex)other;
		if (Double.compare(otherComplex.imaginary, this.imaginary) != 0) return false;
		if (Double.compare(otherComplex.real, this.real) != 0) return false;
		
		return true;
	}

}
