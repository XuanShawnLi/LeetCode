/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
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

 struct Node{
 TreeNode* value;
 Node* next;
 Node(TreeNode* x): value(x),next(NULL){};
};

class BSTIterator {
    Node* current;
	Node* Head;
public:
    BSTIterator(TreeNode *root) {
	if(root==NULL)
		{Head=NULL;current=NULL;return;} 
	PlaceTree(root,Head,current);
	current=Head;
    }

	void PlaceTree(TreeNode* root, Node* &top, Node* &tail)
	{if(root==NULL){top=NULL;return;}
	 if(root->left==NULL and root->right==NULL)
		{Node* tmp=new Node(root);top=tmp;tail=tmp;}
	 else if(root->right==NULL)//has left branch only
		{Node* tmp;
		 tail=new Node(root);
		 PlaceTree(root->left,top,tmp);
		 tmp->next=tail;
		}
	 else if(root->left==NULL)//has right branch only
		{Node* tmp;
		 top=new Node(root);
		 PlaceTree(root->right,tmp,tail);
		 top->next=tmp;
		}
	 else//has both branches
		{Node* middle=new Node(root);
		 Node* tmp;
		 PlaceTree(root->right,tmp,tail);
		 middle->next=tmp;
		 PlaceTree(root->left,top,tmp);
		 tmp->next=middle;
		}
	}

    /** @return whether we have a next smallest number */
    //O(1)
	bool hasNext() {
		return current!=NULL;
    }

    /** @return the next smallest number */
    //O(1)
    int next() {
		int tmp=current->value->val;
        current=current->next;
		return tmp;
    }
};

int main()
{TreeNode* top=new TreeNode(4);
 top->left=new TreeNode(2);
 top->left->left=new TreeNode(1);
 top->left->right=new TreeNode(3);
 //top->right=new TreeNode(6);
 //top->right->left=new TreeNode(5);
 //top->right->right=new TreeNode(7);
 //top=NULL;
 BSTIterator i = BSTIterator(top);
 while (i.hasNext()) cout << i.next();
}


