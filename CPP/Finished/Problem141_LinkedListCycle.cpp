/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        if(head==NULL or head->next==NULL){return false;}
		ListNode *r1=head->next,*r2=head->next->next;
		int n=100000;
		while(r1 and r2){
			if(r1==r2){return true;}
			r1=r1->next;
			r2=r2->next;
			if(r2==NULL or n==0){return false;}
			r2=r2->next;
			n--;
		}
		return false;
    }
};

int main(){
	Solution s;
	ListNode* head=new ListNode(1);
	head->next=new ListNode(2);
	head->next->next=new ListNode(3);
	head->next->next->next=new ListNode(4);
	head->next->next->next->next=head->next->next;
	if(s.hasCycle(head)){cout<<"Yes"<<endl;}
	else{cout<<"No"<<endl;}
} 

