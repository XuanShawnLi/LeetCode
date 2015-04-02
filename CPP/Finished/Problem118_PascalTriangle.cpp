/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
		if(numRows==0){return result;}
		result.push_back(vector<int>(1,1));
		for(int i=1;i<numRows;i++){
			vector<int> tmp(1,1);
			for(int j=1;j<i;j++){
				tmp.push_back(result[i-1][j-1]+result[i-1][j]);
			}
			tmp.push_back(1);
			result.push_back(tmp);
		}
		return result;
    }
	
	void PrintVector(vector<vector<int> > result){
		int n=result.size();
		cout<<"["<<endl;
		for(int i=0;i<result.size();i++){
			cout<<"[";
			for(int j=0;j<result[i].size();j++){
				cout<<result[i][j]<<" ";
			}
			cout<<"]"<<endl;
		}
		cout<<"]"<<endl;
	}
};

int main(){
	Solution s;
	int n=1;
	vector<vector<int> > result=s.generate(n);
	s.PrintVector(result);

}
