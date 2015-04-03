/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
#include<iostream>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 // Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL)return NULL;
		int n=0;
		ListNode* runner=head;
		while(runner){n++;runner=runner->next;}
		int* a=new int[n];
		runner=head;
		for(int i=0;i<n;i++){
			a[i]=runner->val;runner=runner->next;
		}	
		TreeNode* top=ConvertSortedArrayToBST(a,n);
		delete[] a;
		return top;	
    }

	TreeNode* ConvertSortedArrayToBST(int *a,int n){
		if(n==0)return NULL;
		int mid=n/2;
		TreeNode* head=new TreeNode(a[mid]);
		head->left=ConvertSortedArrayToBST(a,mid);
		head->right=ConvertSortedArrayToBST(a+mid+1,n-mid-1);
		return head;
	}
	void PrintTree(TreeNode* root){
		if(root==NULL)return;
		PrintTree(root->left);
		cout<<root->val<<endl;
		PrintTree(root->right);
	}

	void PrintList(ListNode* head){
		cout<<"Print list:";
		while(head){cout<<head->val<<" ";head=head->next;}
		cout<<endl;
	}

	ListNode* ConvertArrayToList(int* a,int n){
		if(n<=0)return NULL;
		ListNode* head=new ListNode(a[0]);
		ListNode* runner=head;
		for(int i=1;i<n;i++){
			runner->next=new ListNode(a[i]);runner=runner->next;
		}
		return head;
	}
};

#define Size(a) sizeof(a)/sizeof(a[0])

int main(){
	Solution s;
	int a[]={1,2,3,4,5,6,7};
	ListNode* head=s.ConvertArrayToList(a,Size(a));
	s.PrintList(head);
	TreeNode* root=s.sortedListToBST(head);
	s.PrintTree(root);
}
