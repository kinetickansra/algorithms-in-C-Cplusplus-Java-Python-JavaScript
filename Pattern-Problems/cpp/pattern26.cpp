#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  for(int row=1; row<=n; row++){

    for(int spaces=1; spaces<=n-row; spaces++){
      cout<<"  ";
    }

    int val=row;
    while(val>=1){
      cout<<val<<" ";
      val--;
    }

    for(int col=2; col<=row; col++){
      cout<<col<<" ";
    }
    cout<<endl;
  }
}
