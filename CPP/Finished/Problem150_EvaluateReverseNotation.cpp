/*
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<tr1/unordered_map>
#include <stdlib.h>
using namespace std;
using namespace std::tr1;

typedef int (*MathFunc)(int, int);

    int Plus(int a,int b){return a+b;}

    int Minus(int a,int b){return a-b;}

    int Multiply(int a,int b){return a*b;}

    int Divide(int a,int b){
        if((a>0 and b>0) or (a<0 and b<0))
            {return a/b;}
        else
            {return -(abs(a)/abs(b));}
    }

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
		int a0=atoi(tokens[0].c_str());
		int n=tokens.size();
		if(n==1){return a0;}
		int a1=atoi(tokens[1].c_str());
		vector<int> setS;
		setS.push_back(a0);
		setS.push_back(a1);
        unordered_map<string,MathFunc> dict;
		dict.insert(make_pair("+",&(Plus)));
		dict.insert(make_pair("-",&(Minus)));
		dict.insert(make_pair("*",&(Multiply)));
		dict.insert(make_pair("/",&(Divide)));
		unordered_map<string,MathFunc>::iterator it;
		for(int i=2;i<n;i++)
			{it=dict.find(tokens[i]);
			 if(it==dict.end())
				{
				 setS.push_back(atoi(tokens[i].c_str()));
				}
			 else
				{
				 a1=setS.back();setS.pop_back();
				 a0=setS.back();setS.pop_back();
				 setS.push_back(it->second(a0,a1));
				 //int tmp=dict[tokens[i]](a0,a1);
				 //tmp=it->second(a0,a1);
				}
			}
		return setS[0];
    }
};

#define Size(a) sizeof(a)/sizeof(a[0])

int main(){
	Solution s;
	string a[]={"2", "1", "+", "3", "*"};
	int na=Size(a);
	vector<string> tokena(a,a+na);
	cout<<s.evalRPN(tokena)<<endl;
	string b[]={"4", "13", "5", "/", "+"};
    int nb=Size(b);
    vector<string> tokenb(b,b+nb);
    cout<<s.evalRPN(tokenb)<<endl;
	string c[]={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int nc=Size(c);
    vector<string> tokenc(c,c+nc);
    cout<<s.evalRPN(tokenc)<<endl;
}
