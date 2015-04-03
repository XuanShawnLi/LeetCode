/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/
#include<iostream>
#include<vector>
using namespace std;

// Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
		return sortedArrayToBST_Helper(num,0,num.size()-1);        
    }

	TreeNode *sortedArrayToBST_Helper(vector<int> &num,int left, int right) {
		if(left>right)return NULL;
		int mid=(left+right)/2;
		TreeNode *head=new TreeNode(num[mid]);
		head->left=sortedArrayToBST_Helper(num,left,mid-1);
		head->right=sortedArrayToBST_Helper(num,mid+1,right);
		return head;
    }

	void PrintTree(TreeNode* root){
        if(root==NULL)return;
        PrintTree(root->left);
        cout<<root->val<<endl;
        PrintTree(root->right);
    }
};

#define Size(a) sizeof(a)/sizeof(a[0])

int main(){
    Solution s;
    int a[]={1,2,3,4,5,6,7};
	vector<int> num(a,a+Size(a));
    TreeNode* root=s.sortedArrayToBST(num);
    s.PrintTree(root);
}

