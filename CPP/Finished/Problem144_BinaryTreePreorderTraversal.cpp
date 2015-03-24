/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/
#include<iostream>
#include<stack>
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
    vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		if(root==NULL){return result;}
        stack<TreeNode*> list;
		list.push(root);
		while(not(list.empty()))
			{TreeNode* r=list.top();
			 list.pop();
			 result.push_back(r->val);
			 if(r->right){list.push(r->right);}
			 if(r->left){list.push(r->left);}
			}
		return result;
    }
};

int main()
{TreeNode* root=new TreeNode(4);
 root->left=new TreeNode(2);
 root->left->left=new TreeNode(1);
 root->left->right=new TreeNode(3);
 root->right=new TreeNode(6);
 root->right->left=new TreeNode(5);
 root->right->right=new TreeNode(7);
 Solution s; 
 vector<int> result=s.preorderTraversal(root);
 for(int i=0;i<result.size();i++)
	{cout<<result[i]<<" ";}
	cout<<" == 4 2 1 3 6 5 7"<<endl;
//middle -> left branch -> right branch
}
