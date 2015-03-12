/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
#include<iostream>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
	int n=s.length();
	int r_left=0,r_len=1;
	if(n<2){return s;} 
	for(int c=0;c<n;c++)//odd center
		{int left=c-1,right=c+1;
		 while(left>=0 and right<n and s[left]==s[right]){left--;right++;}
		 if(right-left-1>r_len){r_left=left+1;r_len=right-left-1;}
		}
	for(int c=0;c<n-1;c++)//even left center
		{if(s[c]==s[c+1])
		 	{int left=c-1,right=c+2;
		 	 while(left>=0 and right<n and s[left]==s[right]){left--;right++;}
         	 if(right-left-1>r_len){r_left=left+1;r_len=right-left-1;}
			}
		}
	return s.substr(r_left,r_len);
	}

    string longestPalindrome_DP(string s) {
		int n=s.length();
		if(n<2){return s;}	
		int r_left=0,r_len=1;
		int** dp=new int*[n];
		for(int i=0;i<n;i++){
			dp[i]=new int[n];
			for(int j=0;j<n;j++){dp[i][j]=-1;}//unknown
			dp[i][i]=1;//True
		}
		longestPalindrome_sub(s,0,n-1,r_left,r_len,dp,n);
		for(int i=0;i<n;i++){delete[] dp[i];}
		delete[] dp;
		return s.substr(r_left,r_len);
    }

	void longestPalindrome_sub(string &s,int left,int right,int& r_left, int &r_len, int** dp,int &n){
	if(left>right or dp[left][right]>=0){return;}
	if(s[left]==s[right])
		{
		 if(left==right-1)
			{dp[left][right]=1;
			if(right-left+1>r_len){r_len=right-left+1;r_left=left;}
			}
		 else
			{longestPalindrome_sub(s,left+1,right-1,r_left,r_len,dp,n);
			 if(dp[left+1][right-1]==1)
				{dp[left][right]=1;
				 if(right-left+1>r_len){r_len=right-left+1;r_left=left;}
				}
			 else
				{dp[left][right]=0;}
			}
		}
	 else
		{dp[left][right]=0;
		 longestPalindrome_sub(s,left+1,right,r_left,r_len,dp,n);
		 longestPalindrome_sub(s,left,right-1,r_left,r_len,dp,n);
		}
	}
};

int main()
{string word="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
 Solution s;
 cout<<word<<endl;
 cout<<s.longestPalindrome(word)<<endl;
 word="abcbe";
 cout<<word<<endl;
 cout<<s.longestPalindrome(word)<<endl;
 word="bb";
 cout<<word<<endl;
 cout<<s.longestPalindrome(word)<<endl;
}
