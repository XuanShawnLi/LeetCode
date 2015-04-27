//
//  Problem203_RemoveLinkedListElements.cpp
//  LeetCode
//
//  Created by Xuan Li on 4/27/15.
//  Copyright (c) 2015 Xuan Li. All rights reserved.
//
/*
 Remove all elements from a linked list of integers that have value val.
 
 Example
 Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 Return: 1 --> 2 --> 3 --> 4 --> 5
 */
#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* runner=head;
        ListNode* previous=NULL;
        while(runner){
            if(runner->val==val){
                if(runner->next==NULL){
                    if(previous){previous->next=NULL;}
                    break;
                }
                else{
                    runner->val=runner->next->val;
                    runner->next=runner->next->next;
                }
            }
            else{
                previous=runner;
                runner=runner->next;
            }
        }
        if(previous==NULL){return NULL;}
        return head;
    }
    
    ListNode* ConvertArraytoList(int* a, int n){
        if(n==0){return NULL;}
        ListNode* head=new ListNode(a[0]);
        ListNode* runner=head;
        for(int i=1;i<n;i++){
            runner->next=new ListNode(a[i]);
            runner=runner->next;
        }
        return head;
    }
    
    void PrintList(ListNode* head){
        cout<<"Printing List: ";
        while(head){
            cout<<head->val<<"->";head=head->next;
        }
        cout<<"end"<<endl;
    }
};

#define Size(a) sizeof(a)/sizeof(a[0])

int main(){
    int a[]={6};//,1,2,6,3,4,5,6};
    int n=Size(a);
    Solution s;
    ListNode* head=s.ConvertArraytoList(a, n);
    s.PrintList(head);
    int val=6;
    head=s.removeElements(head, val);
    s.PrintList(head);
}
