/*

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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
     	int n=inorder.size();
        if(n==0)return NULL;
        int* ain=new int[n];
        for(int i=0;i<n;i++){ain[i]=inorder[i];}
        int* apre=new int[n];
        for(int i=0;i<n;i++){apre[i]=preorder[i];}
        TreeNode* result=buildTree_Helper(apre,ain,n);
        delete[] ain;
        delete[] apre;
        return result;   
    }

	TreeNode *buildTree_Helper(int* preorder, int* inorder, int n){
		if(n==0)return NULL;
		TreeNode* head=new TreeNode(preorder[0]);
		int mid=FindValue(inorder,n,head->val);
		head->left=buildTree_Helper(preorder+1,inorder,mid);
        head->right=buildTree_Helper(preorder+mid+1,inorder+mid+1,n-mid-1);
        return head;
	}

	int FindValue(int* list,int n, int val){
		for(int i=0;i<n;i++){
			if(list[i]==val)return i;
		}
		cout<<n<<" val="<<val<<endl;
		cout<<"error"<<endl;
		exit(1);
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
	int apre[]={4,2,1,3,6,5,7};
	int ain[]={1,2,3,4,5,6,7};
	vector<int> inorder(ain,ain+Size(ain));
	vector<int> preorder(apre,apre+Size(apre));
	TreeNode* top=s.buildTree(preorder,inorder);
	s.PrintTree(top);
}

