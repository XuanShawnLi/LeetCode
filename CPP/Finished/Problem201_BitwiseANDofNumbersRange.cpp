//
//  Problem201_BitwiseANDofNumbersRange.cpp
//  LeetCode
//
//  Created by Xuan Li on 4/27/15.
//  Copyright (c) 2015 Xuan Li. All rights reserved.
//

#include <iostream>
using namespace std;
/*
 Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 
 For example, given the range [5, 7], you should return 4.
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(n==0)return 0;
        if(m==n)return m;
        int base=1<<30;
        while(base>n){base=base>>1;}
        if(base<=n and base>m)return 0;
        return base+rangeBitwiseAnd(m-base,n-base);
    }
};

void main(){
    Solution s;
    int m=12;
    int n=13;
    cout<<m<<":"<<n<<"="<<s.rangeBitwiseAnd(m,n)<<endl;
}
