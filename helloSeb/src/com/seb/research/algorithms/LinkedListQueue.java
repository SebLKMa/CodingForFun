package com.seb.research.algorithms;

public class LinkedListQueue extends LinkedList {

	public LinkedListQueue() {
		super();
	}
	
	public void enqueue(Object data) {
		this.add(data);
	}
	
	public Object dequeue() {
		Object item = this.removeFirst();
		
		return item;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinkedListQueue queue = new LinkedListQueue();
		
		queue.enqueue("1");
		queue.enqueue("2");
		queue.enqueue("3");
		queue.enqueue("4");
		queue.enqueue("5");
		
		System.out.println(queue.toString());
		
	    Object item = queue.dequeue();
	    while (item != null) {
	    	System.out.println(item);
	    	item = queue.dequeue();
	    }
		
	}

}
