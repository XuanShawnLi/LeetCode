/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<algorithm>
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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > result;
    	if(root==NULL)return result;
		result=levelOrder(root);
		reverse(result.begin(),result.end());
		return result;
    }

    vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > result;
		if(root==NULL)return result;
		queue<TreeNode*> q;
		unordered_map<TreeNode*,int> distance;
		q.push(root);distance.insert(make_pair(root,1));
		int lastdistance=0;
		vector<int> tmp(1,root->val);
		while(!q.empty()){
			TreeNode* current=q.front();q.pop();
			if(distance[current]>lastdistance){//next layer, start writing the current layer
				result.push_back(tmp);tmp.clear();
				lastdistance=distance[current];
			}
			if(current->left){
				q.push(current->left);
				distance.insert(make_pair(current->left,distance[current]+1));
				tmp.push_back(current->left->val);
			}
			if(current->right){
                q.push(current->right);
                distance.insert(make_pair(current->right,distance[current]+1));
                tmp.push_back(current->right->val);
            }
		}
		if(!tmp.empty())result.push_back(tmp);
		return result;
    }

	void PrintVector(vector<vector<int> > result){
        int n=result.size();
        cout<<"["<<endl;
        for(int i=0;i<result.size();i++){
            cout<<"[";
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j]<<" ";
            }
            cout<<"]"<<endl;
        }
        cout<<"]"<<endl;
    }
};

int main(){
	Solution s;
	TreeNode* root=new TreeNode(3);
	root->left=new TreeNode(9);
	root->right=new TreeNode(20);
	root->right->left=new TreeNode(15);
	root->right->right=new TreeNode(7);
	vector<vector<int> > result=s.levelOrderBottom(root);
	s.PrintVector(result);
}

