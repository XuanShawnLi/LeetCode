/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
       //construct the result by every binary digit, key (3*1 or 3*0)%3=0
		if(n==1){return A[0];}
		int nd=31;int result=0;
		int nnegative=0;int base=1;int i_max=0;
		for(int i=0;i<n;i++){
			if(A[i]==-2147483648){A[i]=0;i_max++;}
			else if(A[i]<0){A[i]=-A[i];nnegative++;}
		}
		if(i_max==1){return -2147483648;}
		for(int id=0;id<nd;id++){
			int tmp=0;
			for(int i=0;i<n;i++){
				tmp+=A[i]%2;A[i]=A[i]/2;
			}
			result+=(tmp%3)*base;
			base*=2;
		}
		if(nnegative%3==0){return result;}
		return -result;  
    }
};

#define Size(a) sizeof(a)/sizeof(a[0])

int main(){
	//int A[]={1,1,1,2,2,2,3,4,4,4};
	int A[]={-401451,-177656,-2147483646,-473874,-814645,-2147483646,-852036,-457533,-401451,-473874,-401451,-216555,-917279,-457533,-852036,-457533,-177656,-2147483646,-177656,-917279,-473874,-852036,-917279,-216555,-814645,2147483645,-2147483648,2147483645,-814645,2147483645,-216555};
	int n=Size(A);
	Solution s;
	cout<<s.singleNumber(A,n)<<endl;
}
