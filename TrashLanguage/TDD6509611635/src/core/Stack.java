package core;

import java.util.ArrayList;
import java.util.List;

public class Stack implements IStack{
	private List<Object> list;
	private int maxSize;
	
	public Stack() {
		list = new ArrayList<>();
		maxSize = 10;
	}
	
	public boolean isEmpty() {
		return list.isEmpty();
	}
	
	public int getSize() {
		return list.size();
	}
	
	public void push (Object elm) {
		if(list.size() < maxSize) {
			list.add(elm);
		} else {
			
		}
	}
	
	public Object top() {
			return list.get(getSize()-1);
	}
	
	public Object pop() {
		Object elm = top();
		list.remove(getSize()-1);
		return elm;
	}
}
