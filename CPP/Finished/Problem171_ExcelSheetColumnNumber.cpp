/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
#include<iostream>
using namespace std;

class Solution {
public:
	int Bucket['Z'];

	Solution(){
		for(int i=0;i<26;i++)
			{Bucket['A'+i]=i+1;
			}
	}

    int titleToNumber(string s) {
        int n=s.length();
		int result=0;
		int base=1;
		for(int i=n-1;i>=0;i--)
			{result+=Bucket[s[i]]*base;
			 base*=26;
			}
		return result;
    }
};

int main()
{Solution s;
 string a="A";
 cout<<a<<" "<<s.titleToNumber(a)<<endl;
 a="AB";
 cout<<a<<" "<<s.titleToNumber(a)<<endl;
 a="BA";
 cout<<a<<" "<<s.titleToNumber(a)<<endl;

}
