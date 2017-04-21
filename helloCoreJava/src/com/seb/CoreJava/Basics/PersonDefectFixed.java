package com.seb.CoreJava.Basics;

public class PersonDefectFixed {
	private final String name;
	private final int age;
	
	public PersonDefectFixed(String name, int age){
		this.name = name;
		this.age = age;
	}
	
	@Override
	public int hashCode() {
		return this.name.hashCode() * age;
	}
	
	@Override
	public boolean equals(Object other) {
		if (this == other) return true;
		if (other == null || getClass() != other.getClass()) return false;
		
		PersonDefectFixed otherPerson = (PersonDefectFixed)other;
		if (!this.name.equals(otherPerson.name)) return false;
		if (Integer.compare(otherPerson.age, this.age) != 0) return false;
		
		return true;
	}
}
