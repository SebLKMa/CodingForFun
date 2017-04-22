package com.seb.CoreJava.Tests;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;

import org.junit.Test;

public class CollectionsTests {

	/**
	 * LinkedHashMap has all the properties of HashMap - quick lookup by key.
	 * It also preserves the order of entry.
	 */
	@Test
	public void showLinkedHashmapProperties() {
		final LinkedHashMap<Integer, String> orderedMap = new LinkedHashMap<>();		
		orderedMap.put(10, "ten");
		orderedMap.put(20, "twenty");
		orderedMap.put(30, "thirty");
		orderedMap.put(40, "forty");
		orderedMap.put(50, "fifty");
		
		// works like a map
		assertEquals("fifty", orderedMap.get(50));
		
		// respects insertion order
		final Iterator<Integer> keyIter = orderedMap.keySet().iterator();
		assertEquals("ten", orderedMap.get(keyIter.next()));
		assertEquals("twenty", orderedMap.get(keyIter.next()));
		assertEquals("thirty", orderedMap.get(keyIter.next()));
		assertEquals("forty", orderedMap.get(keyIter.next()));
		assertEquals("fifty", orderedMap.get(keyIter.next()));
		
		// same is not true for regular HashMap
		// insertion is based on hash key
		final HashMap<Integer, String> regularMap = new HashMap<>();
		regularMap.put(10, "ten");
		regularMap.put(20, "twenty");
		regularMap.put(30, "thirty");
		regularMap.put(40, "forty");
		regularMap.put(50, "fifty");
		
		final ArrayList<String> hashMapValues = new ArrayList<>(regularMap.values());
		final ArrayList<String> linkedHashMapValues = new ArrayList<>(orderedMap.values());
		
		// lists will have same entries, but different order
		assertFalse(linkedHashMapValues.equals(hashMapValues));
	}

}
