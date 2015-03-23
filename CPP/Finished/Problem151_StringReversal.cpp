/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
		//s.erase(0, s.find_first_not_of(' '));
		//s.erase(s.find_last_not_of(" ") + 1);
		vector<string> list;
		int n=s.length();
		int i=0,j;
		while(i<n)
			{//find the first nonspace
			 while(i<n and s[i]==' '){i++;}
			 if(i==n){break;}
			 j=i;
			 while(j<n and s[j]!=' '){j++;}
			 list.push_back(s.substr(i,j-i));
			 i=j;
			}	
		int m=list.size();
		s="";
		for(i=m-1;i>=0;i--){s+=list[i];if(i!=0){s+=" ";}}
	
    }
};

int main()
{string words=" the sky   is blue   ";
 Solution s;
 cout<<"%"<<words<<"%"<<endl;
 s.reverseWords(words);
 cout<<words<<endl;

}
