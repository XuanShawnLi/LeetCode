/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
		if(root==NULL)return 0;
		if(root->left==NULL and root->right==NULL)return 1;
		if(root->left==NULL)return 1+minDepth(root->right);
		if(root->right==NULL)return 1+minDepth(root->left);
		return 1+min(minDepth(root->left),minDepth(root->right));
    }
};

int main(){
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(4);
/*
    root->left->left=new TreeNode(11);
    root->left->left->left=new TreeNode(7);
    root->left->left->right=new TreeNode(2);
    root->right=new TreeNode(8);
    root->right->left=new TreeNode(13);
    root->right->right=new TreeNode(4);
    root->right->right->right=new TreeNode(1);
*/
    Solution s;
    cout<<s.minDepth(root)<<endl;;
}
