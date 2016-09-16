package com.seb.research.algorithms;

//import java.util.Arrays;

/******************************************************************************
 * File: RingBuffer.java
 * Author: Keith Schwarz (htiek@cs.stanford.edu) (http://www.keithschwarz.com/)
 *
 * An implementation of a synchronized queue backed by a ring buffer.  This
 * functionality and implementation is similar to the ArrayBlockingQueue class,
 * but I thought that I'd implement my own version to get a better feel for how
 * it works.
 *
 * A ring buffer is a space-efficient, locality-friendly implementation of a
 * FIFO queue.  It is implemented as a fixed-sized array that is treated as
 * though it wraps around like a ring; it has no well-defined start or end
 * point.  This array stores two pointers, a read pointer and a write pointer,
 * delineating where the next insert should take place and from where the next
 * element should be dequeued.  For example:
 *
 *                       [2] [3] [ ] [ ] [ ] [ ] [0] [1]
 *                                ^               ^
 *                                |               |
 *                              write            read
 *
 * When using a ring buffer, one must be careful not to let the read and write
 * pointers cross one another.  If this happens, future write operations will
 * start overwriting old elements that have not yet been consumed.  For this
 * reason, most ring buffers adopt one of two strategies.  First, the ring
 * buffer can increase its size whenever it runs out of room.  This approach
 * allows the buffer to grow arbitrarily large if need be.  The second option,
 * and the one used in this implementation, is simply to block on a read or
 * write when data is not available.  This allows the ring buffer to implement
 * the producer/consumer pattern fairly easily; any number of threads can begin
 * creating data while some number of threads consume it, and at no time are
 * too many elements kept in memory waiting to be read.
 */
public final class RingBuffer<T> {
    /* The actual ring buffer. */
    private final T[] elements;

    /* The write pointer, represented as an offset into the array. */
    private int offset = 0;

    /* The read pointer is encoded implicitly by keeping track of the number of
     * unconsumed elements.  We can then determine its position by backing up
     * that many positions before the read position.
     */
    private int unconsumedElements = 0;

    /**
     * Constructs a new RingBuffer with the specified capacity, which must be
     * positive.
     *
     * @param size The capacity of the new ring buffer.
     * @throws IllegalArgumentException If the capacity is negative.
     */
    @SuppressWarnings("unchecked")
    public RingBuffer(int size) {
        /* Validate the size. */
        if (size <= 0)
            throw new IllegalArgumentException("RingBuffer capacity must be positive.");

        /* Construct the array to be that size. */
        elements = (T[]) new Object[size];
    }

    /**
     * Appends an element to the ring buffer, blocking until space becomes
     * available.
     *
     * @param elem The element to add to the ring buffer.
     * @throws InterruptedException If the thread is interrupted before the
     *                              insertion completes.
     */
    public synchronized void add(T elem) throws InterruptedException {
        /* Block until the capacity is nonzero.  Otherwise we don't have any
         * space to write.
         */
        while (getUnconsumedElements() == elements.length)
            wait();

        /* Write the element into the next open spot, then advance the write
         * pointer forward a step.
         */
        elements[offset] = elem;
        offset = (offset + 1) % elements.length;
        
        printMessage("add Offset: " + offset);

        /* Increase the number of unconsumed elements by one, then notify any
         * threads that are waiting that more data is now available.
         */
        incrementUnconsumedElements();
        printMessage(getUnconsumedElements() + ", " + capacity());
        notifyAll();
    }

    /**
     * Returns the maximum capacity of the ring buffer.
     *
     * @return The maximum capacity of the ring buffer.
     */
    public int capacity() {
        return elements.length;
    }

    /**
     * Observes, but does not dequeue, the next available element, blocking
     * until data becomes available.
     *
     * @return The next available element.
     * @throws InterruptedException If the caller is interrupted before data
     *                              becomes available.
     */
    public synchronized T peek() throws InterruptedException {
        /* Wait for data to become available.
         * i.e. there are elements to consume
         * */
        while (getUnconsumedElements() == 0)
            wait();

        /* Hand back the next value.  The index of this next value is a bit
         * tricky to compute.  We know that there are unconsumedElements
         * elements waiting to be read, and they're contiguously before the
         * write position.  However, the buffer wraps around itself, and so we
         * can't just do a naive subtraction; that might end up giving us a
         * negative index.  To avoid this, we'll use a clever trick in which
         * we'll add to the index the capacity minus the distance.  This value
         * must be positive, since the distance is never greater than the
         * capacity, and if we then wrap this value around using the modulus
         * operator we'll end up with a valid index.  All of this machinery
         * works because
         *
         *                 (x + (n - k)) mod n == (x - k) mod n
         * 
         * And Java's modulus operator works best on positive values.
         */
        int peekOffset = (offset + (capacity() - getUnconsumedElements())) % capacity();
        printMessage("peek Offset: " + peekOffset);
        //return elements[(offset + (capacity() - unconsumedElements)) % capacity()];
        return elements[peekOffset];
    }

