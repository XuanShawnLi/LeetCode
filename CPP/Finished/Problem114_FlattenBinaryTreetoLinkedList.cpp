/*
 Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    void flatten(TreeNode *root) {
		TreeNode* head=root;
        if(root==NULL){return;}
		while(root){
			if(root->left!=NULL){
				TreeNode* Previous=RightMostNode(root->left);
				TreeNode* Next=root->right;
				Previous->right=Next;
				root->right=root->left;
				root->left=NULL;
			}
			root=root->right;
		}
    }

	TreeNode* RightMostNode(TreeNode* root){
		while(root->right){root=root->right;}
		return root;
	}

	void PrintTree(TreeNode* root){
        if(root==NULL)return;
        cout<<root->val<<" ";
		if(root->left){cout<<"has left "<<root->left->val<<" ";}
		if(root->right){cout<<"has right "<<root->right->val<<" ";}
		cout<<endl;
        PrintTree(root->left);
        PrintTree(root->right);
    }
};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(5);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
//    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(6);
	Solution s;
	s.PrintTree(root);
	s.flatten(root);
	s.PrintTree(root);
}
