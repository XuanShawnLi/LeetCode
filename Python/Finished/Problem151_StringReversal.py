"""
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
"""
class Solution:
	# @param s, a string
	# @return a string
	def reverseWords(self, s):
		newword=s.strip()
		wordlist=newword.split()
		wordlist.reverse()
		return " ".join(wordlist)

s=Solution()
word="   the sky is  blue  "
print word
print s.reverseWords(word)
