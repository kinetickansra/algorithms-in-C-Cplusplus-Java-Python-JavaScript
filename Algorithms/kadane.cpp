#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int maxSumSubArray(const vector<int> &A) {
   int n = A.size();
    int curSum = 0, maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        curSum += A[i];
        maxSum = max(maxSum, curSum);
        if (curSum < 0) curSum = 0;
    }
    return maxSum;
}

int main(){
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> v(a,a+9);
	int res = maxSumSubArray(v);
	cout<<res<<endl;
}
