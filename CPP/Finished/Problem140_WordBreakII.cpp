/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/
#include<iostream>
#include<tr1/unordered_set>
#include<vector>
using namespace std;
using namespace std::tr1;
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<string> result;
		int n=s.length();
        if(n==0){return result;}
		vector< vector<int> > dp;
		for(int i=0;i<=n;i++){vector<int> tmp; dp.push_back(tmp);}
        dp[n].push_back(-1);//tail element must be non empty
        for(int i=n-1;i>=0;i--){
            for(int l=n-i;l>=1;l--){
				if(not(dp[i+l].empty()) and dict.count(s.substr(i,l))==1){
					dp[i].push_back(l);
                }
            }
        }
		if(dp[0].empty()){return result;}
		ComposeString(s,dp,result);
		return result;
    }

	void ComposeString(string s,vector< vector<int> >& dp, vector<string> &result){
		int n=dp[0].size();
		for(int i=0;i<n;i++){
			int l=dp[0][i];
			ComposeString_sub(s,dp,s.substr(0,l),l,result);
		}
	}

	void ComposeString_sub(string s,vector< vector<int> > &dp, string previous, int start, vector<string> &result){
		if(start==s.length()){result.push_back(previous);return;}
		int n=dp[start].size();
		for(int i=0;i<n;i++){
			int l=dp[start][i];
			ComposeString_sub(s,dp,previous+" "+s.substr(start,l),start+l,result);
		}
	}
};

int main(){
	Solution s;
	string word="catsanddog";
	unordered_set<string> dict;
	dict.insert("cat");dict.insert("cats"),dict.insert("and");
	dict.insert("sand");dict.insert("dog");
	vector<string> result=s.wordBreak(word,dict);
	for(int i=0;i<result.size();i++){
		cout<<"|"<<result[i]<<"|"<<endl;
	}
}
