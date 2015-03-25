/*
Given a singly linked list L: L0->L1->...->Ln-1->Ln,
reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/
#include<iostream>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    void reorderList(ListNode *head) {
		if(head==NULL or head->next==NULL or head->next->next==NULL){return;}
		//length must be longer than 2
		int n=0;ListNode* r=head;
		while(r){n++;r=r->next;}
		ListNode* tail1=Move(head,(n-1)/2);
		ListNode* tail2=tail1->next;
		ListNode* head2=Move(head,n-1);
		tail1->next=NULL;
		int m=n/2;r=tail2;ListNode* NextNode=r->next;
		for(int i=1;i<m;i++){
			 ListNode* NextNextNode=NextNode->next;
			 NextNode->next=r;
			 r=NextNode;NextNode=NextNextNode;			 
		}
		tail2->next=NULL;
		ListNode *left=head,*right=head2;
		ListNode *NextLeft=left->next,*NextRight=right->next;
		while(left and right){
			 left->next=right;right->next=NextLeft;
			 left=NextLeft;right=NextRight;
			 if(left)NextLeft=left->next;
			 if(right)NextRight=right->next;
		}
		return;
    }

	ListNode* Move(ListNode* head,int n){
		for(int i=0;i<n;i++){head=head->next;}
		return head;
	}

	void PrintList(ListNode* head){
		if(head==NULL){cout<<"Empty list"<<endl;}
		while(head){cout<<head->val<<"->";head=head->next;}
		cout<<"NULL"<<endl;
	}

	ListNode* CreateList(int* a,int n){
		if(n==0){return NULL;}
		ListNode* head=new ListNode(a[0]);
		ListNode* r=head;
		for(int i=1;i<n;i++){
			r->next=new ListNode(a[i]);r=r->next;
		}
		return head;
	}
};

#define Size(a) sizeof(a)/sizeof(a[0])

int main(){
	Solution s;
	int n=7;
	int *a=new int[n];
	for(int i=0;i<n;i++){a[i]=i+1;}
	ListNode* head=s.CreateList(a,n);
	s.PrintList(head);
	s.reorderList(head);
	s.PrintList(head);
}
