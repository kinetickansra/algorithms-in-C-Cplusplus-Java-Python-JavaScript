#include<iostream.h>
#include<conio.h>


void merge_sort(int arr[],int low,int mid,int high){

	int temp[100];
	int end = mid-1;

	int i,j,k;
	i = k = low;
	j = mid;

	while(i<=end&&j<=high){

		if(arr[i]<arr[j]){
			temp[k] = arr[i];
			i++;
		}

		else{
			temp[k] = arr[j];
			j++;
		}

		k++;
	}

	while(i<=end){
		temp[k++] = arr[i++];
	}

	while(j<=high){
		temp[k++] = arr[j++];
	}

	cout<<"dafasfdsaf   ";

	for(i =0;i<=(high-low);++i){
		arr[low+i] = temp[low+i];

		cout<<arr[low+i]<<"  ";
	}

	cout<<endl;
}




void merge_divide(int arr[],int low,int high){

	int mid;

	if(low<high){

	    mid = (low+high)/2;

	    merge_divide(arr,low,mid);
	    merge_divide(arr,mid+1,high);

	    merge_sort(arr,low,mid+1,high);

	}


}



void main(){

	clrscr();

	int low = 0;
	int high = 5;
	int arr[6]={6,5,4,3,2,-1};

	for(int i = 0;i<=high;++i){
		cout<<arr[i]<<"   ";
	}

	cout<<endl;

	merge_divide(arr,low,high);

	cout<<"output"<<endl;

	for(i = 0;i<=high;++i){
		cout<<arr[i]<<endl;
	}

	getch();
}