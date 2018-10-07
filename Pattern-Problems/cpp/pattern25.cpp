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

    for(int col=1; col<=(2*row)-1; col++){
      cout<<"* ";
    }
    cout<<endl;
  }
}
