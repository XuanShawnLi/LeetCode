/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n=ratings.size();
		if(n==1){return 1;}
		int *c=new int[n];
		for(int i=0;i<n;i++){c[i]=1;}
		for(int i=1;i<n;i++){
			if(ratings[i]>ratings[i-1]){c[i]=c[i-1]+1;}
		}
		for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){c[i]=max(c[i],c[i+1]+1);}
        }
		int result=0;
		for(int i=0;i<n;i++){result+=c[i];}
		delete[] c;
		return result;
    }
};

#define Size(a) sizeof(a)/sizeof(a[0])

int main(){
	int a[]={1,2,3,1,4,3,2,1};
	int n=Size(a);
	vector<int> ratings(a,a+n);
	Solution s;
	cout<<s.candy(ratings)<<endl;
}
