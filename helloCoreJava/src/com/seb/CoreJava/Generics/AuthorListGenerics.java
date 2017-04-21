package com.seb.CoreJava.Generics;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

public class AuthorListGenerics {
	private List<Author> authors; // this list is restricted to contain objects of Author type 

	private class Author {
		private final String name;
		
		private Author(final String name) {
			this.name = name;
		}
		
		public String getName() {
			return this.name;
		}
	}
	
	public void createAuthors() {
		authors = new ArrayList<>(); // inferred to type of Author
		
		authors.add(new Author("Stephen Hawking"));
		authors.add(new Author("Edgar Allen Poe"));
		authors.add(new Author("Richard Feynman"));
	}
	
	@Test
	public void authorListAccess() {
		createAuthors();
		Author author = authors.get(2);
		assertEquals("Richard Feynman", author.getName());
	}
}
