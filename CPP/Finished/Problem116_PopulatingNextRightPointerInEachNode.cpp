/*
 Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/
#include<iostream>
#include<queue>
using namespace std;

 // Definition for binary tree with next pointer.
  struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };

 
class Solution {
public:
	void connect(TreeLinkNode *root) {//O(1) space
		if(root==NULL)return;
		TreeLinkNode* runner=root;
		TreeLinkNode* nextrunner=runner->left;
		while(nextrunner){//set next layer
			while(runner){//move horizontally
				runner->left->next=runner->right;
				if(runner->next){
					runner->right->next=runner->next->left;
				}
				runner=runner->next;
			}	
			runner=nextrunner;
			nextrunner=runner->left;
		}
	}

    ivoid connect_queue(TreeLinkNode *root) {//O(n) space
		if(root==NULL){return;}
		queue<TreeLinkNode*> q;
		q.push(root);
		TreeLinkNode* previous=NULL;
		while(!q.empty()){
			TreeLinkNode* current=q.front();q.pop();
			if(current->right==NULL and current->left==NULL){continue;}
			else if(current->left==NULL){
				q.push(current->right);
				current->right->next=FindNextChildren(current->next);
			}
			else if(current->right==NULL){
				q.push(current->left);
				current->left->next=FindNextChildren(current->next);
			}
			else{
				q.push(current->left);
				current->left->next=current->right;
				q.push(current->right);
				current->right->next=FindNextChildren(current->next);
			}
		}
        return;
    }

	TreeLinkNode* FindNextChildren(TreeLinkNode* pNext){
		while(pNext){
			if(pNext->left){return pNext->left;}
			if(pNext->right){return pNext->right;}
			pNext=pNext->next;

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
	TreeLinkNode* root=new TreeLinkNode(1);
	root->left=new TreeLinkNode(2);
	root->right=new TreeLinkNode(3);
	root->left->left=new TreeLinkNode(4);
	root->left->right=new TreeLinkNode(5);
	root->right->left=new TreeLinkNode(6);
	root->right->right=new TreeLinkNode(7);
	Solution s;
	s.connect(root);
	s.PrintTree(root);
}
