class minheaps{
    int[] arr;
    int count;
    minheaps(int n){
        arr=new int[n];
        count=0;
    }
    void minHeapify(int i){
        int left=2*i+1;
        int right=2*(i+1);
        if (count>=right){
            int l=min(arr[i],arr[left],arr[right]);
            if (l==arr[left]){
                int temp=arr[left];
                arr[left]=arr[i];
                arr[i]=temp;
                minHeapify(left);
            }
            else if (l==arr[right]) {
                int temp=arr[right];
                arr[right]=arr[i];
                arr[i]=temp;
                minHeapify(right);
            }
        }
        else if(count>=left){
            int l=arr[i]<arr[left]?arr[i]:arr[left];
            if (l==arr[left]){
                int temp=arr[left];
                arr[left]=arr[i];
                arr[i]=temp;
                minHeapify(left);
            }
        }
    }
    int min(int a, int b, int c){
        if(a<b && a<c){
            return a;
        }
        else if(b<a && b<c){
            return b;
        }
        else{
            return c;
        }
    }
    void insert(int n){
        arr[count]=n;
        count+=1;
        check(count-1);
    }

    void check(int i){
        int p;
        if (i%2==0){
            p=i/2-1;
        }
        else {
            p=(i-1)/2;
        }
        if(p>=0){
            if(arr[p]>arr[i]){
                int temp=arr[p];
                arr[p]=arr[i];
                arr[i]=temp;
                check(p);
            }
        }
    }
    void extractMin(){
        if(count>0){
            System.out.println(arr[0]);
            arr[0]=arr[count-1];
            count-=1;
            minHeapify(0);
        }
    }
    public static void main(String[] args){
        int[] arr={2,5,6,1,9,24,55,11};
        minheaps A=new minheaps(8);
        for (int i=0;i<8;i++){
            A.insert(arr[i]);
        }
        for (int i=0;i<8;i++){
            A.extractMin();
        }
    }
}
