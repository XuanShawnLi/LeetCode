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
//O(n) space
//O(n) complexity in constructor
//O(1) complexity in search
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

class BSTIterator_M{
//O(1) space
//O(h*h) complexity in constructor
//O(1) in checking hasNext
//O(h*h) complexity in next
	TreeNode* current;
public:
	BSTIterator_M(TreeNode *root) {
	//Go to the left most node
	TreeNode* tmp;
	current=root;
	if(root==NULL){current=NULL;return;}
	while(current->left)//reconnet at each level
		{
		 tmp=current->left;
		 while(tmp->right and tmp->right!=current){tmp=tmp->right;}//find the right most node of the left branch
		 if(tmp->right==current){cout<<"error"<<endl;exit(1);}
		 else
			{tmp->right=current;
			 current=current->left;
		//	 cout<<"reconnect"<<tmp->val<<" "<<tmp->right<<endl;
			}
		}
	//cout<<current->val<<" and right="<<current->right<<endl;exit(1);
	//now current is the left most node
    }

	/** @return whether we have a next smallest number */
    //O(1)
    bool hasNext() {
        return current!=NULL;
    }

	/** @return the next smallest number */
    //O(1)
    int next() {
		int result=current->val;
		TreeNode* tmp;
		//go to the next smallest number
		//check if current is the right-most node of current->right's left branch
		tmp=current->right;
		if(tmp==NULL){current=NULL;}//end
		else
			{tmp=tmp->left;//left branch
			 while(tmp and tmp!=current){tmp=tmp->right;}
			 if(tmp==current)//yes needs to relink
				{tmp=current->right;
				 current->right=NULL;
				 current=tmp;
				}
			 else//no need to relink
				{
				 current=current->right;
				 //go to the left most node of the current branch
				 TreeNode* tmp;
				 while(current->left)
					{tmp=current->left;
					 while(tmp->right and tmp->right!=current){tmp=tmp->right;}//find the right most node of the left branch
					 if(tmp->right==current){cout<<"error"<<endl;exit(1);}
					 else
            			{tmp->right=current;
             			 current=current->left;
            			}
					}
				}
		}
		return result;
    }
};

int main()
{TreeNode* top=new TreeNode(4);
 top->left=new TreeNode(2);
 top->left->left=new TreeNode(1);
 top->left->right=new TreeNode(3);
 top->right=new TreeNode(6);
 top->right->left=new TreeNode(5);
 top->right->right=new TreeNode(7);
 top=NULL;
 BSTIterator i = BSTIterator(top);
 while (i.hasNext()) cout << i.next()<<endl;
}


