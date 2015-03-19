/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Related problem: Reverse Words in a String II

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/
#include<iostream>
using namespace std;

void CopyArray(int* ,int *,int);

class Solution {
public:
    void rotate(int a[], int n, int k) {
    k=k%n;
	int *b=new int[n];	
	CopyArray(a,b,n);
	for(int i=0;i<n-k;i++)
		{a[i+k]=b[i];}
	for(int i=0;i<k;i++)
		{a[i]=b[n-k+i];}
	delete[] b;
    }
};

void PrintArray(int nums[],int n)
{for(int i=0;i<n;i++){cout<<nums[i]<<" ";}cout<<endl;}

void CopyArray(int *a,int* b,int n)
{for(int i=0;i<n;i++){b[i]=a[i];}}

#define Size(a) sizeof(a)/sizeof(a[0]);

int main()
{int a[]={1,2,3,4,5,6,7};
 int n=Size(a);
 int *b=new int[n];
 Solution s;
 for(int k=0;k<2*n;k++)
	{
	 cout<<k<<endl;
	 CopyArray(a,b,n);
 	 s.rotate(b,n,k);
	 PrintArray(b,n);
	}
 delete[] b;
}
