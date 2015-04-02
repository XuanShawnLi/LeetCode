/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n=triangle.size();
		if(n==1){return triangle[0][0];}
		int* dp_even=new int[n];
		int* dp_odd=new int[n];
		dp_even[0]=triangle[0][0];
		for(int i=1;i<n;i++){
			if(i%2==0){//even rows
				//first element
                dp_even[0]=triangle[i][0]+dp_odd[0];
                for(int j=1;j<i;j++){
                    dp_even[j]=triangle[i][j]+min(dp_odd[j-1],dp_odd[j]);
				}
                //last element
                dp_even[i]=triangle[i][i]+dp_odd[i-1];
			}
			else{//odd rows
				//first element
				dp_odd[0]=triangle[i][0]+dp_even[0];
				for(int j=1;j<i;j++){
					dp_odd[j]=triangle[i][j]+min(dp_even[j-1],dp_even[j]);
				}
				//last element
				dp_odd[i]=triangle[i][i]+dp_even[i-1];
			}
		}
		int result;
		if(n%2==0){
			result=*min_element(dp_odd,dp_odd+n);
		}
		else{
			result=*min_element(dp_even,dp_even+n);
		}
		delete[] dp_even;
		delete[] dp_odd;
		return result;
    }
};

int main(){
	const int n=4;
	vector<vector<int> > triangle;
	triangle.push_back(vector<int>(1,2));
	triangle.push_back(vector<int>(2,3));
	triangle[1][1]=4;
	triangle.push_back(vector<int>(3,6));
    triangle[2][1]=5;triangle[2][2]=7;
	triangle.push_back(vector<int>(4,4));
    triangle[3][1]=1;triangle[3][2]=8;triangle[3][3]=3;
	Solution s;
	cout<<s.minimumTotal(triangle)<<"==11"<<endl;	
}
