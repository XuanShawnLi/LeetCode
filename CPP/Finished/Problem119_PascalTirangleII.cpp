/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0){return vector<int>(1,1);}
		if(rowIndex==1){return vector<int>(2,1);}
    	int* dp_odd=new int[rowIndex+1];
		int* dp_even=new int[rowIndex+1];
		dp_odd[0]=1;dp_odd[1]=1;
		for(int i=2;i<=rowIndex;i++){
			if(i%2==0){//construct even
				dp_even[0]=1;dp_even[i]=1;
				for(int j=1;j<i;j++){
					dp_even[j]=dp_odd[j-1]+dp_odd[j];
				}
			}
			else{//construct odd
				dp_odd[0]=1;dp_odd[i]=1;
                for(int j=1;j<i;j++){
                    dp_odd[j]=dp_even[j-1]+dp_even[j];
                }
			}
		}
		if(rowIndex%2==1){
			vector<int> result(dp_odd,dp_odd+rowIndex+1);
			return result;
		}
		else{
			vector<int> result(dp_even,dp_even+rowIndex+1);
            return result;
		}
	}
};

int main(){
	Solution s;
	for(int n=0;n<5;n++){
		cout<<n<<"=[";
		vector<int> result=s.getRow(n);
		for(int j=0;j<result.size();j++){
			cout<<result[j]<<" ";
		}
		cout<<"]"<<endl;
	}
}
