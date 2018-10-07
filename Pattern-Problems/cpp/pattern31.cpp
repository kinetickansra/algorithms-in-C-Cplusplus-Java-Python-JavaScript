#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  int num = (2*n)-1;

  for(int row=1; row<=n; row++){
    for(int col=1; col<=num; col++){
      if(col==row){
        cout<<row;
      }
      else if(col==num+1-row){
        cout<<row;
      }
      else{
        cout<<" ";
      }
    }
    cout<<endl;
  }

  for(int row=n-1; row>=1; row--){
    for(int col=1; col<=num; col++){
      if(col==row){
        cout<<row;
      }
      else if(col==num+1-row){
        cout<<row;
      }
      else{
        cout<<" ";
      }
    }
    cout<<endl;
  }
}
