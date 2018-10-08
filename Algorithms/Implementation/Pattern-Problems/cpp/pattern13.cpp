#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  for(int row=1; row<=n; row++){
    char val = 'D'-row+1;
    for(int col=1; col<=row; col++){
      cout<<val<<" ";
      val++;
    }
    cout<<endl;
  }
}
