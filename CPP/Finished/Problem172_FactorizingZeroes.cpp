/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
#include<iostream>
#include<ctime>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
	int result=0;    
	long base=5;    
	while(n>=base)
		{result+=n/base;
		 base*=5;
		}
	return result;
    }
};

int main()
{Solution s;
 int n=20;
 time_t t1=clock();
 cout<<n<<" trailing:"<<s.trailingZeroes(n)<<endl;
 cout<<"CPU time="<<clock()-t1<<endl;
 n=200;
 t1=clock();
 cout<<n<<" trailing:"<<s.trailingZeroes(n)<<endl;
 cout<<"CPU time="<<clock()-t1<<endl;
 n=2000;
 t1=clock();
 cout<<n<<" trailing:"<<s.trailingZeroes(n)<<endl;
 cout<<"CPU time="<<clock()-t1<<endl;
 n=2147483647;
  t1=clock();
 cout<<n<<" trailing:"<<s.trailingZeroes(n)<<endl;
 cout<<"CPU time="<<clock()-t1<<endl;
 n=1808548329;
 t1=clock();
 cout<<n<<" trailing:"<<s.trailingZeroes(n)<<endl;
 cout<<"CPU time="<<clock()-t1<<endl;
}
