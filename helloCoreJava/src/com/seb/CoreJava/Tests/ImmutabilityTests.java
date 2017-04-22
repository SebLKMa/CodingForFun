package com.seb.CoreJava.Tests;

import static org.junit.Assert.*;

import org.junit.Test;

import com.seb.CoreJava.Immutable.BookRecord;
import com.seb.CoreJava.Immutable.BookRecordImmutable;

import java.lang.reflect.*;

public class ImmutabilityTests {

	@Test
	public void mutateBookRecord() {
		final BookRecord record = new BookRecord("Scott Meyer", "Effective C++");
		
		try {
			final Field authorReflected = record.getClass().getDeclaredField("bookTitle");
			authorReflected.setAccessible(true); // overrides all immutability
			authorReflected.set(record, "Modern Effective C++");
			
			assertEquals("Modern Effective C++", record.getBookTitle());

		} catch (NoSuchFieldException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SecurityException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalArgumentException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	@Test
	public void mutateBookRecordImmutable() {
		final BookRecordImmutable record = new BookRecordImmutable("Scott Meyer", "Effective C++");
		
		try {
			final Field authorReflected = record.getClass().getDeclaredField("bookTitle");
			authorReflected.setAccessible(true); // overrides all immutability
			authorReflected.set(record, "Modern Effective C++");
			
			assertEquals("Modern Effective C++", record.getBookTitle());

		} catch (NoSuchFieldException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SecurityException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalArgumentException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
