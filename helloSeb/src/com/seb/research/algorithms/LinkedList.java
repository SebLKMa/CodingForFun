package com.seb.research.algorithms;

import java.util.Hashtable;

public class LinkedList {
    
    /**
     * Implementation of a node.
     */
    private class Node {
        Node next; // null indicates end of list
        Object data;
        
        public Node(Object dataValue) {
            next = null;
            data = dataValue;
        }
        
        public Node(Object dataValue, Node nextNode) {
            next = nextNode;
            data = dataValue;
        }
        
        public Object getData() {
            return data;
        }
        
        public Node getNext() {
            return next;
        }
        
        public void setNext(Node nextNode) {
            next = nextNode;
        }
    }
    
    private Node head;
    private int count;
    
    /**
     * Constructs an empty list, head is an empty node.
     */
    public LinkedList() {
        head = new Node(null);
        count = 0;
    }
    
    /**
     * Get the number of elements in this list.
     * @return
     */
    public int size() {
        return count;
    }
    
    /**
     * Adds element to end of list
     * @param data
     */
    public void add(Object data) {
        Node temp = new Node(data);
        Node current = head;
        
        // BEFORE:
        // [head|next] -> [data1|next] -> [data2|next] -> [data3|null]
        // AFTER: add [new data]
        // [head|next] -> [data1|next] -> [data2|next] -> [data3|next] -> [new data|null]
        
        // iterates from beginning until the end of list
        while (current.getNext() != null) {
            current = current.getNext();
        }
        
        current.setNext(temp);
        count++;
    }
    
    /**
     * Adds element at specified position in the list.
     * @param data
     * @param index
     */
    public void add(Object data, int index) {
        Node temp = new Node(data);
        Node current = head;
        
        // BEFORE:
        // [head|n0] -> [data1|next] -> [data2|next] -> [data3|next] -> [data4|null]
        // AFTER: insert [data5] at index 2
        // [head|n0] -> [data1|next] -> [data2|next] -> [data5|next] -> [data3|next] -> [data4|null]
        
        // iterates from beginning to the specified index or until end of list
        for (int i=1; i < index && current.getNext() != null; i++) {
            current = current.getNext();
        }
        
        // sets new node's next to point to current node's next
        temp.setNext(current.getNext());
        
        // sets current node's next to point to new node
        current.setNext(temp);
        
        count++;
    }
    
    /**
     * Gets element at specified index.
     * @param index
     * @return
     */
    public Object get(int index) {
        if (index <= 0) return null;
        
        // iterates from beginning until index or last node
        Node current = head.getNext();        
        for (int i=1; i < index; i++) {            
            if (current.getNext() == null) {
                return null;
            }
            
            current = current.getNext();
        }
        
        return current.getData();
    }
    
    public boolean remove(int index) {
        if (index < 1 || index > size()) return false;
        //System.out.println("remove index:" + index);
        
        // BEFORE: 
        // [head|n0] -> [data1|next] -> [data2|next] -> [data5|next] -> [data3|next] -> [data4|null]
        // BEFORE: remove index 3
        // [head|n0] -> [data1|next] -> [data2|next] -> [data3|next] -> [data4|null]
         
        // iterates from beginning until index or last node
        Node current = head;
        for (int i=1; i < index; i++) {
            if (current.getNext() == null) {
                return false;
            }
            
            //System.out.println("current:" + current.getData());
            current = current.getNext();
            //System.out.println("current:" + current.getData());
        }
        
        current.setNext(current.getNext().getNext());
        count--;
        return true;
    }
    
    public void removeDupsFast() {
    	System.out.println("removeDupsFast()");
    	if (this.size() == 0) return;
    	
    	Hashtable table = new Hashtable(); // using buffer to store unique keys
    	Node previous = head;
    	Node current = head.getNext();
    	while (current != null) {
    		if (table.containsKey(current.getData())) {
    			// table contains the node data, remove the node
    			previous.setNext(current.getNext());
    			count--; // remember to update size
    		} else {
    			// table does not contain node data, add node data to table
    			table.put(current.getData(), true);
    			previous = current; // move previous
    		}
    		current = current.getNext(); // move current
    	}
    }
    
    public void removeDupsSlow() {
    	System.out.println("removeDupsSlow()");
    	if (this.size() == 0) return;
    	
    	Node previous = head;
    	Node current = head.getNext();
    	while (current != null) {
    		Node runner = head; // runner always starts from beginning to current
    		while (runner != current) {
    			if (runner.getData() != null && runner.getData() == current.getData()) {
    				// current node data found from runner, remove current
    				Node nextNode = current.getNext();
    				previous.setNext(nextNode);
    				current = nextNode; // move current to next node
    				count--; // remember to update size
    				break; // by now, all dups would have been removed
    			}
    			runner = runner.getNext(); // move runner to next node
    		}
    		if (runner == current) { // update previous, move current to next
    			previous = current;
    			current = current.getNext();
    		}
    	}
    }
    
    
    public String toString() {
        Node current = head.getNext();
        // using StringBuilder in case list is large
        //String desc = "";
        StringBuilder sb = new StringBuilder();
        while (current != null) {
        	//desc += "[" + current.getData().toString() + "]";
            sb.append("[");
            sb.append(current.getData().toString());
            sb.append("]");
            current = current.getNext();
        }
        //return desc;
        return sb.toString();
    }
  
      
    public static void main(String[] args) {
        LinkedList myList = new LinkedList();
    
        // add elements to LinkedList
        myList.add("1");
        myList.add("2");
        myList.add("3");
        myList.add("4");
        myList.add("5");
    
        /*
         * Please note that primitive values can not be added into LinkedList
         * directly. They must be converted to their corresponding wrapper
         * class.
         */
    
        System.out.println("myList - print linkedlist: " + myList);
        System.out.println("myList.size() - print linkedlist size: " + myList.size());
        System.out.println("myList.get(3) - get 3rd element: " + myList.get(3));
        System.out.println("myList.remove(3) - remove 2nd element: " + myList.remove(3));
        System.out.println("myList.get(3) - get 3rd element: " + myList.get(3));
        System.out.println("myList.size() - print linkedlist size: " + myList.size());
        System.out.println("myList - print linkedlist: " + myList);
    }
}
