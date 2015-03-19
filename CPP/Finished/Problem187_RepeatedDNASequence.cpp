/*
 All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/
#include<iostream>
#include<vector>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;

class Solution {
public:

    vector<string> findRepeatedDnaSequences_stringmap(string s) {
        unordered_map<string,int> dict;
		vector<string> result;
		int n=s.length();
		int m=n-10+1;
		string tmp;
		unordered_map<string,int>::iterator it;
		for(int i=0;i<m;i++)
			{tmp=s.substr(i,10);
			 it=dict.find(tmp);
			 if(it==dict.end())
				{dict.insert(make_pair(tmp,1));}
			 else
				{dict[tmp]++;
				if(dict[tmp]==2){result.push_back(tmp);}
				}
			}
		return result;
    }

	vector<string> findRepeatedDnaSequences(string s) {
//238ms
        unordered_map<int,int> dict;
        vector<string> result;
        int n=s.length();
        int m=n-10+1;
        string tmp;
		int num;
        unordered_map<int,int>::iterator it;
		unordered_map<char,int> Hash_dict;//({ {'A',0},{'C',1},{'G',2},{'T',3} });
		Hash_dict.insert(make_pair('A',0));
		Hash_dict.insert(make_pair('C',1));
		Hash_dict.insert(make_pair('G',2));
		Hash_dict.insert(make_pair('T',3));
        for(int i=0;i<m;i++)
            {tmp=s.substr(i,10);
			 num=HashFun(tmp,Hash_dict);
             it=dict.find(num);
             if(it==dict.end())
                {dict.insert(make_pair(num,1));}
             else
                {dict[num]++;
                if(dict[num]==2){result.push_back(tmp);}
                }
            }
        return result;
    }

	int HashFun(string &word,unordered_map<char,int> &Hash_dict)
	{int n=word.length();
	 int result=0;
	 for(int i=0;i<n;i++)
		{result+=Hash_dict[word[i]];
		 result=result*4;
		}
	return result;
	}

	vector<string> findRepeatedDnaSequences_Bucket(string s) {
//130ms
        unordered_map<int,int> dict;
        vector<string> result;
        int n=s.length();
        int m=n-10+1;
        int num;
        unordered_map<int,int>::iterator it;
		int Bucket['Z'];
		Bucket['A']=0;
		Bucket['C']=1;
		Bucket['G']=2;
		Bucket['T']=3;
        for(int i=0;i<m;i++)
            {
			 num=0;
			 for(int j=0;j<10;j++)
				{num+=Bucket[s[i+j]];
				 num=num<<2;
				}
             it=dict.find(num);
             if(it==dict.end())
                {dict.insert(make_pair(num,1));}
             else
                {dict[num]++;
                if(dict[num]==2){result.push_back(s.substr(i,10));}
                }
            }
        return result;
    }

};

int main()
{Solution s;
 string word="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
 //string word="AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";	
 vector<string> result=s.findRepeatedDnaSequences_Bucket(word);
 cout<<"Initial string= "<<word<<endl;
 vector<string>::iterator it;
 for(it=result.begin();it!=result.end();it++)
	{
	 cout<<(*it)<<endl;
	}

}
