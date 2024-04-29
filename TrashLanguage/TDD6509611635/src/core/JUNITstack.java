package core;

import junit.framework.TestCase;

public class JUNITstack extends TestCase {
	public void testCreateNewEmptyStack() {
		Stack s1 = new Stack();
		int size = s1.getSize();

		assertEquals(0, size);
		assertTrue(s1.isEmpty());
	}

	public void testPushElmToTop() {
		Stack s1 = new Stack();
		s1.push(1);
		assertEquals(s1.top(), 1);
	}

	public void testLasInFirstOut() {
		Stack s1 = new Stack();
		s1.push(1);
		s1.push(2);
		s1.push(3);

		int size = s1.getSize();
		Object t1 = s1.top();
		Object t2 = s1.pop();

		assertEquals(t2, t1);
		assertEquals(size - 1, s1.getSize());
	}
}
