/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
		int n=num.size();
		if(n<2){return n;}
		unordered_map<int,int> dict;//0 for unmarked and 1 for marked
		for(int i=0;i<n;i++){
			dict.insert(make_pair(num[i],0));
		}       
		int result=1; 
		for(int i=0;i<n;i++){
			if(dict[num[i]]==0){
				dict[num[i]]=1;
				int left=num[i]-1;
				while(dict.find(left)!=dict.end()){dict[left]=1;left--;}
				int right=num[i]+1;
				while(dict.find(right)!=dict.end()){dict[right]=1;right++;}
				if(right-left-1>result){result=right-left-1;}
			}
		}
		return result;
    }
};

#define Size(a) sizeof(a)/sizeof(a[0])

int main(){
	Solution s;
	int a[]={100,4,200,1,3,2};
	vector<int> num(a,a+Size(a));
	cout<<s.longestConsecutive(num)<<"==4"<<endl;

}
