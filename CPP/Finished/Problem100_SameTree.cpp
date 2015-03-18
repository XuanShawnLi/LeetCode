/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL and q==NULL){return true;}
		if(p==NULL or q==NULL or p->val!=q->val){return false;}
		return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

int main()
{
TreeNode* head1=new TreeNode(1);
head1->left=new TreeNode(2);
head1->right=new TreeNode(2);
head1->left->right=new TreeNode(3);
head1->right->right=new TreeNode(3);

TreeNode* head2=new TreeNode(1);
head2->left=new TreeNode(2);
head2->right=new TreeNode(2);
head2->left->right=new TreeNode(3);
head2->right->right=new TreeNode(3);
Solution s;
cout<<s.isSameTree(head1,head2)<<endl;
}
