/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n=gas.size();int previous=gas[0]-cost[0];
		if(n==0){return -1;}
		if(n==1){
			if(previous<0){return -1;}
			else{return 0;}
		}
		int minval=previous;int index=0;
		int current=previous;
		for(int i=1;i<n;i++){
			current=previous+gas[i]-cost[i];
			if(current<minval){minval=current;index=i;}
			previous=current;
		}
		if(current<0){return -1;}
		return (index+1)%n;
    }
};


#define Size(a) sizeof(a)/sizeof(a[0])

int main(){
	Solution s;
	int gas_a[]={2,3,1};
	int cost_a[]={3,1,2};
	vector<int> gas(gas_a,gas_a+Size(gas_a));
	vector<int> cost(cost_a,cost_a+Size(cost_a));
	cout<<s.canCompleteCircuit(gas,cost)<<endl;
}

