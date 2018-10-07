#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  int val = 1;
  //LOOP TO PRINT MULTIPLE ROWS
  for(int row=1; row<=n; row++){
    //WORK OF ONE ROW
    val = row;

    //LOOP TO PRINT MULTIPLE COLUMNS
    for(int col=1; col<=row; col++){
      cout<<val<<" ";
      val++;
    }
    cout<<endl;
  }
}
