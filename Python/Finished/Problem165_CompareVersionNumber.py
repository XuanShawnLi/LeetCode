"""
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
"""
class Solution:
    # @param version1, a string
    # @param version2, a string
    # @return an integer
	def compareVersion(self, version1, version2):
		list1=version1.split(".")
		list2=version2.split(".")
		n1=len(list1)
		n2=len(list2)
		if(n1<n2):
			list1+=[""]*(n2-n1);n1=n2
		elif(n1>n2):
			list2+=[""]*(n1-n2);n2=n1
		for i in range(n1):
			tmp=self.Compare(list1[i],list2[i])
			if(tmp!=0):return tmp
		return tmp

	def Compare(self,word1,word2):
		word1=word1.lstrip('0')
		word2=word2.lstrip("0")
		n1=len(word1)
		n2=len(word2)
		if(n1<n2):return -1
		elif(n1>n2):return 1
		else:
			for i in range(n1):
				if(word1[i]<word2[i]):return -1
				elif(word1[i]>word2[i]):return 1
			return 0

s=Solution()
s1="01"
s2="1"
print s.compareVersion(s1,s2)
s1="1"
s2="1.2"
print s.compareVersion(s1,s2)
