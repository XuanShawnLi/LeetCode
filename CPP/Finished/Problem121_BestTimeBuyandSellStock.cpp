/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
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
		for(int i=1;i<n;i++)
			{if(prices[i]<small)
				{small=prices[i];}
			 else if(prices[i]-small>result)
				{result=prices[i]-small;}
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
cout<<s.maxProfit(prices3)<<" ==4"<<endl;
}
