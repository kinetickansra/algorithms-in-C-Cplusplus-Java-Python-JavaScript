#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  for(int row=1; row<=n; row++){

    for(int space=1; space<=n-row; space++){
      cout<<"  ";
    }

    for(int col=1; col<=row; col++){
      cout<<"1 ";
    }
    cout<<endl;
  }
}
