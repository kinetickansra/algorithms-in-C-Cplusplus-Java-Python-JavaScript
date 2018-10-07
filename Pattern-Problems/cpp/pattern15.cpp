#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  for(int row=n; row>=1; row--){

    for(int spaces=1; spaces<=n-row; spaces++){
      cout<<"  ";
    }

    char val = 'A';
    for(int col=1; col<=row; col++){
      cout<<val<<" ";
      val++;
    }
    val--;
    for(int col=row; col>=1; col--){
      cout<<val<<" ";
      val--;
    }
    cout<<endl;
  }
}
