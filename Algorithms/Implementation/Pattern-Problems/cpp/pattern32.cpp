#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  int val=1;
  int numCol=1;

  for(int row=1; row<=n; row++){
    for(int i=1; i<=numCol; i++){
      if(val>9){
        val=1;
      }
      cout<<val<<" ";
      val++;
    }
    numCol = numCol*2;
    cout<<endl;
  }
}
