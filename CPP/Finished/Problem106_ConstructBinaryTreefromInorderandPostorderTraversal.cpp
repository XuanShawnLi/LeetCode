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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n=inorder.size();
		if(n==0)return NULL;
		int* ain=new int[n];
		for(int i=0;i<n;i++){ain[i]=inorder[i];}
		int* apost=new int[n];
		for(int i=0;i<n;i++){apost[i]=postorder[i];}
		TreeNode* result=buildTree_Helper(ain,apost,n);
		delete[] ain;
		delete[] apost;
		return result;
    }

	TreeNode *buildTree_Helper(int* inorder, int*postorder, int n){
		if(n==0)return NULL;
		TreeNode* head=new TreeNode(postorder[n-1]);
		int mid=FindValue(inorder,n,head->val);
		head->left=buildTree_Helper(inorder,postorder,mid);
        head->right=buildTree_Helper(inorder+mid+1,postorder+mid,n-mid-1);
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
	int ain[]={1,2,3,4,5,6,7};
	int apost[]={1,3,2,5,7,6,4};
	vector<int> inorder(ain,ain+Size(ain));
	vector<int> postorder(apost,apost+Size(apost));
	TreeNode* top=s.buildTree(inorder,postorder);
	s.PrintTree(top);
}


