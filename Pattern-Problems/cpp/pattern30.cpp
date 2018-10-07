#include <iostream>
using namespace std;

int main(){
  cout<<"Enter n : ";
  int n;
  cin>>n;

  if(n%2==0){
    cout<<"n should be an odd number"<<endl;
    return 0;
  }

  for(int stars=1; stars<=n; stars++){
    cout<<"* ";
  }
  cout<<endl;
  int mid = ((n-2)/2) +1;
  for(int row=1; row<=mid; row++){
    int numSpaces = (2*row) - 1;
    int numCol = (n/2)-row+1;
    for(int col=1; col<=numCol; col++){
      cout<<"* ";
    }

    for(int spaces=1; spaces<= numSpaces; spaces++){
      cout<<"  ";
    }

    for(int col=1; col<=numCol; col++){
      cout<<"* ";
    }
    cout<<endl;
  }

  for(int row=mid-1; row>=1; row--){
    int numSpaces = (2*row) - 1;
    int numCol = (n/2)-row+1;
    for(int col=1; col<=numCol; col++){
      cout<<"* ";
    }

    for(int spaces=1; spaces<= numSpaces; spaces++){
      cout<<"  ";
    }

    for(int col=1; col<=numCol; col++){
      cout<<"* ";
    }
    cout<<endl;
  }

  for(int stars=1; stars<=n; stars++){
    cout<<"* ";
  }
  cout<<endl;
}
