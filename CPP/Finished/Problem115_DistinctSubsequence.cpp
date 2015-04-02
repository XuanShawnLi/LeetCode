/*
 Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3. 
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int numDistinct(string S, string T) {
    	int ns=S.length();
		int nt=T.length();
		if(ns<nt){return 0;}
		int** dp=new int*[ns];
		for(int i=0;i<ns;i++){
			dp[i]=new int[nt];
			for(int j=0;j<nt;j++)dp[i][j]=0;
		}
		for(int is=ns-1;is>=0;is--){
			int right=max(nt-ns+is,0);
			for(int it=nt-1;it>=right;it--){
				if(S[is]!=T[it]){
					if(is==ns-1){dp[is][it]=0;}
					else{dp[is][it]=dp[is+1][it];}
				}
				else{
					if(is==ns-1){dp[is][it]=1;}
					else if(it==nt-1){dp[is][it]=dp[is+1][it]+1;}
					else{
						dp[is][it]=dp[is+1][it]+dp[is+1][it+1];
					}
				}
			}
		}
		int result=dp[0][0];
		for(int i=0;i<ns;i++){delete[] dp[i];}
		delete[] dp;
		return result;
    }
}; 

int main(){
	Solution s;
	string S="rabbbit";
	string T="rabbit";
	cout<<"S= "<<S<<" and T=: "<<T<<endl;
	cout<<s.numDistinct(S,T)<<endl;
}
