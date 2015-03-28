/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<string> > partition(string &s) {
		//38ms
		vector<vector<string> > result;
		int n=s.length();
		if(n==0){return result;}
		vector<vector<int> > dp;
		//dp[i] has a list of lengths of up to which index such that [i,dp[i][j]] is a paindrome       
		CreateDP(s,dp);
		vector<string> previous;int start=0;
		for(int j=0;j<dp[start].size();j++){
			int Len=dp[start][j];
            previous.push_back(s.substr(start,Len));
            partition_sub(s,dp,start+Len,previous,result);
            previous.pop_back();
		}
		return result;
    }

	void partition_sub(string &s, vector<vector<int> > &dp, int start, vector<string> previous, vector<vector<string> > &result){
		int n=s.length();
		if(start==n){result.push_back(previous);return;}
		for(int j=0;j<dp[start].size();j++){
			int Len=dp[start][j];
            previous.push_back(s.substr(start,Len));
            partition_sub(s,dp,start+Len,previous,result);
			previous.pop_back();
        }
	} 

	void CreateDP(string &s, vector<vector<int> > &dp){
		//create DP
		int n=s.length();
		for(int i=0;i<n;i++){vector<int> current(1,1);dp.push_back(current);}
		//start DP
		//odd
		for(int i=0;i<n;i++){
			int left=i-1,right=i+1;
			while(left>=0 and right<n and s[left]==s[right]){
				dp[left].push_back(right-left+1);
				left--;right++;
			}
		}
		//even and i is the left center
		for(int i=0;i<n-1;i++){
			if(s[i]==s[i+1]){
				dp[i].push_back(2);
            	int left=i-1,right=i+2;
            	while(left>=0 and right<n and s[left]==s[right]){
                	dp[left].push_back(right-left+1);
                	left--;right++;
            	}
			}
        }
	}
};

int main(){
	Solution s;
	string word = "aab";
	cout<<"string="<<word<<endl;
	vector<vector<string> > result=s.partition(word);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<",";
		}
		cout<<endl;
	}
}
