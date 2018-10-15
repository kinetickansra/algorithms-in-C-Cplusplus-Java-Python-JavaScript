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
		int sumni=getPrefixSum(l-1);#include <vector>

namespace segmentTrees
{

	class FenwickTree
	{

	public:
		std::vector<int> farr;
		FenwickTree(std::vector<int> &arr);

		virtual int getSum(int l, int r);
		virtual void update(int idx, int delta);
	private:
		int getLastSetBit(int a);
		int getPrefixSum(int idx);

	};
}

//.cpp file code:

namespace segmentTrees
{

	FenwickTree::FenwickTree(std::vector<int> &arr)
	{
		farr = std::vector<int>(arr.size() + 1);
		for (int i = 0;i < arr.size();i++)
		{
			update(i,arr[i]);
		}

	}

	int FenwickTree::getSum(int l, int r)
	{
		int sumj = getPrefixSum(r);
		int sumni = getPrefixSum(l - 1);
		return sumj - sumni;
	}

	void FenwickTree::update(int idx, int delta)
	{
		idx++;
		while (idx < farr.size())
		{
			farr[idx] += delta;
			idx += getLastSetBit(idx); //To get to those who get impacted
		}
	}

	int FenwickTree::getLastSetBit(int a)
	{
		return a&-a;
	}

	int FenwickTree::getPrefixSum(int idx)
	{
		int sum = 0;
		idx++;
		while (idx != 0)
		{
			sum += farr[idx];
			idx -= getLastSetBit(idx); //To get to parent
		}
		return sum;
	}
}

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
