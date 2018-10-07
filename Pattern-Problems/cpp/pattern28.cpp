#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  for(int row=1; row<=n; row++){
    for(int col=1; col<=n; col++){
      if(col==row){
        cout<<"* ";
      }
      else{
        cout<<"0 ";
      }
    }
    cout<<"* ";
    for(int col=n; col>0; col--){
      if(col==row){
        cout<<"* ";
      }
      else{
        cout<<"0 ";
      }
    }
    cout<<endl;
  }
}
