/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/
#include<iostream>
#include<queue>
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
    int sumNumbers(TreeNode *root) {
        if(root==NULL){return 0;}
		queue<TreeNode*> q;
		q.push(root);
		int result=0;
		while(not(q.empty())){
			TreeNode* current=q.front();q.pop();
			if(current->left){current->left->val+=current->val*10;q.push(current->left);}
			if(current->right){current->right->val+=current->val*10;q.push(current->right);}
			if(current->left==NULL and current->right==NULL){result+=current->val;}
		}
		return result;
    }
};

int main(){
	Solution s;
	TreeNode* head=new TreeNode(1);
	head->left=new TreeNode(2);
	head->right=new TreeNode(3);
//	cout<<s.sumNumbers(head)<<"==25"<<endl;
	head->left->left=new TreeNode(0);
	cout<<s.sumNumbers(head)<<"==133"<<endl;

}
