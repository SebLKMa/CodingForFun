package com.seb.CoreJava.Generics;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

public class AuthorList {
	@SuppressWarnings("rawtypes")
	private List authors; // this list is not restricted to contain objects of specific type 

	private class Author {
		private final String name;
		
		private Author(final String name) {
			this.name = name;
		}
		
		public String getName() {
			return this.name;
		}
	}
	
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public void createAuthors() {
		authors = new ArrayList();
		
		authors.add(new Author("Stephen Hawking"));
		authors.add(new Author("Edgar Allen Poe"));
		authors.add(new Author("Richard Feynman"));
	}
	
	public void clearAuthors() {
		if (authors == null) return;
		
		authors.clear();
	}
	
	@Test
	public void authorListAccess() {
		createAuthors();
		final Author author = (Author)authors.get(2); // need to cast
		assertEquals("Richard Feynman", author.getName());
		clearAuthors();
	}
	
	@SuppressWarnings("unchecked")
	@Test
	public void authorListMessUp() {
		createAuthors();
		authors.add("J.K. Rowling");
		
		final String authorAsString = (String)authors.get(authors.size() - 1);
		assertEquals("J.K. Rowling", authorAsString);
		clearAuthors();
	}
	
}
