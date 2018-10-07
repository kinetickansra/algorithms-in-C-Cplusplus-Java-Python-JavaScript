#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  for(int row=1; row<=n; row++){
    int val = n-row+1;
    for(int col=1; col<=row; col++){
      cout<<val<<" ";
      val++;
    }
    //n-row times n
    for(int col=1; col<=n-row; col++){
      cout<<n<<" ";
    }
    cout<<endl;
  }

}
