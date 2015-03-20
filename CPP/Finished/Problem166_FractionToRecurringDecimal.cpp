/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

    Given numerator = 1, denominator = 2, return "0.5".
    Given numerator = 2, denominator = 1, return "2".
    Given numerator = 2, denominator = 3, return "0.(6)".

Credits:
Special thanks to @Shangrila for adding this problem and creating all test cases.
*/
#include<iostream>
#include<sstream>
#include<string>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;

class Solution {
public:
    string fractionToDecimal_OLD(int numerator, int denominator) {
    	int r_int=numerator/denominator;
		stringstream ss;
		if(r_int*denominator==numerator){ss<<r_int;return ss.str();}
		double r_d=double(numerator)/denominator;
		ss<<r_d;
		//cout<<ss.str()<<" "<<r_d<<endl;exit(1);
		string str=ss.str();
		str.erase ( str.find_last_not_of('0') + 1, string::npos );
		//check if it is 0.666667
		int n=str.length();
		if(n>8)
			{cout<<"hello"<<endl;
			//????
			}
		return str;
    }

	string fractionToDecimal(long numerator, long denominator) {
		if(numerator==0){return "0";}
		if(numerator<0 and denominator<0){return fractionToDecimal(-numerator, -denominator);}
		else if(numerator<0){return "-"+fractionToDecimal(-numerator, denominator);}
		else if(denominator<0){return "-"+fractionToDecimal(numerator, -denominator);}
		stringstream ss;string result="";
		long r_int=numerator/denominator;
		long remainder=numerator-denominator*r_int;
		unordered_map<long,long> dict;
		ss<<r_int;
		result=ss.str();
		if(remainder!=0){result+=".";}
		dict.insert(make_pair(remainder,result.length()));
		while(remainder>0)
			{numerator=remainder*10;
			 r_int=numerator/denominator;
			 remainder=numerator-denominator*r_int;
			 stringstream tmp;
             tmp<<r_int;
             result+=tmp.str();
			 if(dict.count(remainder)==0)
				{dict.insert(make_pair(remainder,result.length()));}
			 else//repeating patterns
				{
				 long index=dict[remainder];
				 result=result.substr(0,index)+"("+result.substr(index,result.length()-index)+")";
				 return result;
				}
			}
		return result;

	}
};

int main()
{Solution s;
int n=333;
int d=500;
cout<<n<<"/"<<d<<"="<<s.fractionToDecimal(n,d)<<endl;
n=2;d=3;
cout<<n<<"/"<<d<<"="<<s.fractionToDecimal(n,d)<<endl;
n=1;d=2;
cout<<n<<"/"<<d<<"="<<s.fractionToDecimal(n,d)<<endl;
n=2;d=1;
cout<<n<<"/"<<d<<"="<<s.fractionToDecimal(n,d)<<endl;
n=87;d=170;
cout<<n<<"/"<<d<<"="<<s.fractionToDecimal(n,d)<<endl;
n=-1;d=-2147483648;
cout<<n<<"/"<<d<<"="<<s.fractionToDecimal(n,d)<<endl;
}
