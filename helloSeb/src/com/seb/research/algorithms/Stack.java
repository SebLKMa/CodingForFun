package com.seb.research.algorithms;

import java.util.Iterator;
import java.util.NoSuchElementException;

// unused
//import java.util.ListIterator;

/**
 * http://algs4.cs.princeton.edu/code/
 * Stack implementation using generics.
 * @param <T>
 */
public class Stack<T> implements Iterable<T> {
    private int size;       // size of the stack
    private Node<T> first;  // top of the stack
    
    private static class Node<T> {
        private T item;
        private Node<T> next;
    }
    
    /**
     * Constructs an empty stack.
     */
    public Stack() {
        first = null;
        size = 0;
    }
    
    public boolean isEmpty() {
        return first == null;
    }
    
    public int size() {
        return size;
    }
    
    /**
     * Addes item to stack
     * @param item
     */
    public void push(T item) {
        Node<T> oldFirst = first;
        first = new Node<T>();
        first.item = item;
        first.next = oldFirst;
        size++;
    }
    
    /**
     * Removes and returns the item most recently added to stack.
     * @return
     */
    public T pop() {
        if (isEmpty()) throw new NoSuchElementException("Stack underflow");
        T item = first.item;
        first = first.next;
        size--;
        return item;
    }
    
    /**
     * Returns but does NOT remove the item most recently added to stack.
     * @return
     */
    public T peek() {
        if (isEmpty()) throw new NoSuchElementException("Stack underflow");
        T item = first.item;
        return item;
    }
    
    /**
     *
     * @return the sequence of items in LIFO order, separated by spaces.
     */
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (T item : this) {
            sb.append(item + " ");
        }
        return sb.toString();
    }
    
    /**
     *
     * @return an iterator to this stack that iterates through the items in LIFO order
     */
    public Iterator<T> iterator() {
        return new StackIterator<T>(first);
    }
    
    // an internal Iterator class
    private class StackIterator<T> implements Iterator<T> {
        private Node<T> current;
        
        public StackIterator(Node<T> first) {
            current = first;
        }
        
        public boolean hasNext() {
            return current != null;
        }

        public T next() {
            if (!hasNext()) throw new NoSuchElementException();
            T item = current.item;
            current = current.next;
            return item;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }
    
    public static void main(String[] args) {
        Stack<String> myStack = new Stack<String>();
        myStack.push("To");
        myStack.push("Be");
        myStack.push("Or");
        myStack.push("Not");
        myStack.push("To");
        myStack.push("Be");
        System.out.println("Size: " + myStack.size());
        System.out.println(myStack);
        for (String s : myStack) {
            String popped = myStack.pop();
            System.out.println(popped);
        }
        System.out.println("Size: " + myStack.size());
    }
}
