/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int result=0;
		int n=prices.size();
		if(n<2){return result;}
		int small=prices[0];
		int i=1;
		while(i<n)
			{while(i<n and prices[i]>prices[i-1])i++;//find the next decreasing point
			 if(i==n){result+=max(0,prices[n-1]-small);}
			 else
				{result+=max(0,prices[i-1]-small);
				 small=prices[i];
				}
			 i++;
			}
		return result; 
    }
};

#define Size(a) sizeof(a)/sizeof(a[0])

int main()
{Solution s;
int a[]={1,2,3,4};
vector<int> prices1(a,a+Size(a));
cout<<s.maxProfit(prices1)<<" ==3"<<endl;
int b[]={4,3,2,1};
vector<int> prices2(b,b+Size(b));
cout<<s.maxProfit(prices2)<<" ==0"<<endl;
int c[]={1,2,0,4};
vector<int> prices3(c,c+Size(c));
cout<<s.maxProfit(prices3)<<" ==5"<<endl;
}