    /**
     * Removes and returns the next available element, blocking until data
     * becomes available.
     *
     * @return The next available element
     * @throws InterruptedException If the caller is interrupted before data
     *                              becomes available.
     */
    public synchronized T remove() throws InterruptedException {
        /* Use peek() to get the element to return. */
        T result = peek();

        /* Mark that one fewer elements are now available to read. */
        decrementUnconsumedElements();

        /* Because there is more space left, wake up any waiting threads. */
        notifyAll();

        printMessage(getUnconsumedElements() + ", " + capacity());
        return result;
    }

    /**
     * Returns the number of elements that are currently being stored in the
     * ring buffer.
     *
     * @return The number of elements currently stored in the ring buffer.
     */
    public synchronized int size() {
        return getUnconsumedElements();
    }

    /**
     * Returns whether the ring buffer is empty.
     *
     * @return Whether the ring buffer is empty.
     */
    public synchronized boolean isEmpty() {
        return size() == 0;
    }

    public int getUnconsumedElements() {
        return unconsumedElements;
    }

    protected void incrementUnconsumedElements() {
        ++unconsumedElements;
    }
    
    protected void decrementUnconsumedElements() {
        --unconsumedElements;
    }

    private static class Writer implements Runnable {
        private RingBuffer<String> _ring = null;
        private volatile boolean _terminate = false;
        
        public Writer(RingBuffer<String> ring) {
            _ring = ring;
        }
        
        public void run() {
            String messages[] = {
                "Act in haste and repent at leisure; Code too soon and debug forever - Raymond Kennington",
                "Simple can be harder than complex: You have to work hard to get your thinking clean to make it simple - Steve Jobs",
                "Find something you love to do, and you'll never work a day in your life - Harvey Mackay",
                "It's really hard to design products by focus groups. A lot of times, people don't know what they want until you show it to them.- Steve Jobs",
                "People who know little are usually great talkers, while men who know much say little - Jean Jacques Rousseau",
                "In theory there is no difference between theory and practice. In practice there is. - Yogi Berra",
                "If a thing is worth doing, it's worth doing well -- unless doing it well takes so long that it isn't worth doing any more. Then you just do it 'good enough'. - Programming perl, Wall and Schwartz"
                };
            
            int max = messages.length;
            int i = 0;
            while (!_terminate) {
                try {
                    _ring.add(messages[i]);
                    printMessage("Added message - " + messages[i]);
                    i++;
                    if (i >= max) {
                        i = 0;
                    }
                    Thread.sleep(2000);
                } catch (InterruptedException ex) {
                    printMessage("Interrupted! But I wasn't done!");
                }
            }
            printMessage("Tschuess! unconsumed: " + _ring.getUnconsumedElements());
        }
        
        public void terminate() {
            _terminate = true;
        }
    }
    
    private static class Reader implements Runnable {
        private RingBuffer<String> _ring = null;
        private volatile boolean _terminate = false;
        private int _interval = 1000;
        
        public Reader(RingBuffer<String> ring, int interval) {
            _ring = ring;
            _interval = interval;
        }
        
        public void run() {
            while (!_terminate) {
                try {
                    String message =_ring.remove();
                    printMessage("Removed message - " + message);
                    Thread.sleep(_interval);
                } catch (InterruptedException ex) {
                    printMessage("Interrupted! But I wasn't done!");
                }
            }
            printMessage("Tschuess! unconsumed: " + _ring.getUnconsumedElements());
        }
        
        public void terminate() {
            _terminate = true;
        }
    }

    /**
     * Display a message, preceded by the name of the current thread.
     * @param msg
     */
    static void printMessage(String msg) {
        String threadName = Thread.currentThread().getName();
        System.out.format("Thread Name:%s: %s%n", threadName, msg);
    }
    
    public static void main(String[] args) {
        RingBuffer<String> ring = new RingBuffer<String>(5);
        
        Writer w1 = new Writer(ring);
        Reader r2 = new Reader(ring, 1000);
        Reader r3 = new Reader(ring, 2000);
        Thread t1 = new Thread(w1);
        t1.start();
        // allow time to add
        try {
            Thread.sleep(1000 * 10);
        } catch (InterruptedException e) {
        }
        Thread t2 = new Thread(r2);
        t2.start();
        Thread t3 = new Thread(r3);       
        t3.start();
        
        try {
            printMessage("Sleeping...");
            Thread.sleep(1000 * 60);
            printMessage("Woke up...");
            w1.terminate();
            t1.interrupt();//join() will block on wait
            r2.terminate();
            t2.interrupt();//join()
            
            r3.terminate();
            t3.interrupt();//join()
        } catch (InterruptedException e) {
        }
        
    }
}