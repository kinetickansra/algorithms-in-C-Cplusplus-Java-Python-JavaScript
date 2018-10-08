#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  int val = 1;
  for(int row=1; row<=n; row++){
    if(row%2==0){
      val = val+row;
      int subVal = val-1;
      for(int col=1; col<=row; col++){
        cout<<subVal<<" ";
        subVal--;
      }
    }
    else{
      for(int col=1; col<=row; col++){
        cout<<val<<" ";
        val++;
      }
    }
    cout<<endl;
  }

}
