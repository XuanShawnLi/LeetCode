/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        if(n==1){return A[0];}
		int result=0;
		for(int i=0;i<n;i++){result=result^A[i];}
		return result;
    }
};

#define Size(a) sizeof(a)/sizeof(a[0])

int main(){
	int A[]={1,1,2,2,2,2,4,7,7};
	int n=Size(A);
	Solution s;
	cout<<s.singleNumber(A,n)<<endl;
}
