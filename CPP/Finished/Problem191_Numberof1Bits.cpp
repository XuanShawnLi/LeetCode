//
//  Problem191_Numberof1Bits.cpp
//  LeetCode
//
//  Created by Xuan Li on 3/19/15.
//  Copyright (c) 2015 Xuan Li. All rights reserved.
//

//#include "Problem191_Numberof1Bits.h"
#include <iostream>
using namespace std;
/*
 Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 
 For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 
 Credits:
 Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0){
            if(n%2==1){count++;}
            n=n/2;
        }
        return count;
    }
};

int main()
{Solution s;
 cout<<s.hammingWeight(11)<<endl;
    
}
