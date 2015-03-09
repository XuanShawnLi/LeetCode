/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
#include<iostream>
#include<vector>
#include<map>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    	int n=numbers.size();
		vector<int> result;
		unordered_map<int,int> index;
		unordered_map<int,int>::iterator it;
		for(int i=0;i<n;i++)
			{it=index.find(target-numbers[i]);
			 if(it!=index.end())
				{result.push_back(index[target-numbers[i]]);
				 result.push_back(i+1);
				 return result;
				}
			 index.insert(make_pair(numbers[i],i+1));
			}
		result.push_back(-1);
		result.push_back(-1);
		return result;
    }
};

int main()
{
int a[]={2,7,11,15};
vector<int> numbers(a,a+4);
int target=19;
Solution s;
vector<int> result=s.twoSum(numbers,target);
cout<<result[0]<<" and "<<result[1]<<endl;
}
