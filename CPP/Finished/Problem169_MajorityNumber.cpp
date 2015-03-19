/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
#include<iostream>
#include<tr1/unordered_map>
#include<vector>
using namespace std;
using namespace std::tr1;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        unordered_map<int,int> counts;
		unordered_map<int,int>::iterator it;
		int n=num.size();
		if(n==1){return num[0];}
		for(int i=0;i<n;i++)
			{it=counts.find(num[i]);
			 if(it==counts.end())
				{counts.insert(make_pair(num[i],1));}
			 else
				{counts[num[i]]++;
				 if(counts[num[i]]>n/2){return num[i];}
				}
			}
    }
};

#define Size(a) sizeof(a)/sizeof(a[0]);

int main()
{int a[]={1,1,1,1,2,2};
 int n=Size(a);
 vector<int> v(a,a+n);
 Solution s;
 cout<<s.majorityElement(v)<<endl;

}
