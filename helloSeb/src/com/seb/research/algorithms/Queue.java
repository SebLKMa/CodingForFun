package com.seb.research.algorithms;

import java.util.Iterator;
import java.util.NoSuchElementException;
//import java.util.ListIterator;

/**
 * http://algs4.cs.princeton.edu/code/
 * Queue implementation using generics.
 * @param <T>
 */
public class Queue<T> implements Iterable<T> {
    private int size;       // size of the queue
    private Node<T> first;  // first in the queue
    private Node<T> last;   // top of the queue
    
    private static class Node<T> {
        private T item;
        private Node<T> next;
    }
    
    /**
     * Constructs an empty queue.
     */
    public Queue() {
        first = null;
        last = null;
        size = 0;
    }
    
    public boolean isEmpty() {
        return first == null;
    }
    
    public int size() {
        return size;
    }
    
    /**
     * Addes item to queue
     * @param item
     */
    public void enqueue(T item) {
        Node<T> oldLast = last;
        last = new Node<T>();
        last.item = item;
        last.next = null;
        if (isEmpty())
            first = last;
        else
            oldLast.next = last;
        
        size++;
    }
    
    /**
     * Removes and returns the item least recently added to stack.
     * @return
     */
    public T dequeue() {
        if (isEmpty()) throw new NoSuchElementException("Stack underflow");
        T item = first.item;
        first = first.next;
        size--;
        if (isEmpty()) last = null;
        return item;
    }
    
    /**
     * Returns but does NOT remove the item most recently added to stack.
     * @return
     */
    public T peek() {
        if (isEmpty()) throw new NoSuchElementException("Queue underflow");
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
     * @return an iterator to this queue that iterates through the items in FIFO order
     */
    public Iterator<T> iterator() {
        return new QueueIterator<T>(first);
    }
    
    // an internal Iterator class
    private class QueueIterator<T> implements Iterator<T> {
        private Node<T> current;
        
        public QueueIterator(Node<T> first) {
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
        Queue<String> myQueue = new Queue<String>();
        myQueue.enqueue("To");
        myQueue.enqueue("Be");
        myQueue.enqueue("Or");
        myQueue.enqueue("Not");
        myQueue.enqueue("To");
        myQueue.enqueue("Be");
        System.out.println("Size: " + myQueue.size());
        System.out.println(myQueue);
        for (String s : myQueue) {
            String dequeued = myQueue.dequeue();
            System.out.println(dequeued);
        }
        System.out.println("Size: " + myQueue.size());
    }
}
