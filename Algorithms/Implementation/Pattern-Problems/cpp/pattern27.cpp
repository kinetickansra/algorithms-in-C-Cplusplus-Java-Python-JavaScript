#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  for(int row=1; row<=n; row++){
    for (int col=n; col>=1; col--){
      if(col==row){
        cout<<"* ";
      }
      else{
        cout<<col<<" ";
      }
    }
    cout<<endl;
  }
}
