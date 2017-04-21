package com.seb.CoreJava.Basics;

public class Rectangle {
	private final int width;
	private final int length;
	
	public Rectangle(final int width, final int length) {
		this.width = width;
		this.length = length;
	}
	
	public int area() {
		return this.width * this.length;
	}

}
