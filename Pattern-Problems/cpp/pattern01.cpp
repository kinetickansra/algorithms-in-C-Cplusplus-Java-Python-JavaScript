#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  //LOOP TO PRINT MULTIPLE ROWS
  for(int row=1; row<=n; row++){
    //WORK OF ONE ROW

    //LOOP TO PRINT MULTIPLE COLUMNS
    for(int col=1; col<=row; col++){
      cout<<"1 ";
    }
    cout<<endl;
  }
}
