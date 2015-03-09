/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer
*/
#include<iostream>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
	uint32_t result=0;
	int i=0;
	while(n>0)
		{result=result<<1;
		 result+=n%2;
		 n=n/2;
		 i++;
		}
	for(;i<32;i++){result=result<<1;}
	return result;
    }
};

int main()
{
Solution s;
uint32_t n=43261596;
cout<<n<<endl;
//s.reverseBits(n);
cout<<s.reverseBits(n)<<endl;
}
