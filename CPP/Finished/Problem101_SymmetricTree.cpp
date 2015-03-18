/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
#include<iostream>
#include<queue>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

//iterative
	bool isSymmetric(TreeNode *root) {
		if(root==NULL){return true;}
		queue<TreeNode*> q1,q2;
		q1.push(root->left);
		q2.push(root->right);
		TreeNode *node1,*node2;
		while(!q1.empty() and !q2.empty())
			{node1=q1.front();q1.pop();
			 node2=q2.front();q2.pop();
			 if(node1==NULL and node2==NULL){continue;}
			 if(node1==NULL or node2==NULL or node1->val!=node2->val){return false;}
			 q1.push(node1->left);q2.push(node2->right);
			 q1.push(node1->right);q2.push(node2->left);
			}
		return true;
	}

/* 
//recursive
    bool isSymmetric(TreeNode *root) {
		if(root==NULL){return true;}
		return isSymmetric_sub(root->left,root->right);
 	}

	bool isSymmetric_sub(TreeNode *left,TreeNode *right)
	{if(left==NULL and right==NULL){return true;}
	 if(left==NULL or right==NULL or left->val!=right->val){return false;}
	 return isSymmetric_sub(left->left,right->right) && isSymmetric_sub(left->right,right->left);
	}
*/

};

int main()
{
TreeNode* head=new TreeNode(1);
head->left=new TreeNode(2);
head->right=new TreeNode(2);
head->left->right=new TreeNode(3);
head->right->right=new TreeNode(3);
Solution s;
if(s.isSymmetric(head))
{cout<<"It is symmetric"<<endl;}
else
{cout<<"It is not symmetric"<<endl;}
}
