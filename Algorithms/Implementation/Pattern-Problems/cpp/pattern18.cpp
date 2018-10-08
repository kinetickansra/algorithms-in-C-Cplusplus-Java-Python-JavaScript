#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  if(n%2==0){
    cout<<"n should be an odd number"<<endl;
    return 0;
  }

  int mid = (n/2) +1;
  for(int row=1; row<=mid; row++){
    for(int col=1; col<=row; col++){
      cout<<"* ";
    }
    cout<<endl;
  }

  //row -= 2;

  for(int row=mid-1; row>=1; row--){
    for(int col=1; col<=row; col++){
      cout<<"* ";
    }
    cout<<endl;
  }


}
