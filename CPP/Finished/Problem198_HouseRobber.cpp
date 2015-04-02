/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
		int n=num.size();
		if(n==0){return 0;}
		else if(n==1){return num[0];}
		else if(n==2){return max(num[0],num[1]);}
		int* dp=new int[n];//stores optimal starting (containing) the current element to the end
		int result=0;
		dp[n-1]=num[n-1];dp[n-2]=num[n-2];
		dp[n-3]=num[n-3]+num[n-1];
		for(int i=n-4;i>=0;i--){
			dp[i]=num[i]+max(dp[i+2],dp[i+3]);
		}
		result=max(dp[0],dp[1]);
		delete[] dp;
		return result;
    }
};

#define Size(a) sizeof(a)/sizeof(a[0])
int main(){
	int a[]={1,10,25,19,1,1,6};
	vector<int> num(a,a+Size(a));
	Solution s;
	cout<<s.rob(num)<<"==35"<<endl;
	
}
