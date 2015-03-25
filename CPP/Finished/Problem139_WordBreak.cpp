/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/
#include<iostream>
#include<tr1/unordered_set>
using namespace std;
using namespace std::tr1;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n=s.length();
		if(n==0){return true;}
		bool* dp=new bool[n+1];
		for(int i=0;i<n;i++){dp[i]=false;}
		dp[n]=true;
		for(int i=n-1;i>=0;i--){
			for(int l=n-i;l>=1;l--){
				if(dp[i+l] and dict.count(s.substr(i,l))==1){
					dp[i]=true;break;
				}
			}
		}
		bool result=dp[0];delete[] dp;
		return result;
    }
};

int main(){
	Solution s;
	string word="leetcode";
	unordered_set<string> dict;
	dict.insert("leet");dict.insert("code");
	if(s.wordBreak(word,dict)){cout<<"Yes"<<endl;}
	else{cout<<"No"<<endl;}
}
