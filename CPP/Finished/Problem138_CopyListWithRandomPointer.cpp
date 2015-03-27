/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/
#include<iostream>
using namespace std;


 //Definition for singly-linked list with a random pointer.
 struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(head==NULL){return head;}
		//duplicate list: only next is copied
		RandomListNode *r=head;RandomListNode * NextNode=r->next;
		while(r){
			NextNode=r->next;
			r->next=new RandomListNode(r->label);
			r->next->next=NextNode;
			r=NextNode;
		}
		//duplicate list: copy random
		r=head;
		while(r){
			if(r->random==NULL){r->next->random=NULL;}			
			else{r->next->random=r->random->next;}
			r=r->next->next;
		}
		r=head;
		RandomListNode *head2=r->next;
		RandomListNode *r2=head2;
		while(r){
			r->next=r2->next;r=r->next;
			if(r){r2->next=r->next;r2=r2->next;}
		}
		return head2; 
    }

	void PrintList(RandomListNode* head){
		if(head==NULL){cout<<"empty list"<<endl;return;}
		while(head){
			if(head->random==NULL){cout<<head->label<<"with random points to NULL"<<endl;}
			else{cout<<head->label<<"with random points to"<<head->random->label<<endl;}
			head=head->next;
		}
	}	
};

int main(){
	RandomListNode* head=new RandomListNode(1);
	head->next=new RandomListNode(2);
	head->next->next=new RandomListNode(3);
	head->random=head;
	head->next->random=NULL;
	head->next->next->random=head;
	Solution s;
	s.PrintList(head);
	RandomListNode* result=s.copyRandomList(head);
	s.PrintList(result);
//	s.PrintList(head);
}
