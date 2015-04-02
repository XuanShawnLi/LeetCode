/*
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL){return false;}
		if(root->left==NULL and root->right==NULL){return root->val==sum;}
		return hasPathSum(root->left,sum-root->val) or hasPathSum(root->right,sum-root->val);
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
	root->right->right->right=new TreeNode(1);
	Solution s;
	int sum=22;
	cout<<s.hasPathSum(root,sum)<<endl;;

}
