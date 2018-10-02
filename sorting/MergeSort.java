class MergeSort{
    public static void main(String[] args){
        int [] arr={5,4,1,2,7,6,8};
        mergesort(arr,0,6);
        for (int i=0;i<7 ;i++ ) {
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    
    static void mergesort(int[] arr, int l, int h){
        if (l<h){
            int mid=(h+l)/2;
            mergesort(arr,l,mid);
            mergesort(arr,mid+1,h);
            merge(arr,l,mid,h);
        }
    }
    static void merge(int[] arr, int l,int mid ,int h){
        int i=l,j=mid+1,k=0;
        int[] temp=new int[h-l+1];
        while (i<=mid && j<=h){
            if (arr[i]<=arr[j]){
                temp[k]=arr[i];
                i++;
            }
            else{
                temp[k]=arr[j];
                j++;
            }
            k++;
        }
        while(i<=mid){
            temp[k]=arr[i];
            i++;
            k++;
        }
        while(j<=h){
            temp[k]=arr[j];
            j++;
            k++;
        }
        for (int p=0;p<=h-l;p++){
            arr[l+p]=temp[p];
        }
    }
}