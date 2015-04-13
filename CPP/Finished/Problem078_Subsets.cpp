//
//  Problem076_Subsets.cpp
//  LeetCode
//
//  Created by Xuan Li on 4/13/15.
//  Copyright (c) 2015 Xuan Li. All rights reserved.
//

#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
/*
Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example,
If S = [1,2,3], a solution is:

[
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
 ]
*/

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> >result;
        int n=S.size();
        if(n==0)return result;
        sort(S.begin(),S.end());
        vector<int> previous;
        Helper(S,1,previous,result);
        previous.push_back(S[0]);
        Helper(S,1,previous,result);
        return result;
    }
    
    void Helper(vector<int> &S, int i, vector<int>  previous, vector<vector<int> > &result){
        //cout<<"current "<<previous.size()<<" with current i="<<i<<endl;
        if(i==S.size()){
            result.push_back(previous);
            return;
        }
        Helper(S,i+1,previous,result);
        previous.push_back(S[i]);
        Helper(S,i+1,previous,result);
    }
};

#define Size(a) sizeof(a)/sizeof(a[0])

void Problem078(){
    Solution s;
    int a[]={4,1,0};
    cout<<"hello"<<endl;//exit(1);
    vector<int> S(a,a+Size(a));
    vector<vector<int> >result=s.subsets(S);
    for(int i=0;i<result.size();i++){
        cout<<"[ ";
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    

}
