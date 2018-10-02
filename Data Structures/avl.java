
class avl{
    Node root;
    avl(){
        root=null;
    }
    int checkRotate(Node p){
        if(height(p.right)>height(p.left)){
            if(height(p.right.left)>height(p.right.right)){
                return 3;
            }
            else{
                return 4;
            }
        }
        else{
            if(height(p.left.left)>height(p.left.right)){
                return 1;
            }
            else{
                return 2;
            }
        }
    }
    Node insert(Node n){
        if(root==null){
            root=n;
            return root;
        }
        return(ini(root,n));
    }
    Node rightRotate(Node y) {
        if (t==1){
            Node x = y.left;
            Node temp = x.right;
            x.right = y;
            y.left = temp;
            return x;
        }
        return null;
    }
    Node leftRotate(Node x) {
        if (t==1){
            Node y = x.right;
            Node temp = y.left;
            y.left = x;
            x.right = temp;
            return y;
        }
        return null;
    }
    Node ini(Node x,Node n){
        if(x==null){
            return (n);
        }
        else if (x.data>=n.data){
            x.left=ini(x.left,n);
        }
        else if (x.data<n.data){
            x.right=ini(x.right,n);
        }
        boolean p=checkAvl(x);
        if (p==false){
            //System.out.println(p.data);
            int y=checkRotate(x);
            //System.out.println(x);
            if(y==1){
                return rightRotate(x);
            }
            else if(y==2){
                x.left = leftRotate(x.left);
                return rightRotate(x);
            }
            else if (y==3) {
                x.right = rightRotate(x.right);
                return leftRotate(x);
            }
            else if (y==4) {
                return leftRotate(x);
            }
        }
        return x;
    }
    int height(Node p){
        if(p==null){
            return 0;
        }
        return 1+max(height(p.left),height(p.right));
    }
    int t=1;
    int max(int x, int y){
        if(x>y){
            return x;
        }
        return y;
    }
    boolean checkAvl(Node p){
        int x=height(p.left);
        int y=height(p.right);
        if(x==y || x-y==1 || y-x==1){
            return true;
        }
        return false;
    }
    public static void main(String[] args){
        avl A=new avl();
        int[] arr={2,5,6,1,9,24,55,11};
        for (int i=0;i<8;i++){
            Node x=new Node(arr[i]);
            A.root=A.insert(x);
        }
        A.ino(A.root,0,10000);
        System.out.println();
    }

    void ino(Node x,int a,int b){
        int flag=0;
        if(x!=null){
            ino(x.left,a,b);
            System.out.print(x.data+" ");
            ino(x.right,a,b);
        }
    }
}

class Node{
    int data;
    Node left,right;
    Node(int n){
        data=n;
        left=null;
        right=null;
    }
}
