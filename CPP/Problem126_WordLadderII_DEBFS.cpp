/*
 Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

Note:

    All words have the same length.
    All words contain only lowercase alphabetic characters.
*/
#include<iostream>
#include<vector>
#include<tr1/unordered_set>
#include<tr1/unordered_map>
#include<queue>
using namespace std;
using namespace std::tr1;
class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
   		vector<vector<string> > result;
		if(Distance(start,end)==1){
			result.push_back(vector<string>(1,start));
			result[0].push_back(end);
			return result;
		}
		queue<string> q1,q2,q3,*q_small;
		unordered_set<string> frontier1,frontier2,*f_small,*f_big;
		q1.push(start);q2.push(end);
		dict.erase(start);dict.erase(end);
		frontier1.insert(start);frontier2.insert(end);
		int nsize=start.length();
		vector<string> intermediate;
		unordered_map<string,vector<string> > parents1,parents2,*p_small;
		while(!q1.empty() and !q2.empty()){
			if(q1.size()<q2.size()){
				q_small=&q1;
				f_small=&frontier1;
				f_big=&frontier2;
				p_small=&parents1;
			}
			else{
				q_small=&q2;
                f_small=&frontier2;
                f_big=&frontier1;
				p_small=&parents2;
			}
			f_small->clear();
			bool found=false;
			while(!q_small->empty()){
				string current=q_small->front();q_small->pop();
				for(int pos=0;pos<nsize;pos++){
					string tmp=current;
					for(char c='a';c<='z';c++){
						if(tmp[pos]==c)continue;
						tmp[pos]=c;
						if(f_big->find(tmp)!=f_big->end()){
							found=true;
							if(p_small->find(tmp)==p_small->end()){//new element
								p_small->insert(make_pair(tmp,vector<string>(1,current)));
								intermediate.push_back(tmp);
							}
							else{
								(*p_small)[tmp].push_back(current);
							}
						}
						else if(dict.find(tmp)!=dict.end()){//in dictionary
							q3.push(tmp);f_small->insert(tmp);
							f_small->insert(tmp);
							if(p_small->find(tmp)==p_small->end()){//new element
                                p_small->insert(make_pair(tmp,vector<string>(1,current)));
                            }
                            else{
                                (*p_small)[tmp].push_back(current);
                            }
						}
					}
				}
			}
			if(found){
				ConstructVector(start,end,parents1,parents2,intermediate,result);
				return result;
			}
			else{//clear dict for fsmall
				unordered_set<string>::iterator it;
				for(it=f_small->begin();it!=f_small->end();it++){
					dict.erase(*it);
				}
			}
			swap(*q_small,q3);
		}
		return result;
    }

	void ConstructVector(string start,string end,unordered_map<string,vector<string> > &parents1,unordered_map<string,vector<string> > &parents2,vector<string> intermediate,vector<vector<string> > &result){
		int n=intermediate.size();
		vector<vector<string> > result_left;
		for(int i=0;i<n;i++){//going left
			vector<string> tmp(1,intermediate[i]);
			ConstructVector_sub(start,parents1,tmp,result_left);
		}
		for(int i=0;i<result_left.size();i++){
			reverse(result_left[i].begin(),result_left[i].end());
			ConstructVector_sub(end,parents2,result_left[i],result);
		}
	}

	void ConstructVector_sub(string start, unordered_map<string,vector<string> > &parents1, vector<string> &previous, vector<vector<string> > &result){
		string word=previous[previous.size()-1];
		if(word==start){result.push_back(previous);return;}
		int n=parents1[word].size();
		for(int i=0;i<n;i++){
			previous.push_back(parents1[word][i]);
			ConstructVector_sub(start,parents1,previous,result);
			previous.pop_back();
		}
	}

	int Distance(string start,string end){
		int n=start.length();
		int result=0;
		for(int i=0;i<n;i++){if(start[i]!=end[i])result++;}
		return result;
	}

	void PrintList(vector<vector<string> >& result){
		int n=result.size();
		cout<<"["<<endl;
		for(int i=0;i<n;i++){
			cout<<"[";
			for(int j=0;j<result[i].size();j++){cout<<result[i][j]<<" ";}
			cout<<"]"<<endl;
		}
		cout<<"]"<<endl;
	}
};

int main(){
	string start="hit";
	string end="cog";
	unordered_set<string> dict;
	dict.insert("hot");dict.insert("dot");dict.insert("dog");dict.insert("lot");dict.insert("log");
	cout<<"start:"<<start<<endl;
	cout<<"end:"<<end<<endl;
	unordered_set<string>::iterator it;
	cout<<"Dict=: [";
	for(it=dict.begin();it!=dict.end();it++){cout<<*it<<" ";}
	cout<<"]"<<endl;
	Solution s;
	vector<vector<string> > result=s.findLadders(start,end,dict);
	s.PrintList(result);
}
