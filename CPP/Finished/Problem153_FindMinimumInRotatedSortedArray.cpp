/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
		int n=num.size();
		if(n==1){return num[0];}
		int left=0,right=n-1;
		while(left<right)
			{if(left==right-1){return min(num[left],num[right]);}
			 int middle=(left+right)/2;
			 if(num[left]<num[middle])
				{if(num[middle]>num[right])//look to the right
					{left=middle+1;}
				 else//look to the left
					{right=middle-1;}
				}
			 else//left>middle
				{right=middle;}
			}
		return num[left];
    }

	void PrintArray(int* a, int n)
		{cout<<"Array= ";
		 for(int i=0;i<n;i++){cout<<a[i]<<" ";}
		 cout<<endl;
		}

	void RotateArray(int *a,int n)
		{int tmp=a[0];
		 for(int i=0;i<n-1;i++){a[i]=a[i+1];}
		 a[n-1]=tmp;
		}
};

#define Size(a) sizeof(a)/sizeof(a[0])

int main()
{Solution s;
 int a[]={0,1,2,3,4,5,6,7};
 int n=Size(a);
 for (int i=0;i<n;i++)
	{s.PrintArray(a,n);
	 vector<int> num(a,a+n);
	 cout<<s.findMin(num)<<" == "<<0<<endl;
	 s.RotateArray(a,n);
	}

}
