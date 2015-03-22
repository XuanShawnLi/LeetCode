"""
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
"""
class Solution:
	# @param dungeon, a list of lists of integers
	# @return a integer
	def calculateMinimumHP_slow(self, dungeon):
		#139ms
		nrow=len(dungeon)
		if(nrow<1):return 1
		ncol=len(dungeon[0])
		if(ncol<1):return 1
		current1=[[0 for j in range(ncol)] for i in range(nrow)]
		current2=[[0 for j in range(ncol)] for i in range(nrow)]
		result1=[[0 for j in range(ncol)] for i in range(nrow)]
		result2=[[0 for j in range(ncol)] for i in range(nrow)]
		current2[0][0]=current1[0][0]=dungeon[0][0]
		result2[0][0]=result1[0][0]=min(dungeon[0][0],0)
		for j in range(1,ncol):#process the first row
			current2[0][j]=current1[0][j]=dungeon[0][j]+current1[0][j-1]
			result2[0][j]=result1[0][j]=min(result1[0][j-1],current1[0][j])
		for i in range(1,nrow):#process the first column
			current2[i][0]=current1[i][0]=dungeon[i][0]+current1[i-1][0]
			result2[i][0]=result1[i][0]=min(result1[i-1][0],current1[i][0])
		#list 1 stores the current sum and the initial health needed where sum is the biggest
		#list 2 stores the current sum and the initial health needed where the -(intial health needed) is the largest 
		for i in range(1,nrow):
			for j in range(1,ncol):
				#assumption c1>c2:cup1>cup2,cleft1>cleft2: only has to compare cup1 and cleft1 to get c1
				#assumption r1<r2:rup1<rup2? 
				cup1=dungeon[i][j]+current1[i-1][j]
				cup2=dungeon[i][j]+current2[i-1][j]
				rup1=min(result1[i-1][j],cup1)
				rup2=min(result2[i-1][j],cup2)	
				cleft1=dungeon[i][j]+current1[i][j-1]
				cleft2=dungeon[i][j]+current2[i][j-1]
				rleft1=min(result1[i][j-1],cleft1)
				rleft2=min(result2[i][j-1],cleft2)
				if(cup1<cleft1):
					current1[i][j]=cleft1;result1[i][j]=rleft1
				else:
					current1[i][j]=cup1;result1[i][j]=rup1
				a=sorted([(rup1,cup1),(rup2,cup2),(rleft1,cleft1),(rleft2,cleft2)])
				result2[i][j]=a[3][0];current2[i][j]=a[3][1]
		return -result2[nrow-1][ncol-1]+1

	def calculateMinimumHP(self,dungeon):
		#86ms
		nrow=len(dungeon)
		if(nrow<1):return 1
		ncol=len(dungeon[0])
		if(ncol<1):return 1
		dp=[[1 for j in range(ncol)] for i in range(nrow)]
		for i in range(nrow-2,-1,-1):#process last colume
			dp[i][ncol-1]=max(1,dp[i+1][ncol-1]-dungeon[i+1][ncol-1])
		for j in range(ncol-2,-1,-1):#process last row
			dp[nrow-1][j]=max(1,dp[nrow-1][j+1]-dungeon[nrow-1][j+1])
		for i in range(nrow-2,-1,-1):
			for j in range(ncol-2,-1,-1):
				up=max(1,dp[i+1][j]-dungeon[i+1][j])
				left=max(1,dp[i][j+1]-dungeon[i][j+1])
				dp[i][j]=min(up,left)
		return max(1,dp[0][0]-dungeon[0][0])


s=Solution()
dungeon=[[-2,-3,3],[-5,-10,1],[10,30,-5]]
for x in dungeon:print x
print s.calculateMinimumHP_slow(dungeon),"==",7
print s.calculateMinimumHP(dungeon),"==",7
dungeon=[[100]]
for x in dungeon:print x
print s.calculateMinimumHP_slow(dungeon),"==",1
print s.calculateMinimumHP(dungeon),"==",1
dungeon=[[1,-3,3],[0,-2,0],[-3,-3,-3]]
for x in dungeon:print x
print s.calculateMinimumHP_slow(dungeon),"==",3
print s.calculateMinimumHP(dungeon),"==",3
dungeon=[[2],[1]]
for x in dungeon:print x
print s.calculateMinimumHP(dungeon),"==",1

