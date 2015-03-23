/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int> &num) {
		int n=num.size();
		if(n==1){return num[0];}
		if(n==2){return min(num[0],num[1]);}
        int left=0,right=n;
		int result=0xfffffff;
		while(left!=right)
			{
			 int middle=(left+right)/2;
			 if(num[middle]>num[left])//on the right with the possibility that the array was not rotated
				{result=min(result,num[left]);
				 left=middle+1;
				}
			 else if(num[middle]<num[left])//on the left with the possibility it is the middle
				{result=min(result,num[middle]);
				 right=middle;
				}
			 else
				{result=min(result,num[left]);
				 left++;
				}
			}
			return result;
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
 //int a[]={0,1,2,3,4,5,6,7};
 int a[]={4,4,4,4,1,4,4};
 int n=Size(a);
 for (int i=0;i<n;i++)
    {s.PrintArray(a,n);
     vector<int> num(a,a+n);
     cout<<s.findMin(num)<<" == "<<0<<endl;
     s.RotateArray(a,n);
    }

}
