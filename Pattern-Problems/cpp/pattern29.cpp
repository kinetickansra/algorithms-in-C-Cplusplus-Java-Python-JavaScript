#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  for(int row=1; row<=n; row++){

    for(int col=1; col<=row; col++){
      cout<<col<<" ";
    }

    for(int spaces=1; spaces<= 2*(n-row); spaces++){
      cout<<"  ";
    }

    for(int col=row; col>=1; col--){
      cout<<col<<" ";
    }

    cout<<endl;
  }
}
