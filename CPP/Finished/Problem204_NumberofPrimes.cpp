//
//  Problem204_NumberofPrimes.cpp
//  LeetCode
//
//  Created by Xuan Li on 4/27/15.
//  Copyright (c) 2015 Xuan Li. All rights reserved.
//
/*Description:

Count the number of prime numbers less than a non-negative number, n

click to show more hints.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
 */
#include <ctime>
#include <iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int* dp=new int[n];
        for(int i=0;i<n;i++){dp[i]=0;}
        int r=2;
        while(r<n){
            int m=(n-1)/r;
            for(int j=2;j<m+1;j++){dp[j*r]=1;}
            r=FindNextZero(dp,n,r);
        }
        int result=0;
        for(int i=2;i<n;i++){
            if(dp[i]==0)result++;
        }
        return result;
    }
    
    int FindNextZero(int* dp,int n,int r){
        r=r+1;
        while(r<n){
            if(dp[r]==0)return r;
            r++;
        }
        return n;
    }
};

int main(){
    Solution s;
    time_t t1,t2;
    for(int n=1;n<=20;n++){
        cout<<n<<":"<<s.countPrimes(n)<<endl;
    }
    t1=clock();
    int n=999983;
    cout<<n<<":"<<s.countPrimes(n)<<"=="<<78497<<endl;
    t2=clock();
    cout<<"CPU time= "<<t2-t1<<endl;
}
