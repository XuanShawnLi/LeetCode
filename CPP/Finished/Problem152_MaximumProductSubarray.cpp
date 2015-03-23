/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
		if(n==1){return A[0];}
		int pos=0,neg=0,result=-0xfffffff;
		//pos: largest contiguous positive ending with the current element
		//neg: -largest continous negative ending with the current element
		for(int i=0;i<n;i++)
			{if(A[i]>0)
				{pos=max(pos*A[i],A[i]);//if zero then new pos, if nonzero=> getting better
				 result=max(result,pos);
				 neg=neg*A[i];//if zero=> zero, if nonzero=> getting better
				}
			 else if(A[i]<0)
				{int tmp=neg;
				 neg=min(pos*A[i],A[i]);//at least a negative number
				 pos=A[i]*tmp;
				 if(pos>0){result=max(pos,result);}//if pos is good, update it
				 result=max(result,A[i]);//at least it is not -INT_MAX
				}
			 else//zero separates everything and set lower bound to be zero
				{pos=neg=0;
				 if(result<0){result=0;}
				}
			}
		return result;
    }
};

#define Size(a) sizeof(a)/sizeof(a[0])

int main()
{Solution s;
int a[]={2,3,-2,4,0,2,4};
int n=Size(a);
cout<<s.maxProduct(a,n)<<" =8"<<endl;

}
