package segmentTrees;

public class FenwickTree {

	int[] farr;
	public FenwickTree(int[] arr){
		farr=new int[arr.length+1];
		for(int i=0;i<arr.length;i++)
		{
			update(i,arr[i]);
		}
		
	}
	
	public int getSum(int l,int r){
		int sumj=getPrefixSum(r);
		int sumni=getPrefixSum(l-1);
		return sumj-sumni; 
	}
	public void update(int idx,int delta){
		idx++;
		while(idx<farr.length){
			farr[idx]+=delta;
			idx+=getLastSetBit(idx);//To get to those who get impacted
		}
	}
	private int getLastSetBit(int a){
		return a&-a;
	}
	private int getPrefixSum(int idx){
		int sum=0;idx++; 
		while(idx!=0){
		    sum+=farr[idx];
			idx-=getLastSetBit(idx);//To get to parent
		}
		return sum; 
	}

}