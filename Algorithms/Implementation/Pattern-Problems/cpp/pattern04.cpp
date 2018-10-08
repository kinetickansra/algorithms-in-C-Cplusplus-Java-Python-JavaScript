#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  for(int row=n; row>=1; row--){
    for(int col=1; col<=row; col++){
      cout<<"1 ";
    }
    cout<<endl;
  }
}
