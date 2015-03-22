/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
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
		int small=prices[0];int is=-1,ib=-1,is_save=0;
		for(int i=1;i<n;i++)
			{if(prices[i]<small)
				{small=prices[i];is_save=i;}
			 else if(prices[i]-small>result)
				{is=is_save;ib=i;result=prices[i]-small;}
			}
		int second=max(max(0,maxProfit_One(prices,0,is-1)),max(maxProfit_One(prices,ib+1,n-1),maxProfit_Reverse(prices,is,ib)));
		return result+second;
    }

	int maxProfit_One(vector<int> &prices,int left, int right) {
        int result=0;
		if(left>=right){return result;}
        int small=prices[left];
        for(int i=left+1;i<=right;i++)
            {if(prices[i]<small)
                {small=prices[i];}
             else if(prices[i]-small>result)
                {result=prices[i]-small;}
            }
		return result;
    }

	int maxProfit_Reverse(vector<int> &prices,int left, int right) {
        int result=0;
        if(left>=right){return result;}
        int small=prices[right];
        for(int i=right-1;i>=left;i--)
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
cout<<s.maxProfit(prices3)<<" ==5"<<endl;

}

