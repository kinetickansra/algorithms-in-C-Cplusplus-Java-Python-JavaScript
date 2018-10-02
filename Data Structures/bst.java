
class bst{
    Node root;
    bst(){
        root=null;
    }

    public static void main(String[] args){
        bst A=new bst();
        int[ ] arr={2,3,1,5,4,60,36};
        for (int i=0;i<7;i++){
          Node x=new Node(arr[i]);
            A.insert(x);
        }
        inorder(A.root);
        System.out.println();
        A.delet(4);
        inorder(A.root);
        System.out.println();
    }
    void insert(Node n){
        if(root==null){
            root=n;
        }
        else{
            ini(root,n);
        }
    }
    boolean isEmpty(){
        return root==null;
    }
    void ini(Node x,Node n){
        if(x.left==null && x.data>=n.data){
            x.left=n;
        }
        else if(x.right==null && x.data<n.data){
            x.right=n;
        }
        else if (x.data>=n.data){
            ini(x.left,n);
        }
        else if (x.data<n.data){
            ini(x.right,n);
        }
    }
    boolean isRight(Node x,Node p){
        return x.right==p;
    }
    int findMin(Node p){
        int t;
        if (p.left!=null){
            t=findMin(p.left);
        }
        else{
            t=p.data;
        }class Node{
        int data;
        Node left,right;
        Node(int n){
            data=n;
            left=null;
            right=null;
        }
    }
        return t;
    }
    Node delet(int n){
        return delete(root,n);
    }
    Node delete(Node p,int n){
        if(p!=null){
            if (p.data<n){
                p.right= delete(p.right,n);
                return p;
            }
            else if(p.data>n){
                p.left= delete(p.left,n);
                return p;
            }
            else {
                if(p.left==null && p.right== null){
                    return null;
                }
                else if (p.left!=null && p.right!=null){
                    int x=findMin(p.right);
                    p.right=delete(p.right,x);
                    p.data=x;
                    return p;
                }
                else{
                    if(p.left!=null){
                        return p.left;
                    }
                    else{
                        return p.right;
                    }
                }
            }
        }
        return null;
    }



    static void inorder(Node x){
        if(x!=null){
            inorder(x.left);
            System.out.print(x.data+" ");
            inorder(x.right);
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
