/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

	bool Compare(string a,string b)
		{int n1=a.length();
		 int n2=b.length();
		 for(int i=0;i<min(n1,n2);i++)
			{if(a[i]<b[i]){return true;}
			 else if(a[i]>b[i]){return false;}
			}
		 return a+b<b+a;
		}

class Solution {
public:
    string largestNumber(vector<int> &num) {
	vector<string> list;
	int n=num.size();
	for(int i=0;i<n;i++)
		{stringstream ss;
		 ss<<num[i];
		 list.push_back(ss.str());
		}
	sort(list.begin(),list.end(),Compare);
	string result="";
	for(int i=n-1;i>=0;i--)
	{
	if(result!="0" or list[i]!="0")result+=list[i];}
	return result;
    }
};

int main()
{int a[]={3,30,34,5,9};
 int n=sizeof(a)/sizeof(a[0]);
 vector<int> num(a,a+n);
 Solution s;
 cout<<s.largestNumber(num)<<"=9534330"<<endl;
}
