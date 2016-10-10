package com.seb.research.algorithms;

public class HashtableString {

	/**
	 * Data structure used by HashtableString
	 * @author likke
	 *
	 */
	public class StringKeyValue {
		
		public StringKeyValue(String newKey, String newValue) {
			this.key = newKey;
			this.value = newValue;
		}
		
		public String getKey() {
			return this.key;
		}
		
		public String getValue() {
			return this.value;
		}
		
		public StringKeyValue getNext() {
			return this.next;
		}
		
		public void setNext(StringKeyValue nextObj) {
			this.next = nextObj;
		}
		
		private String key = ""; // holds the key
		private String value = ""; // holds the value
		private StringKeyValue next; // points to next object in linked list
	}
	
	public HashtableString(int newTableSize) {
		this.tableSize = newTableSize;
		this.table = new StringKeyValue[newTableSize];
		for (int i = 0; i<newTableSize; i++) {
			this.table[i] = null;
		}
	}
	
	public StringKeyValue find(String key) {
		int bucket = hashString(key); // get the hashed value to locate array index
		StringKeyValue obj = this.table[bucket]; // get the first object in array index
		while (obj != null) {
			if (key.equals(obj.key)) {
				return obj;
			}
			obj = obj.getNext();
		}
		return null; // key not found
	}
	
	public boolean add(String newKey, String newValue) {
		if (this.find(newKey) != null) {
			return false; // duplicate key not allowed
		}
		
		StringKeyValue newEntry = new StringKeyValue(newKey, newValue);
		int bucket = hashString(newKey);
		newEntry.setNext(this.table[bucket]);
		this.table[bucket] = newEntry;
		size++;
		
		return true;
	}
	
	public String get(String key) {
		StringKeyValue entry = this.find(key);
		if (entry == null) {
			return null;
		}
		return entry.getValue();
	}
	
	public boolean contains(String key) {
		if (this.find(key) == null) {
			return false;
		}
		return true;
	}
	
	public boolean remove(String key) {
		int bucket = this.hashString(key);
		StringKeyValue entry = this.table[bucket];
		if (entry == null) { // key not found
			return false;
		}
		else if (key.equals(entry.getKey())) { // key found in first array element
			this.table[bucket] = entry.next;
			size--;
			return true;
		}
		else { // iterate linked list to find the key
			StringKeyValue nextEntry = entry.getNext();
			while (nextEntry != null) {
				if (key.equals(nextEntry.getKey())) {
					entry.setNext(nextEntry.getNext());
					size--;
					return true;
				}
				entry = entry.getNext();
				nextEntry = nextEntry.getNext();
			}
		}
		return false;
	}
	
	public int getSize() {
		return this.size;
	}
	
	public void initIterator() {
		this.currentEntry = null;
		this.currentIndex = this.tableSize;
		
		// set currentEntry and currentIndex to the first non-null entry in table
		for (int i=0; i<this.tableSize; i++) {
			if (this.table[i] == null) {
				continue; // move to next element
			}
			else {
				this.currentEntry = this.table[i];
				this.currentIndex = i;
				break;
			}
		}
	}
	
	public boolean hasNext() {
		if (this.currentEntry == null) {
			return false;
		}
		return true;
	}
	
	public String getNextKey() {
		if (this.currentEntry == null) {
			return ""; // iterator currentEntry is null, nothing in table
		}
		
		// sets the key to be returned
		String returnKey = new String(this.currentEntry.getKey());
		
		// update currentEntry to its next or to next non-null element in in table.
		if (this.currentEntry.getNext() != null) {
			// if currentEntry is linked to next, set it to next
			this.currentEntry = this.currentEntry.getNext();
		}
		else {
			for (int i=this.currentIndex+1; i<this.tableSize; i++) {
				if (this.table[i] == null) {
					continue; // move to next element
				}
				this.currentEntry = this.table[i];
				this.currentIndex = i;
				return returnKey;
			}
			this.currentEntry = null;
			this.currentIndex = this.tableSize;
		}
		return returnKey;
	}
	
	private int hashString(String key) {
		char[] arrKey = key.toCharArray();
		int keyLength = key.length();
		int hashValue = 0;
		
		int tempHashValue = 0;
		for (int i=0; i<keyLength; i++) {
			tempHashValue = (tempHashValue << 2) + arrKey[i]; 
		}
		hashValue = Math.abs(tempHashValue % this.tableSize); // abs to ensure +ve value
		return hashValue;
	}
	
	private int tableSize = 0;
	private StringKeyValue[] table;
	private int size = 0;
	private StringKeyValue currentEntry = null;
	private int currentIndex = 0;
	
	public static void displayAll(HashtableString hashTable) {
		System.out.println("Current entries in hash table:");
		
		String key = "";
		String value = "";
		hashTable.initIterator();
		while (hashTable.hasNext()) {
			key = hashTable.getNextKey();
			value = hashTable.get(key);
			System.out.println("key: " + key + "\tvalue:" + value);
		}
	}
	
	public static void main(String[] args) {
		HashtableString myTable = new HashtableString(10);
		myTable.add("111", "aaa");
		myTable.add("222", "bbb");
		myTable.add("333", "ccc");

		String key = "222";
		String value = myTable.get(key);
		System.out.println(key + ", " + getValue(value));
		System.out.println("Size: " + myTable.getSize());
		displayAll(myTable);
		
		myTable.remove(key);
		value = myTable.get(key);
		System.out.println(key + ", " + getValue(value));
		System.out.println("Size: " + myTable.getSize());
		displayAll(myTable);
	}
	
	public static String getValue(String value) {
		if (value == null) {
			return "value not found";
		}
		return value;
	}

}
