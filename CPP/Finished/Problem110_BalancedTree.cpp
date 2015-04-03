/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
*/
#include<iostream>
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
    bool isBalanced(TreeNode *root) {
		pair<bool,int> result=isBalanced_Helper(root);
		return result.first;
    }

	pair<bool,int> isBalanced_Helper(TreeNode *root) {
		if(root==NULL)return make_pair(true,0);
		pair<bool,int> Left=isBalanced_Helper(root->left);
        pair<bool,int> Right=isBalanced_Helper(root->right);
		bool part1=Left.first and Right.first and abs(Left.second-Right.second)<=1;
		int part2=1+max(Left.second,Right.second);
		return make_pair(part1,part2);
	}

};


int main(){
    TreeNode* root=new TreeNode(5);
    root->right=new TreeNode(8);
    root->right->right=new TreeNode(4);
    Solution s;
    cout<<s.isBalanced(root)<<endl;;

}
