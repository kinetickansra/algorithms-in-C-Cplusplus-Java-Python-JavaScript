
public class LinkedList {
	private class Node {
		int data;
		Node next;

	}

	private Node head;
	private Node tail;
	private int size;

	int size() {
		return size;

	}

	boolean isEmpty() {
		return size == 0;

	}

	void display() {
		for (Node temp = head; temp != null; temp = temp.next) {
			System.out.print(temp.data + " ");
		}
		System.out.println();
	}

	void addFirst(int value) {
		if (size == 0) {
			handleZSize(value);
			return;
		}
		Node temp = new Node();
		temp.data = value;
		temp.next = head;
		this.head = temp;
		size++;

	}

	void addLast(int value) {
		if (size == 0) {
			handleZSize(value);
			return;
		}
		Node temp = new Node();
		temp.data = value;
		this.tail.next = temp;
		this.tail = temp;
		size++;
	}

	void handleZSize(int value) {
		Node temp = new Node();
		temp.data = value;
		head = temp;
		tail = temp;
		size++;
		// temp.data=value;
	} 

	int getFirst() {
		// Node temp=head;
		return head.data;
	}

	int getLast() {
		// Node temp=tail;
		return tail.data;
	}

	int getAt(int idx) {
		if (size < 0 || idx >= size) {
			System.out.println("Index Out Of Bounds");
			return -1;
		}
		Node temp = head;
		for (int i = 0; i < idx; i++) {
			temp = temp.next;
		}
		return temp.data;
	}

	private Node getNodeAt(int idx) {
		if (size < 0 || idx >= size) {
			System.out.println("Index Out Of Bounds");
			return null;
		}
		Node temp = head;
		for (int i = 0; i < idx; i++) {
			temp = temp.next;
		}
		return temp;
	}

	void addAt(int value, int idx) {
		if (idx < 0 || idx >= size) {
			System.out.println("out of bound");
			return;
		}
		if (idx == 0)
			addFirst(value);
		else if (idx == size)
			addLast(value);
		else {
			Node temp = new Node();
			temp.data = value;
			Node im1 = getNodeAt(idx - 1);
			temp.next = im1.next;
			im1.next = temp;
		}
	}

	int removeFirst() {

		if (size == 0) {
			System.out.println("Underflow");
			return -1;
		} else if (size == 1) {
			return handleSizeOneRemoval();

		} else {
			Node temp = head;
			Node ip1 = temp.next;
			head = ip1;
			return temp.data;
		}
	}

	int removeLast() {
		if (size == 0) {
			System.out.println("Underflow");
			return -1;
		} else if (size == 1) {
			return handleSizeOneRemoval();

		} else {
			Node temp = tail;
			Node im1 = getNodeAt(size - 2);
			tail = im1;
			return temp.data;
		}
	}

	int removeAt(int idx) {
		if (size < 0 || idx >= size) {
			System.out.println("Index Out Of Bounds");
			return -1;
		} else if (size == 0) {
			System.out.println("Underflow");
			return -1;
		} else if (size == 1) {
			return handleSizeOneRemoval();

		} else {
			Node im1 = getNodeAt(idx - 1);
			Node i = im1.next;
			Node ip1 = i.next;
			im1.next = ip1;
			// i.next=null;
			// This line is not required in java but is in c++.
			// This due to garbage collection algo of java called mark and sweep
			return i.data;

		}

	}

	private int handleSizeOneRemoval() {
		int temp = head.data;
		head = tail = null;
		size = 0;
		return temp;
	}

	public void reverseDataIteratively() {
		for (int i = 0; i < size / 2; i++) {
			Node f = getNodeAt(i);
			Node s = getNodeAt(size - 1 - i);
			int tem = f.data;
			f.data = s.data;
			s.data = tem;
		}
	}

	public void reversePointerIterative() {

		Node prev = null;
		Node curr = head;
		while (curr != null) {
			Node ocnext = curr.next;
			curr.next = prev;
			prev = curr;
			curr = ocnext;

		}
		Node t = head; 
		head = tail;
		tail = t;

	}

	public void displayReverse() {
		recurseRev(head);

	}
 
	private void recurseRev(Node curr) {
		if (curr == null)
			return;
		recurseRev(curr.next);
		System.out.print(curr.data + " ");

	}

	public void reversePointerrecursive() {
		reversePointerRecursive(head);
		Node tem = head;
		head = tail;
		tail = tem;
		tail.next = null;
	}

	private void reversePointerRecursive(Node curr) {
		if (curr.next == null)
			return;
		reversePointerRecursive(curr.next);
		curr.next.next = curr;

	}

	public void reverseDataRecursivly() {

		heapMover left = new heapMover();
		left.node = this.head;
		reverseDataRecursivly(left, head, 0);
	}

	private class heapMover {
		Node node;
	} 

	private void reverseDataRecursivly(heapMover left, Node right, int counter) {
		if (right == null)
			return;
		reverseDataRecursivly(left, right.next, counter + 1);
		if (counter >= size / 2) {

			int t = left.node.data;
			left.node.data = right.data;
			right.data = t;
			left.node = left.node.next;

		}
	}

	public void fold() {
		heapMover left = new heapMover();
		left.node = this.head;
		fold(left, head, 0); 
	}

	private void fold(heapMover left, Node right, int counter) {
		if (right == null)
			return;
		fold(left, right.next, counter + 1);
		if (counter > size / 2) {

			Node ocnext = left.node.next;
			left.node.next = right;
			right.next = ocnext;
			left.node = ocnext;

		} else if (counter == size / 2) {
			tail = right;
			tail.next = null; 
		}
	}
	public boolean isPalindrome(){
		heapMover left = new heapMover();
		left.node = this.head; 
		return isPalindrome(left, head, 0); 
	} 
	private boolean isPalindrome(heapMover left, Node right, int counter){
		if (right == null)
			return true; 
		boolean f=isPalindrome(left, right.next, counter + 1);
		if (counter >= size / 2) {

			//int t = left.node.data;
			if(left.node.data != right.data)
			   {left.node = left.node.next;return f=false;}
			left.node = left.node.next;
			   
		} 
		return f;   
	}
	public int mid(){
	 Node slow=head;Node fast=head;	

	 while(fast!=null&&fast.next!=null)  
	 { 
		 slow=slow.next; 
		 fast=fast.next.next; 
		  
	 }
	 return slow.data; 
	}

}
