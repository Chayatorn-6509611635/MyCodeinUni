package core;

/*
 * Teeraphat Siritham
 * ID 6509611809
 * 
 * */

public interface IStack {
	boolean isEmpty();
	boolean isFull();
	int getSize();
	void push(Object e);
	Object pop();
	Object top();
	
}
