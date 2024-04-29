package core;
import java.util.*;

/*
 * Teeraphat Siritham
 * ID 6509611809
 * 
 * */

public class Stack implements IStack {
	
	 private Object[] s;
	 private int topStack;
	 private int maxSize;
	 
	public Stack() {
		s = new Object[20];
		topStack = -1;
		maxSize = 20;
	}
	public Stack(int size){
		s = new Object[size];
		topStack = -1;
		maxSize = size;
	}
	@Override
	public boolean isEmpty() {
		// TODO Auto-generated method stub
		return topStack == -1;
	}
	public boolean isFull() {
		return topStack == maxSize-1;
	}

	@Override
	public int getSize() {
		// TODO Auto-generated method stub
		return this.topStack+1;
	}
	public void push(Object e) {
		if(isFull()) {
			
		}
		else {
			this.s[++this.topStack] = e;
		}
			
		
	}
	public Object top() {
		return this.s[this.topStack];
	}
	public Object pop() {
		return this.s[this.topStack--];
	}

}
