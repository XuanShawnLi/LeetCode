/*
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]
*/
#include<iostream>
#include<vector>
using namespace std;

 // Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
     	vector<vector<int> > result;
		if(root==NULL)return result;
		if(root->left==NULL and root->right==NULL){
			if(root->val==sum)result.push_back(vector<int>(1,root->val));
			return result;
		}
		vector<int> tmp(1,root->val);
		pathSum_Helper(root->left,sum-root->val,tmp,result);
		pathSum_Helper(root->right,sum-root->val,tmp,result);   
    }

	void pathSum_Helper(TreeNode *root, int sum, vector<int> &previous, vector<vector<int> > &result) {
		if(root==NULL)return;
		if(root->left==NULL and root->right==NULL){
			if(root->val==sum){
				previous.push_back(root->val);result.push_back(previous);
				previous.pop_back();
			}
			return;
		}
		previous.push_back(root->val);
		pathSum_Helper(root->left,sum-root->val,previous,result);
		pathSum_Helper(root->right,sum-root->val,previous,result);
		previous.pop_back();
	}

    void PrintVector(vector<vector<int> > result){
        int n=result.size();
        cout<<"["<<endl;
        for(int i=0;i<result.size();i++){
            cout<<"[";
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j]<<" ";
            }
            cout<<"]"<<endl;
        }
        cout<<"]"<<endl;
    }
};

int main(){
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(4);
    root->left->left=new TreeNode(11);
    root->left->left->left=new TreeNode(7);
    root->left->left->right=new TreeNode(2);
    root->right=new TreeNode(8);
    root->right->left=new TreeNode(13);
    root->right->right=new TreeNode(4);
	root->right->right->left=new TreeNode(5);
    root->right->right->right=new TreeNode(1);
    Solution s;
    int sum=22;
	vector<vector<int> > result=s.pathSum(root,sum);
	s.PrintVector(result);
}
