package com.seb.CoreJava.Immutable;

/**
 * This class is "immutable". Private member fields must be marked as final.
 * However, Reflection APIs can still change its states if setAccessible is set to true.
 * @author seblkma
 *
 */
public final class BookRecordImmutable {
	final private String author;
	final private String bookTitle;
	
	public BookRecordImmutable(String author, String bookTitle) {
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
