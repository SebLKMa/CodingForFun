package com.seb.CoreJava.Basics;

public class PersonDefect {
	private final String name;
	private final int age;
	
	public PersonDefect(String name, int age){
		this.name = name;
		this.age = age;
	}
	
	@Override
	public int hashCode() {
		return this.name.hashCode() * age;
	}

}
