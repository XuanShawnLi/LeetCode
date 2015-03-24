/*
Sort a linked list in O(n log n) time using constant space complexity.
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
	ListNode *sortList(ListNode *head){
		if(head==NULL or head->next==NULL){return head;}
		int n=0;
		ListNode *r;ListNode* head2=head;
		int vmin=0xfffffff;
		r=head;
		while(r!=NULL)
			{n++;r=r->next;}
		int stepsize=1;ListNode *r1,*r2,*r3;
		ListNode* previous=NULL,*next_previous;
		while(stepsize<n)
			{bool first=true;
			 r1=head2;
			 while(r1!=NULL)
				{r2=Move(r1,stepsize);r3=Move(r2,stepsize);
				 if(r2!=NULL)
				 	{//cout<<"merging"<<r1->val<<" "<<r2->val<<endl;
					 if(first){
						head2=MergeList(r1,r2,r3,next_previous);
						first=false;
						next_previous->next=r3;
					//	PrintList(head2);//exit(1);
					 }
					 else{
						previous->next=MergeList(r1,r2,r3,next_previous);
						next_previous->next=r3;
				//		PrintList(head2);//exit(1);
					 }
					}
				 r1=r3;previous=next_previous;
				}
			 //PrintList(head2);//exit(1);
			 stepsize*=2;
			}
		return head2;
	}

	ListNode* MergeList(ListNode* left, ListNode* right, ListNode* nextHead, ListNode* & tail){
		//return head of this merged list 
		//pass back the tail of this merged list in tail
		ListNode *rl=left,*rr=right;
		ListNode *head,*previous;
		if(rl->val<rr->val){head=rl;rl=rl->next;}
		else{head=rr;rr=rr->next;}
		previous=head;
		while(rl!=right and rr!=nextHead)
			{if(rl->val<rr->val)
				{previous->next=rl;previous=rl;rl=rl->next;}
			 else
				{previous->next=rr;previous=rr;rr=rr->next;}
			}
		if(rl==right)//left ran out
			{previous->next=rr;
			 while(rr->next!=nextHead){rr=rr->next;}
			 tail=rr;
			}
		else//right ran out
			{previous->next=rl;
			 while(rl->next!=right){rl=rl->next;}
			 tail=rl;
			}
		//cout<<head->val<<" "<<head->next->val<<" "<<tail->next->val<<endl;exit(1);
		return head;
	}

	ListNode* Move(ListNode* head,int n){
		if(head==NULL){return head;}
		int i=0;
		while(i<n and head!=NULL)
			{i++;head=head->next;}
		return head;
	}
    ListNode *sortList_ONSPACE(ListNode *head) {
		if(head==NULL or head->next==NULL){return head;}
		int n=0;ListNode* r=head;
		while(r!=NULL){n++;r=r->next;}
		int* a=new int[n];
		r=head;
		for(int i=0;i<n;i++){a[i]=r->val;r=r->next;}
		//start
		sortArray(a,n);
		r=head;
		for(int i=0;i<n;i++){r->val=a[i];r=r->next;}
		delete[] a;
		return head;
	}

	void sortArray(int* a,int n){
		if(n==1){return;}
		int *b=new int[n];
		int stepsize=1;
		while(stepsize<n){
			int m=n/(stepsize*2);
			int left=0,right=stepsize;
			while(left<n)
				{if(right<n)//two sectors to merge
					{int il=left,ir=right,ir_max=min(right+stepsize,n);
					 int ib=left;
					 while(il<right and ir<ir_max)
						{if(a[il]<a[ir]){b[ib++]=a[il++];}
						 else{b[ib++]=a[ir++];}
						}
					 if(il==right)//left ran out
						 {while(ir<ir_max){b[ib++]=a[ir++];}}
					 else
						 {while(il<right){b[ib++]=a[il++];}}
					}
				 else//copy the rest of a to b
				 	{for(int i=left;i<n;i++){b[i]=a[i];}}
				 left=right+stepsize;right=left+stepsize;
				}
			CopyArray(a,b,n);
			//PrintArray(b,n);//exit(1);
			stepsize*=2;
		}
	}

	void CopyArray(int *a,int *b,int n)
		{for(int i=0;i<n;i++){a[i]=b[i];}}

	void PrintArray(int *a,int n)
		{for(int i=0;i<n;i++){cout<<a[i]<<":";}cout<<endl;}

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
int n=3;
int *a=new int[n];
for(int i=0;i<n;i++){a[i]=n-i;}
Solution s;
ListNode* head=s.MakeList(a,n);
s.PrintList(head);
head=s.sortList(head);
s.PrintList(head);
}
