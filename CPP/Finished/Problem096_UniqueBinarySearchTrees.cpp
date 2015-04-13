//
//  Problem96_UniqueBinarySearchTrees.cpp
//  LeetCode
//
//  Created by Xuan Li on 4/9/15.
//  Copyright (c) 2015 Xuan Li. All rights reserved.
//
/*
 Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 
 For example,
 Given n = 3, there are a total of 5 unique BST's.
 
 1         3     3      2      1
  \       /     /      / \      \
   3     2     1      1   3      2
  /     /       \                 \
 2     1         2                 3
*/
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<int, int> dict;
    Solution(){
        dict[0]=1;dict[1]=1;
    }
    
    int numTrees(int n) {
        int left,right;
        for(int i=1;i<=n;i++){
            if(dict.find(i)==dict.end()){
                int current=0;
                for(int j=0;j<i;j++){
                    left=dict[j];
                    right=dict[i-1-j];
                    current+=left*right;
                }
                dict[i]=current;
            }
        }
        return dict[n];
    }
};

void Problem096(){
    Solution s;
    for(int i=1;i<10;i++){
        cout<<i<<": "<<s.numTrees(i)<<endl;
    }
    
}
