package core;

/*
 * Teeraphat Siritham
 * ID 6509611809
 * 
 * */

import static org.junit.jupiter.api.Assertions.*;
import junit.framework.*;

import org.junit.jupiter.api.Test;

public class JUNITStack extends TestCase {

	public void testCreateNewEmptyStack() {
		Stack s1 = new Stack();
		int size = s1.getSize();
		
		assertEquals(size, 0);
		assertTrue(s1.isEmpty());
	}
	
	public void testPushElmToTop() {
		Stack s1 = new Stack();
		s1.push(3);
		boolean check = s1.isEmpty();
		assertFalse(check);
		assertEquals(s1.top(), 3);
	}

	public void testLastInFirstOut() {
		Stack s1 = new Stack();
		s1.push(1);
		s1.push(2);
		s1.push(3);
		assertEquals(s1.pop(), 3);
		assertEquals(s1.pop(), 2);
		assertEquals(s1.pop(), 1);
	}
	public void testPushToFullStack() {
		Stack s1 = new Stack(3);
		for(int i = 0 ; i < 20 ; i++) {
			s1.push(9);
		}
		assertEquals(3, s1.getSize());
		assertTrue(s1.isFull());
	}
	
}
