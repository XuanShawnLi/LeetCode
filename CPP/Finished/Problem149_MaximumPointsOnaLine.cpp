/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/
#include<iostream>
#include<vector>
#include<functional>
#include<string>
#include<sstream>
#include<tr1/functional>
#include<tr1/unordered_map>
#include<tr1/unordered_set>
using namespace std;
using namespace std::tr1;

// Definition for a point.
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}

 };

bool Compare(Point a, Point b){return a.x<b.x;}

class Solution {
public:
    int maxPoints(vector<Point> &points) {
		int n=points.size();
		if(n<3){return n;}
		sort(points.begin(),points.end(),Compare);
		int result=2;
		for(int i=0;i<n;i++)
			{Point &p1=points[i];
			 unordered_map<double,int> slope;
			 //slope is only defined with respect to a specific starting point and thus there is no yval problem. If slope same then yval is the same.
			 //thus this contains all the points that are on the same line with p1
			 double m=0.0;
			 int same_points=1;
			 int local_max=1;
			 for(int j=i+1;j<n;j++)
				{
				 Point &p2=points[j];
				 if(p1.x==p2.x and p1.y==p2.y)
					{same_points++;
					 local_max=max(local_max,same_points);//this line takes care of (0,0),(0,1),(0,0),(0,-1),(0,0) issue...so the x=0 points can be randomly placed and Compare is justified
					 continue;
					}
				 else if(p1.x==p2.x)
					{m=0xfffffff;}
				 else
					{m=double(p2.y-p1.y)/(p2.x-p1.x);}
				 if(slope.find(m)==slope.end())
					{slope.insert(make_pair(m,same_points));}
				 slope[m]++;
				 local_max=max(local_max,slope[m]);
				}
			result=max(result,local_max);
			}
		return result;
	}
};


int main()
{Solution s;
hash<string> hash_fn;

vector<Point> points;
points.push_back(Point(0,0));
points.push_back(Point(0,1));
points.push_back(Point(0,0));
points.push_back(Point(0,-1));

/*
points.push_back(Point(0,0));
points.push_back(Point(1,1));
points.push_back(Point(2,2));
points.push_back(Point(0,0));
points.push_back(Point(2,2));
points.push_back(Point(3,3));
points.push_back(Point(4,1));
*/
cout<<s.maxPoints(points)<<" == 6"<<endl;
}

