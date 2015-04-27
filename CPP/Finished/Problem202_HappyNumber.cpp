//
//  Problem202_HappyNumber.cpp
//  LeetCode
//
//  Created by Xuan Li on 4/27/15.
//  Copyright (c) 2015 Xuan Li. All rights reserved.
//
/*
 Write an algorithm to determine if a number is "happy".
 
 A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 
 Example: 19 is a happy number
 
 12 + 92 = 82
 82 + 22 = 68
 62 + 82 = 100
 12 + 02 + 02 = 1
*/
#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        if(n<=0)return false;
        if(n==1)return true;
        int count=0;
        int ncount=100;
        while(n!=1){
            n=NewNumber(n);
            count++;
            if(count>ncount)return false;
        }
        return true;
    }
    
    int NewNumber(int n){
        int result=0;
        while(n>0){
            result+=(n%10)*(n%10);
            n=n/10;
        }
        return result;
    }
};

int main(){
    Solution s;
    int n=20;
    if(s.isHappy(n)){
        cout<<n<<" is happy!"<<endl;
    }
    else{
        cout<<n<<" is not happy!"<<endl;
    }
    
    
}
