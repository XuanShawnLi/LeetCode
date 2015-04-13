//
//  Problem090_SubsetsII.cpp
//  LeetCode
//
//  Created by Xuan Li on 4/13/15.
//  Copyright (c) 2015 Xuan Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:

[
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
 ]
*/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        int n=S.size();
        vector<vector<int> > result;
        if(n==0)return result;
        unordered_map<int, int> Counts;
        vector<int> Unique;
        for(int i=0;i<n;i++){
            if(Counts.find(S[i])==Counts.end()){
                Counts[S[i]]=1;
                Unique.push_back(S[i]);
            }
            else{
                Counts[S[i]]++;
            }
        }
        sort(Unique.begin(),Unique.end());
        vector<int> previous;
        Counts[Unique[0]]--;
        if(Counts[Unique[0]]>0){
            Helper(Unique,1,Counts,previous,result);
        }
        else{
            Helper(Unique,0,Counts,previous,result);
        }
        previous.push_back(Unique[0]);
        Helper(Unique,0,Counts,previous,result);
        return result;
    }
    
    void Helper(vector<int>& Unique, int index, unordered_map<int, int> &Counts, vector<int> previous, vector<vector<int> > &result){
        if(index==Unique.size()){
            //cout<<"Finalize with previous size "<<previous.size()<<endl;
            result.push_back(previous);
            return;
        }
        if(Counts[Unique[index]]==0){
            //cout<<"Element "<<Unique[index]<<" has used up"<<endl;
            Helper(Unique,index+1,Counts,previous,result);
            return;
        }
        //cout<<"Now we are touching element"<<Unique[index]<<" with previous size "<<previous.size()<<endl;
        Counts[Unique[index]]--;
        if(Counts[Unique[index]]>0){
            Helper(Unique,index+1,Counts,previous,result);
        }
        else{
            Helper(Unique,index,Counts,previous,result);
        }
        previous.push_back(Unique[index]);
        Helper(Unique,index,Counts,previous,result);
        Counts[Unique[index]]++;
    }
};

#define Size(a) sizeof(a)/sizeof(a[0])

void Problem090(){
    Solution s;
    int a[]={1,1};
    vector<int> S(a,a+Size(a));
    vector<vector<int> >result=s.subsetsWithDup(S);
    for(int i=0;i<result.size();i++){
        cout<<"[ ";
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
}
