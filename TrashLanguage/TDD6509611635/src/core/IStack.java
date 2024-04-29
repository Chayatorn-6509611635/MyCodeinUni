package core;

public interface IStack {
	public boolean isEmpty();
	public int getSize();
	public void push (Object elm);
	public Object top();
	public Object pop();
}
