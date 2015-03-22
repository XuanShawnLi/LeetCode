/*
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
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
		//14ms
		int nrow=dungeon.size();
		if(nrow<1){return 1;}
		int ncol=dungeon[0].size();
		if(ncol<1){return 1;} 
		int** dp=new int*[nrow];
		for(int i=0;i<nrow;i++)
			{dp[i]=new int[ncol];}
		dp[nrow-1][ncol-1]=1;
		for(int i=nrow-2;i>=0;i--)//last column
			{dp[i][ncol-1]=max(1,dp[i+1][ncol-1]-dungeon[i+1][ncol-1]);}
		for(int j=ncol-2;j>=0;j--)//last row
            {dp[nrow-1][j]=max(1,dp[nrow-1][j+1]-dungeon[nrow-1][j+1]);}
		for(int i=nrow-2;i>=0;i--)
			{for(int j=ncol-2;j>=0;j--)
				{int left=max(1,dp[i][j+1]-dungeon[i][j+1]);
				 int up=max(1,dp[i+1][j]-dungeon[i+1][j]);
				 dp[i][j]=min(left,up);
				}
			}
		return max(1,dp[0][0]-dungeon[0][0]);
    }
};

#define Size(a) sizeof(a)/sizeof(a[0])

void VectorCopy(int**a,int nrow,int ncol,vector<vector<int> > &dungeon){
	for(int i=0;i<nrow;i++)
		{vector<int> tmp;
		 for(int j=0;j<ncol;j++)
			{tmp.push_back(a[i][j]);}
		 dungeon.push_back(tmp);
		}
}

int main()
{Solution s;
 int b[]={1,-3,3,0,-2,0,-3,-3,-3};
 int nrow=3;
 int ncol=3;
 int **a=new int*[nrow];
 int k=0;
 for(int i=0;i<nrow;i++)
	{a[i]=new int[ncol];
	 for(int j=0;j<ncol;j++){a[i][j]=b[k++];}
	}
 vector<vector<int> > dungeon;
 VectorCopy(&a[0],nrow,ncol,dungeon);
 cout<<s.calculateMinimumHP(dungeon)<<" =3"<<endl; 
  
}
