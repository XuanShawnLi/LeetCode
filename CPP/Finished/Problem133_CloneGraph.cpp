/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/
#include<iostream>
#include<tr1/unordered_map>
#include<tr1/unordered_set>
#include<vector>
#include<queue>
using namespace std;
using namespace std::tr1;
 // Definition for undirected graph.
 struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node==NULL){return node;}
		queue<UndirectedGraphNode*> q;
        unordered_set<UndirectedGraphNode*> counted;
		unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> dict;
		q.push(node);UndirectedGraphNode* newhead=new UndirectedGraphNode(node->label);
		counted.insert(node);dict.insert(make_pair(node,newhead));
		while(not(q.empty())){
			UndirectedGraphNode *current=q.front();q.pop();
			for(int i=0;i<current->neighbors.size();i++){
				UndirectedGraphNode *tmp=current->neighbors[i];
				if(counted.count(tmp)==0){
					q.push(tmp);counted.insert(tmp);
					UndirectedGraphNode *tmp2=new UndirectedGraphNode(tmp->label);
					dict.insert(make_pair(tmp,tmp2));
				}
					dict[current]->neighbors.push_back(dict[tmp]);//create links
			}
		}
		return newhead;
    }

	void PrintGraph(UndirectedGraphNode *node){
		queue<UndirectedGraphNode*> q;
		unordered_set<UndirectedGraphNode*> counted;
		q.push(node); counted.insert(node);
		while(not(q.empty())){
			UndirectedGraphNode *current=q.front();q.pop();
			cout<<"Current Node:"<<current->label<<", has neighbors:";
			for(int i=0;i<current->neighbors.size();i++){
				UndirectedGraphNode *tmp=current->neighbors[i];
				cout<<tmp->label<<" ";
				if(counted.count(tmp)==0){q.push(tmp);counted.insert(tmp);}
			}
			cout<<endl;
		}
	}
};

int main(){
UndirectedGraphNode* top0=new UndirectedGraphNode(0);
UndirectedGraphNode* top1=new UndirectedGraphNode(1);
UndirectedGraphNode* top2=new UndirectedGraphNode(2);
top0->neighbors.push_back(top1);
top0->neighbors.push_back(top2);
top1->neighbors.push_back(top0);
top1->neighbors.push_back(top2);
top2->neighbors.push_back(top0);
top2->neighbors.push_back(top1);
top2->neighbors.push_back(top2);
Solution s;
s.PrintGraph(top0);
UndirectedGraphNode* newtop=s.cloneGraph(top0);
s.PrintGraph(newtop);
}
