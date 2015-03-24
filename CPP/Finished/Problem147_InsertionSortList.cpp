/*
Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
		if(head==NULL or head->next==NULL){return head;}    
		int n=0;ListNode* r=head;	
		while(r!=NULL){n++;r=r->next;}
		ListNode* start=head->next;
		r=head;
		for(int i=1;i<n;i++)
			{r=head;
			 while(r!=start)
				{if(r->val>start->val)
					{int tmp=r->val;r->val=start->val;start->val=tmp;}
				r=r->next;
				}
		 	 start=start->next;
			}    
		return head;
    }

	ListNode* MakeList(int* a, int n){
        if(n==0){return NULL;}
        ListNode* head=new ListNode(a[0]);
        ListNode* r=head;
        for(int i=1;i<n;i++){
            r->next=new ListNode(a[i]);r=r->next;
        }
        return head;
    }

    void PrintList(ListNode* head){
    if(head==NULL){cout<<"Empty list"<<endl;return;}
    while(head!=NULL){cout<<head->val<<"->";head=head->next;}
    cout<<"NULL"<<endl;
    }

};

int main(){
int n=7;
int *a=new int[n];
for(int i=0;i<n;i++){a[i]=n-i;}
Solution s;
ListNode* head=s.MakeList(a,n);
s.PrintList(head);
head=s.insertionSortList(head);
s.PrintList(head);
}

