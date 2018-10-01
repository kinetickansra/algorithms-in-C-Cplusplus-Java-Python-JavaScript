package pep5_2Jan;

import java.util.Scanner;

public class BinarySearch {

	public static void main(String[] args) 
	{
     Scanner scn=new Scanner(System.in);
     int N=scn.nextInt();
	 int[] a=new int[N];
	 boolean flag=false;
	 for(int i=0;i<N;i++)
	 {
		 a[i]=scn.nextInt();
	 }
     int low=0,high=(a.length)-1;
     int mid;
    
     int n=scn.nextInt();
     while(high>=low)
     {
    	 mid=(high+low)/2;
    	 if (a[mid]>n)
    	 {
    		high=mid-1;
    	 }
    	 else if (a[mid]<n)
    	 {
    		 low=mid+1;
         }
    	 else if  (a[mid]==n)
    		 {System.out.println(mid);
    		 flag=true;
    		 break;}
    	
     }
     if (flag==false)
     {
    	 System.out.println(-1);
     }
         
	}

}
