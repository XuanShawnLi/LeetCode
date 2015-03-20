/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        //step 1 make list
		vector<string> list1=MakeList(version1);
		vector<string> list2=MakeList(version2);
		int n1=list1.size();
		int n2=list2.size();
		int tmp;
		if(n1<n2)
			{list1.insert(list1.end(),n2-n1,"");n1=n2;}
		else if(n1>n2)
			{list2.insert(list2.end(),n1-n2,"");n2=n1;}
		for(int i=0;i<n1;i++)
			{tmp=CompareString(list1[i],list2[i]);
			 if(tmp!=0){return tmp;}
			}
		return 0;
    }

	vector<string> MakeList(string word){
		vector<string> result;
		int n=word.length();
		int i=0;int left=0;
		while(i<n)
			{while(i<n and word[i]!='.'){i++;}
			 if(i==n){result.push_back(word.substr(left,n-left));break;}			 
			 result.push_back(word.substr(left,i-left));
			 i++;left=i;
			}
		return result;
	}

	int CompareString(string s1,string s2){
		s1.erase(0, s1.find_first_not_of('0'));
		s2.erase(0, s2.find_first_not_of('0'));
		int n1=s1.length();
		int n2=s2.length();
		if(n1<n2){return -1;}
		else if(n1>n2){return 1;}
		for(int i=0;i<n1;i++)
			{if(s1[i]<s2[i]){return -1;}
			 else if(s1[i]>s2[i]){return 1;}
			}
		return 0;
	}
};

int main()
{
Solution s;
string s1="13.37";
string s2="4.2.3";
cout<<s1<<" : "<<s2<<endl;
cout<<s.compareVersion(s1,s2)<<endl;
s1="01";
s2="1";
cout<<s1<<" : "<<s2<<endl;
cout<<s.compareVersion(s1,s2)<<endl;
s1="1.0";
s2="1";
cout<<s1<<" : "<<s2<<endl;
cout<<s.compareVersion(s1,s2)<<endl;
}

