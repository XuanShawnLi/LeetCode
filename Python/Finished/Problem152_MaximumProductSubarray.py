"""
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
"""

def MaxProduct(a):
	n=len(a)
	pos=0;neg=0;res=-0xfffffff
	for i in range(n):
		if(a[i]>0):
			pos=max(pos*a[i],a[i])#either the previous is zero to set a new positive or accumulating
			neg=neg*a[i]
			res=max(res,pos)
		elif(a[i]<0):
			tmp=neg
			neg=min(pos*a[i],a[i])
			pos=tmp*a[i]
			if(pos>0):res=max(res,pos)
			res=max(a[i],res)
		else:
			neg=0;pos=0
			if(res<0):res=0
	return res


a=[-1,0,2,-3,4,-5,6,-7,8,9,-10]
#a=[-2]
print a
print MaxProduct(a)
