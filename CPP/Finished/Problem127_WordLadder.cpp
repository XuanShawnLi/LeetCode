/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    int ladderLength_OneEndBFS(string start, string end, unordered_set<string> &dict) {
        int nl=26;
		string letters="abcdefghijklmnopqrstuvwxyz";
		int d=0;
		int n=start.length();
		for(int i=0;i<n;i++){if(start[i]!=end[i])d++;}
		if(d==1){return 2;}
		queue<string> q;
		q.push(start);
		unordered_map<string,int> distance;
		distance.insert(make_pair(start,1));
		while(not(q.empty())){
			string current=q.front();q.pop();
			for(int i=0;i<n;i++){
				for(int il=0;il<nl;il++){
					string newword=current.substr(0,i)+letters[il]+current.substr(i+1,n-i-1);
					if(newword==end){return distance[current]+1;}
					if(newword!=current and dict.find(newword)!=dict.end() and distance.find(newword)==distance.end()){
						distance[newword]=distance[current]+1;
						q.push(newword);
						dict.erase(newword);//913ms->836ms
					}
				}
			}
		}
		return 0;
    }

	int ladderLength(string start, string end, unordered_set<string> &dict) {
		//80ms!!! great improvement since it is a double-ended breath-first-search
		queue<string> q1,q2,q3;
		unordered_set<string> frontier1,frontier2;//1(2):trees expanded from start (end)
		frontier1.insert(start);frontier2.insert(end);
		q1.push(start);q2.push(end);
		int dist=1;int nsize=start.length();
		while(!q1.empty() and !q2.empty()){
			if(q1.size()<q2.size()){//expand q1
				frontier1.clear();
				while(!q1.empty()){
					string current=q1.front();q1.pop();
					for(int pos=0;pos<nsize;pos++){
						string tmp=current;
						for(char c='a';c<='z';c++){
							if(c==tmp[pos])continue;
							tmp[pos]=c;
							if(frontier2.find(tmp)!=frontier2.end()){return dist+1;}
							if(dict.find(tmp)!=dict.end()){
								q3.push(tmp);//q3 will be the next q1 
								frontier1.insert(tmp);
								dict.erase(tmp);
							}
						}
					}
				}//q1 now empty
				dist++;
				swap(q1,q3);
			}
			else{
				frontier2.clear();
                while(!q2.empty()){
                    string current=q2.front();q2.pop();
                    for(int pos=0;pos<nsize;pos++){
                        string tmp=current;
                        for(char c='a';c<='z';c++){
                            if(c==tmp[pos])continue;
                            tmp[pos]=c;
                            if(frontier1.find(tmp)!=frontier1.end()){return dist+1;}
                            if(dict.find(tmp)!=dict.end()){
                                q3.push(tmp);//q3 will be the next q1 
                                frontier2.insert(tmp);
                                dict.erase(tmp);
                            }
                        }
                    }
                }//q2 now empty
                dist++;
                swap(q2,q3);
			}
		}
		return 0;

	}
};

int main(){
	Solution s;
	string start="hit";
	string end="cog";
	unordered_set<string> dict;
	dict.insert("hot");dict.insert("dot");dict.insert("dog");
	dict.insert("lot");dict.insert("log");
	cout<<s.ladderLength(start,end,dict)<<"==5"<<endl;
}
