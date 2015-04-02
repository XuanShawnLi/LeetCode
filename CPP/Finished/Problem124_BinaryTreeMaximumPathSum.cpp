/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
	int maxval;

	int maxPathSum(TreeNode* root) {//45ms
		if(root==NULL){return 0;}
		maxval=root->val;
		Helper(root);
		return maxval;
	}

	int Helper(TreeNode* root){
		if(root==NULL){return 0;}
		int Left=max(0,Helper(root->left));
		int Right=max(0,Helper(root->right));
		maxval=max(maxval,root->val+Left+Right);
		return root->val+max(Left,Right);
	}

    int maxPathSum_Pair(TreeNode *root) {//54ms
		if(root==NULL){return 0;}
		if(root->left==NULL and root->right==NULL){return root->val;}
		else if(root->left==NULL){
			pair<int,int> Right=maxPathSum_sub(root->right);
			return max(max(root->val,root->val+Right.first),Right.second);	
		}     
		else if(root->right==NULL){
			pair<int,int> Left=maxPathSum_sub(root->left);
            return max(max(root->val,root->val+Left.first),Left.second);
		}
		else{
			pair<int,int> Right=maxPathSum_sub(root->right);
			pair<int,int> Left=maxPathSum_sub(root->left);
			int result=max(root->val,root->val+Left.first);
			result=max(result,root->val+Right.first);
			result=max(result,root->val+Left.first+Right.first);
			result=max(result,max(Right.second,Left.second));
			return result;
		}
    }

	pair<int,int> maxPathSum_sub(TreeNode *root){
		int result1,rv=root->val,result2;
		if(root->left==NULL and root->right==NULL){
			return make_pair(rv,rv);
		}
		else if(root->left==NULL){
            pair<int,int> Right=maxPathSum_sub(root->right);
			result1=max(rv,rv+Right.first);
			result2=max(max(result1,Right.first),Right.second);
			return make_pair(result1,result2);
        }
		else if(root->right==NULL){
			pair<int,int> Left=maxPathSum_sub(root->left);
            result1=max(rv,rv+Left.first);
            result2=max(max(result1,Left.first),Left.second);
            return make_pair(result1,result2);
		} 
		else{
			pair<int,int> Right=maxPathSum_sub(root->right);
			pair<int,int> Left=maxPathSum_sub(root->left);
			result1=max(max(rv,rv+Left.first),rv+Right.first);
			result2=max(result1,rv+Left.first+Right.first);
			result2=max(max(result2,Left.second),Right.second);
			return make_pair(result1,result2);
		}
	}
};

int main(){
	Solution s;
	TreeNode* root=new TreeNode(-1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	cout<<s.maxPathSum(root)<<"==4"<<endl;
	root->right->left=new TreeNode(10);
	root->right->right=new TreeNode(10);
	cout<<s.maxPathSum(root)<<"==23"<<endl;
}
