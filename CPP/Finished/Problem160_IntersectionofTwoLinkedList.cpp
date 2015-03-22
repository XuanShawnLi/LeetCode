/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 -> a2
                   ->
                     c1 -> c2 -> c3
                   ->           
B:     b1 -> b2 -> b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/
#include<iostream>
using namespace std;
// * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if(headA==NULL or headB==NULL){return NULL;}
        int nA=0;
		ListNode* rA=headA;
		while(rA){rA=rA->next;nA++;}
		int nB=0;
		ListNode* rB=headB;
		while(rB){rB=rB->next;nB++;}
		rA=headA;rB=headB;
		if(nA>nB)
			{for(int i=0;i<nA-nB;i++){rA=rA->next;}}
		else if(nA<nB)
			{for(int i=0;i<nB-nA;i++){rB=rB->next;}}
		while(rA)
			{if(rA==rB){return rA;}
			 rA=rA->next;rB=rB->next;
			}
		return NULL;
    }
};

int main()
{ListNode* a=new ListNode(11);
 a->next=new ListNode(12);
 ListNode* b=new ListNode(21);
 b->next=new ListNode(22);
 b->next->next=new ListNode(23);
 ListNode* c=new ListNode(31);
 c->next=new ListNode(32);
 c->next->next=new ListNode(33);
 a->next->next=c;
 b->next->next->next=c;
 Solution s;
 ListNode* result=s.getIntersectionNode(a,b);
 if(result==NULL or result->val!=c->val){cout<<"Error"<<endl;}
 else{cout<<"correct"<<endl;}
}
