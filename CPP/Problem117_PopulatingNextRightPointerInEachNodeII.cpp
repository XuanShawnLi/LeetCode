/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/
#include<iostream>
using namespace std;

 // Definition for binary tree with next pointer.
  struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };

class Solution {
public:
    void connect(TreeLinkNode *root) {
		if(root==NULL)return;
        TreeLinkNode* runner=root;
        TreeLinkNode* nextrunner=FindNext(runner);
        while(nextrunner){//set next layer
            while(runner){//move horizontally
				if(runner->left!=NULL and runner->right!=NULL){
					runner->left->next=runner->right;
					runner->right->next=FindNext(runner->next);
				}
				else if(runner->left!=NULL){
					runner->left=FindNext(runner->next);
				}
				else if(runner->right!=NULL){
					runner->right->next=FindNext(runner->next);
				}
                runner=runner->next;
            }
            runner=nextrunner;
            nextrunner=FindNext(runner);
        }        
    }

	TreeLinkNode* FindNext(TreeLinkNode* current){
		while(current){
			if(current->left){return current->left;}
			if(current->right){return current->right;}
			current=current->next;
		}
		return NULL;
	}

	 void PrintTree(TreeLinkNode* root){
        if(root==NULL)return;
        cout<<root->val<<" ";
        if(root->next){cout<<"has next: "<<root->next->val<<endl;}
        else{cout<<"has next: NULL"<<endl;}
        PrintTree(root->left);
        PrintTree(root->right);
    }
};



int main(){
    TreeLinkNode* root=new TreeLinkNode(3);
    root->left=new TreeLinkNode(9);
    root->right=new TreeLinkNode(20);
//    root->left->left=new TreeLinkNode(4);
//    root->left->right=new TreeLinkNode(5);
    root->right->left=new TreeLinkNode(15);
    root->right->right=new TreeLinkNode(7);
    Solution s;
    s.connect(root);
    s.PrintTree(root);
}
