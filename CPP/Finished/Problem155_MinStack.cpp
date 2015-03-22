/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

#include<iostream>
#include<vector>
using namespace std;

class MinStack {
	vector<int> Stack;
	vector<int> MS;
	int n;
public:
	MinStack(){n=0;}
    void push(int x) {
        Stack.push_back(x);
		if(n==0){MS.push_back(x);}
		else{MS.push_back(min(x,MS[n-1]));}
		n++;
    }

    void pop() {
        Stack.pop_back();
		MS.pop_back();
		n--;
    }

    int top() {
        return Stack[n-1];
    }

    int getMin() {
        return MS[n-1];
    }

	bool Empty()
	{return Stack.empty();}
};

int main()
{MinStack m;
 m.push(1);
 m.push(2);
 m.push(-1);
 m.push(-1);
 m.push(3);
 while(!m.Empty())
	{cout<<"current element"<<m.top()<<"with minimum element"<<m.getMin()<<endl;
	 m.pop();
	}


}
