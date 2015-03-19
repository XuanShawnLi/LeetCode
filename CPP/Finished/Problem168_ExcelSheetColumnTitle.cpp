/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases.
*/
#include<iostream>
using namespace std;
class Solution {
public:

	char Bucket[26];

	Solution(){
		for(int i=0;i<26;i++)
			{
			 Bucket[i]='A'+i;
			}
	}

    string convertToTitle(int n) {
	string result="";
	while(n>0)
		{
		 result+=Bucket[(n-1)%26];
		 n=(n-1)/26;
		}
	reverse(result.begin(),result.end());
	return result;
    }

    
};

int main()
{Solution s;
for(int i=1;i<=26*26;i++)
	{cout<<i<<"->"<<s.convertToTitle(i)<<endl;}


}
