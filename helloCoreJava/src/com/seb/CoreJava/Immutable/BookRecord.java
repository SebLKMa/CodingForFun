package com.seb.CoreJava.Immutable;

/**
 * This class is "almost immutable".
 * However, Reflection APIs can still change its states.
 * @author seblkma
 *
 */
public class BookRecord {
	private String author;
	private String bookTitle;
	
	public BookRecord(String author, String bookTitle) {
		this.author = author;
		this.bookTitle = bookTitle;
	}

	public String getAuthor() {
		return author;
	}
	
	public String getBookTitle() {
		return bookTitle;
	}
	
}
