package com.seb.practice;

public class Person {
	
	private int age = 0;
	
	public Person(int initialAge) {
		if (initialAge >= 0) {
			setAge(initialAge);
		}
		else {
			System.out.println("Age is not valid, setting age to 0.");
		}
	}
	
	public void yearPasses() {
		this.age++;
	}
	
	public void amIOld() {
		int myAge = getAge();
		if (myAge < 13) {
			System.out.println("You are young.");
		}
		else if (myAge >= 13 && myAge < 18) {
			System.out.println("You are a teenager.");
		}
		else {
			System.out.println("You are old.");
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}



	public int getAge() {
		return age;
	}



	private void setAge(int age) {
		this.age = age;
	}

}
