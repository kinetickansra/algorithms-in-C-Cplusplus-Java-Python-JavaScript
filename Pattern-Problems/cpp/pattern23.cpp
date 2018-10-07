#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  cout<<"1"<<endl;

  for(int row=1; row<=n-1; row++){
    cout<<"1 ";
    for(int col=1; col<=row-1; col++){
      cout<<"2 ";
    }
    cout<<"1 ";
    cout<<endl;
  }

}
