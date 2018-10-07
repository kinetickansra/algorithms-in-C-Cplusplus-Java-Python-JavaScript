#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  char val = 'A';
  for(int row=1; row<=n; row++){
    for(int col=1; col<=row; col++){
      cout<<val<<" ";
    }
    cout<<endl;
    val++;
  }
}
