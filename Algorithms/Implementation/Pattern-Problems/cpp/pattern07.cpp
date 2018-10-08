#include <iostream>
using namespace std;

int main(){
    cout<<"Enter n : ";
    int n;
    cin>>n;

    int val = 1;

    for(int row=1; row<=n; row++){

      for(int spaces=1; spaces<=n-row; spaces++){
        cout<<"  ";
      }

      for(int col=1; col<=row; col++){
        cout<<val<<" ";
        val++;
      }
      cout<<endl;
    }

}
