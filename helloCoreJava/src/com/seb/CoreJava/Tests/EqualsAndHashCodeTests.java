package com.seb.CoreJava.Tests;

import static org.junit.Assert.*;

import java.util.HashSet;
import java.util.Set;

import org.junit.Test;

import com.seb.CoreJava.Basics.PersonDefect;
import com.seb.CoreJava.Basics.PersonDefectFixed;

public class EqualsAndHashCodeTests {

	@Test
	public void wrongSetBehavior() {
		final Set<PersonDefect> persons = new HashSet<>();
		
		final PersonDefect person1 = new PersonDefect("Tom", 28);
		final PersonDefect person2 = new PersonDefect("Dick", 30);
		final PersonDefect person3 = new PersonDefect("Harry", 22);
		
		final boolean person1Added = persons.add(person1);
		final boolean person2Added = persons.add(person2);
		final boolean person3Added = persons.add(person3);
		assertTrue(person1Added && person2Added && person3Added);
		
		// logically equals to person1
		final PersonDefect person1a = new PersonDefect("Tom", 28);
		// should return false because Tom already in the set
		final boolean person1aAdded = persons.add(person1a);
		
		// but returns true because the equals has not been implemented
		assertTrue(person1aAdded);
		// and the set size increased to 4 because of the same defect
		assertEquals(4, persons.size());
	}

	@Test
	public void rightSetBehavior() {
		final Set<PersonDefectFixed> persons = new HashSet<>();
		
		final PersonDefectFixed person1 = new PersonDefectFixed("Tom", 28);
		final PersonDefectFixed person2 = new PersonDefectFixed("Dick", 30);
		final PersonDefectFixed person3 = new PersonDefectFixed("Harry", 22);
		
		final boolean person1Added = persons.add(person1);
		final boolean person2Added = persons.add(person2);
		final boolean person3Added = persons.add(person3);
		assertTrue(person1Added && person2Added && person3Added);
		
		// logically equals to person1
		final PersonDefectFixed person1a = new PersonDefectFixed("Tom", 28);
		// should return false because Tom already in the set
		final boolean person1aAdded = persons.add(person1a);
		
		// equals has been implemented
		assertFalse(person1aAdded);
		// and the set size should remain as 3, person1a is not added to set
		assertEquals(3, persons.size());
	}
}
