package com.seb.CoreJava.Tests;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

public class LambdasTests {

	@Test
	public void lambdaForeach() {
		List<Integer> numbers = new ArrayList<>();
		numbers.add(1);
		numbers.add(2);
		numbers.add(3);
		
		List<Integer> incrementedNumbers = new ArrayList<>();
		numbers.forEach(i -> { incrementedNumbers.add(i+10); }); // lambdas are anonymous functions
		
		for (int i=0; i<numbers.size(); i++) {
			assert numbers.get(i)+10 == incrementedNumbers.get(i);
		}
		
		assert numbers.size() == incrementedNumbers.size();
	}

}
