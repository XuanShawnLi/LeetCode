/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include<iostream>
using namespace std;
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1==NULL and l2==NULL){return NULL;}
        else if(l1==NULL){return l2;}
        else if(l2==NULL){return l1;}
        int carryover=0;int tmp=0;
        ListNode* head=NULL;ListNode* previous;
        while(l1 and l2){
            tmp=carryover+l1->val+l2->val;
            if(head==NULL){
                head=new ListNode(tmp%10);
                carryover=tmp/10;
                previous=head;
            }
            else{
                previous->next=new ListNode(tmp%10);
                carryover=tmp/10;
                previous=previous->next;
            }
            l1=l1->next;l2=l2->next;
        }
        while(carryover!=0 or l1!=NULL or l2!=NULL){
            if(l1!=NULL){tmp=carryover+l1->val;l1=l1->next;}
            else if(l2!=NULL){tmp=carryover+l2->val;l2=l2->next;}
            else{tmp=carryover;}
            previous->next=new ListNode(tmp%10);
            carryover=tmp/10;
            previous=previous->next;
        }
        return head;
    }
    
    void PrintNumber(ListNode* L){
        while(L!=NULL){
            cout<<L->val;L=L->next;
        }
        cout<<endl;
    }
};

int main()
{ListNode* L1=new ListNode(0);
//L1->next=new ListNode(4);
//L1->next->next=new ListNode(3);
ListNode* L2=new ListNode(7);
L2->next=new ListNode(3);
//L2->next->next=new ListNode(6); 
Solution s;
ListNode* L3=s.addTwoNumbers(L1,L2);
s.PrintNumber(L3);
}