/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 
*/
#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        s=RemoveSpace(s);
		return isPalindrome_sub(s);
    }

	string RemoveSpace(string s){
		string result="";
		int n=s.length();
		for(int i=0;i<n;i++){
			if(s[i]<='z' and s[i]>='a'){
				result+=s[i];
			}
			else if(s[i]<='Z' and s[i]>='A'){
				result+=(s[i]-'A'+'a');
			}
			else if(s[i]<='9' and s[i]>='0'){
				result+=s[i];
			}
		}
		return result;
	}

	bool isPalindrome_sub(string word){
		int left=0,right=word.length()-1;
		while(left<right){
			if(word[left++]!=word[right--])return false;
		}
		return true;
	}
};

int main(){
	Solution s;
	string word="A man, a plan, a canal: Panama";
	cout<<s.isPalindrome(word)<<endl;
	word="race a car";
	cout<<s.isPalindrome(word)<<endl;
	word="1A2";
	cout<<s.isPalindrome(word)<<endl;
}
