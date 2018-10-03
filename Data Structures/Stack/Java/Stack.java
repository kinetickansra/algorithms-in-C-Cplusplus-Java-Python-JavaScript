
public class Stack {

	private int[] data;
	private int tos = -1;// top of stackk 

	public Stack(int capacity) {
		this.data = new int[capacity];
	}

	public Stack()// contructor chaining
	{
		this(5);
	}

	public int top()// tells element at tos
	{
		if (this.tos == -1) {
			System.out.println("Stack UnderFlow");
			return -1;
		}
		int value = this.data[this.tos]; 
		return value;
	}

	public int pop()// element to delete
	{
		// check for underflow
		if (this.tos == -1) {
			System.out.println("Stack UnderFlow");
			return -1;
		}
		int value = this.data[this.tos];
		this.data[this.tos] = 0;
		this.tos--;
		return value;

	}

	public void push(int item) {
		// check for overflow
		if (this.tos == this.data.length - 1) {
			System.out.println("Stack OverFlow");
			return;
		}
		this.tos++;
		this.data[this.tos] = item;
	}

	public boolean isEmpty() {
		if (this.size() == 0)
			return true;
		else
			return false;
	}

	public void display() {
		for (int i = tos; i >= 0; i--) {
			System.out.print(this.data[i] + " "); 
		}
		System.out.println();
	}

	public int size() {
		return this.tos + 1;
	}

}
