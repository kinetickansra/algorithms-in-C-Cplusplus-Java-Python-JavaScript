package segmentTrees;



public class SegmentTree {
	private class Node{
		int rsi;
		int rei;
		int data;
		Node left;
		Node right;
	}
	Node root;
	public SegmentTree(int[] arr){
		this.root=construct(arr, 0, arr.length-1); 
	}
	private Node construct(int[] arr,int lo,int hi){
		
		if(lo==hi){
			Node bn=new Node();
			bn.data=arr[lo];
			bn.rsi=lo;
			bn.rei=hi;
			return bn;
		}
		
		
		Node node=new Node();
		int mid=(lo+hi)/2;
		node.rsi=lo;
		node.rei=hi;
		node.left=construct(arr, lo, mid);
		node.right=construct(arr,mid+1,hi);
		node.data=node.left.data+node.right.data;
		return node;
		
				
	}

	public void display() {
		display(root);
	}
	private void display(Node node) {
		if (node == null)
			return;
		String str = "";
		if (node.left == null)
			str += ". <= ";
		else
			str += node.left.data + " <= ";
		str += node.data + " => ";
		if (node.right == null)
			str += ".";
		else
			str += node.right.data;
		System.out.println(str);
		display(node.left);
		display(node.right);

	}

	public void update(int idx,int delta){
	 update(root, idx, delta); 
		
	}
	private void update(Node node,int idx,int delta)
	{
		if(idx<=node.rei&&idx>=node.rsi)
		{   
			if(node.rei==idx&&node.rsi==idx){
				node.data+=delta;
				return;
				
			}
			update(node.left, idx, delta);
		    update(node.right, idx, delta);
		    node.data=node.left.data+node.right.data; 
			 
		}
		
		
		
	}

	public int query(int qsi,int qei){
		return query(root, qsi, qei);
	}
	private int query(Node node,int qsi,int qei){
		if(qsi<=node.rsi&&qei>=node.rei){
			return node.data;
		}
		else if(qsi>node.rei||qei<node.rsi){
			return 0;
		}
		int n1=query(node.left, qsi, qei);
		int n2=query(node.right, qsi, qei);
		return (n1+n2);  
		
	}
}
