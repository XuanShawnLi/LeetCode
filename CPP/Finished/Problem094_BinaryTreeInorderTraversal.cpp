/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

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
    vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		if(root==NULL){return result;}
		//Morris Traversal
		TreeNode* r=root;
		while(r)
			{if(r->left==NULL)
				{result.push_back(r->val);r=r->right;}
			 else//it has left branch
				{TreeNode* rsave=r;
				 r=r->left;
				 while(r->right!=NULL and r->right!=rsave){r=r->right;}
				 if(r->right==rsave)
					{r->right=NULL;//cout<<"unlink"<<r->val<<" with "<<rsave->val<<endl;
					 result.push_back(rsave->val);r=rsave->right;
					}
				 else
					{r->right=rsave;//cout<<"link"<<r->val<<" with "<<rsave->val<<endl;
					 r=rsave->left;
					}
				}
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
 vector<int> result=s.inorderTraversal(root);
 for(int i=0;i<result.size();i++)
	{cout<<result[i]<<" ";}
	cout<<" == 1 2 3 4 5 6 7"<<endl;
//left branch ->middle-> right branch
}
