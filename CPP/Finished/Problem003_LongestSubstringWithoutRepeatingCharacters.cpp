/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
#include<iostream>
#include<map>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
		if(n<2){return n;}
		int result=1,current=1,left=0,right=1;
		unordered_map<char,int> positions;
		unordered_map<char,int>::iterator it;
		positions.insert(make_pair(s[0],0));
		while(right<n)
			{it=positions.find(s[right]);
			 if(it==positions.end() or positions[s[right]]==-1)
				{positions[s[right]]=right;
				 current++;
				 if(current>result){result=current;}
				}
			 else
				{//find duplicate
				 int previous=positions[s[right]];
				 positions[s[right]]=right;
				 while(left<previous)//move left pointer until 
					{positions[s[left]]=-1;
					 left++;
					}
				 left=previous+1;
				 current=right-left+1;
				}
			 right++;
			}
		return result;
    }
};

int main()
{
Solution s;
string word="abcabcbb";
cout<<"String= "<<word<<endl;
cout<<s.lengthOfLongestSubstring(word)<<" ="<<3<<endl;
word="bbbbb";
cout<<"String= "<<word<<endl;
cout<<s.lengthOfLongestSubstring(word)<<" ="<<1<<endl;
}
