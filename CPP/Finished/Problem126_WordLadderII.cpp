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
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		vector<vector<string> > result;
		if(Distance(start,end)==1){// dist==2 case
			vector<string> tmp;
			tmp.push_back(start);tmp.push_back(end);
			result.push_back(tmp);
			return result;
		}
		unordered_map<string, vector<string> > parents;
		unordered_map<string, int> distance;
		queue<string> q;
		q.push(start);distance.insert(make_pair(start,1));
		dict.erase(start);dict.erase(end);
		parents.insert(make_pair(end,vector<string>()));
		int min_distance;int found=false;
		int nsize=start.length();
		while(!q.empty()){
			string current=q.front();q.pop();
			if(found and distance[current]>min_distance)break;
			for(int pos=0;pos<nsize;pos++){
				string tmp=current;
				for(char c='a';c<='z';c++){
					if(tmp[pos]==c)continue;
					tmp[pos]=c;
					if(tmp==end){
						if(!found){found=true;min_distance=distance[current];}
						parents[end].push_back(current);
					}
					else if(dict.find(tmp)!=dict.end()){
						if(distance.find(tmp)==distance.end()){
							q.push(tmp);
							distance.insert(make_pair(tmp,distance[current]+1));
							parents.insert(make_pair(tmp,vector<string>(1,current)));
						}
						else if(distance[current]+1==distance[tmp]){
							parents[tmp].push_back(current);//dimond case
						}
					}
				}
			}
			dict.erase(current);
		}
		if(found){
        	ConstructVector(start,end,parents,result);
            return result;
        }
		return result;
	}

	int Distance(string a,string b){
		int n=a.length();
		int result=0;
		for(int i=0;i<n;i++){
			if(a[i]!=b[i])result++;
		}
		return result;
	}

	void ConstructVector(string &start,string &end,unordered_map<string, vector<string> > &parents,vector<vector<string> > &result){
		vector<string> tmp(1,end);
		ConstructVector_sub(start,tmp,parents,result);
		int n=result.size();
		for(int i=0;i<n;i++){
			reverse(result[i].begin(),result[i].end());
		}
	}

	void ConstructVector_sub(string &start,vector<string> previous,unordered_map<string, vector<string> > &parents,vector<vector<string> > &result){
		string word=previous[previous.size()-1];
		if(word==start){//start to put it in result
			result.push_back(previous);
			return;
		}
		int m=parents[word].size();
		for(int i=0;i<m;i++){
			previous.push_back(parents[word][i]);
            ConstructVector_sub(start,previous,parents,result);
			previous.pop_back();
        } 
	}
    void Print(vector<vector<string> > result){
        for(int i=0;i<result.size();i++){
            cout<<"[ ";
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j]<<" ";
            }
            cout<<"]"<<endl;
        }
    }
};

int main(){
    Solution s;
    unordered_set<string> dict;
/*    string start="hit";
    string end="cog";
    dict.insert("hot");dict.insert("dot");dict.insert("dog");
    dict.insert("lot");dict.insert("log");
*/
	string start="a";string end="c";
	dict.insert("a");dict.insert("b");dict.insert("c");

    cout<<"start= "<<start<<" and end= "<<end<<endl;
    unordered_set<string>::iterator it;
    cout<<"dict has:"<<endl;
    for(it=dict.begin();it!=dict.end();it++){cout<<*it<<endl;}
    cout<<"----"<<endl;
    vector<vector<string> >result=s.findLadders(start,end,dict);
    s.Print(result);
}

