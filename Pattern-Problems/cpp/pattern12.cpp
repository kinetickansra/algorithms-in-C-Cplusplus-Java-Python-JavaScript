#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  for(int row=4; row>=1; row--){
    for(int col=1; col<=row; col++){
      cout<<(row+1)%2<<" ";
    }
    cout<<endl;
  }
}
