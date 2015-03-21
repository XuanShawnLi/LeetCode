/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Credits:
Special thanks to @porker2008 for adding this problem and creating all test cases.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maximumGap_NLOGN(vector<int> &num) {
		int n=num.size();
		if(n<2){return 0;}	
		sort(num.begin(),num.end());
		int result=0;
		for(int i=0;i<n-1;i++)
			{if(num[i+1]-num[i]>result){result=num[i+1]-num[i];}}
		return result;
	}

	int maximumGap(vector<int> &num) {
		int n=num.size();
		if(n<2){return 0;}
		long big=num[0];
		long small=num[0];
		for(int i=0;i<n;i++)
			{if(num[i]<small)small=num[i];
			 if(num[i]>big)big=num[i];
			}
		int BucketSize=max(int((big-small)/(n-1)),1);
		int m=(big-small)/BucketSize+1;
		vector< vector<int> > Buckets(m,vector<int>(0));
		for(int i=0;i<n;i++)
			{int index=(num[i]-small)/BucketSize;
			 Buckets[index].push_back(num[i]);
			}
		vector<long> boundaries_min;
		vector<long> boundaries_max;
		for(int i=0;i<m;i++)
			{if(Buckets[i].size()>0)
				{big=Buckets[i][0];small=big;
				 int mm=Buckets[i].size();
				 for(int j=0;j<mm;j++)
					{if(Buckets[i][j]<small)small=Buckets[i][j];
					 if(Buckets[i][j]>big)big=Buckets[i][j];
					}
				 boundaries_min.push_back(small);boundaries_max.push_back(big);
				}
			}
		int mm=boundaries_min.size();
		int result=-1;
		for(int i=0;i<mm-1;i++)
			{if(boundaries_min[i+1]-boundaries_max[i]>result)result=boundaries_min[i+1]-boundaries_max[i];}
		return result;
	}
};

#define Size(a) sizeof(a)/sizeof(a[0])

int main()
{
//int a[]={1,2,14,29,109,108,7};
int a[]={1,1,1,1,1,5,5,5,5,5};
//int a[]={601408776,63967816,431363697,242509930,15970592,60284088,228037800,147629558,220782926,55455864,456541040,106650540,17290078,52153098,103139530,294196042,16568100,426864152,61916064,657788565,166159446,1741650,101791800,28206276,6223796,524849590,125389882,84399672,153834912,164568204,1866165,283209696,560993994,16266096,219635658,9188983,485969304,782013650,120332636,44659356,444517408,36369045,47370708,18542592,98802990,137690000,124889895,56062800,265421676,309417680,4634176,801661539,510541206,258227892,398938089,47255754,152260962,409663140,102847688,45756553,377936600,269498,375738702,263761134,53797945,329493948,224442208,508336845,189507850,40944620,127879560,119629476,186894520,62409156,693721503,4289916,523899936,28955240,266488028,20356650,40769391,483694272,97988044,84102,67246047,310688630,41288643,58965588,42881432,152159462,94786355,174917835,119224652,525034376,261516,274800528,62643819,23613832,8397240,797832131,855155367,337066320,26341480,61932200,20661075,515542796,390337500,522552030,43538516,150800550,116747540,152989123,488640056,700610304,233604,344277340,21439176,9397864,16365822,73027584,453041413,197374275,157735188,15273822,187081152,379611084,865005504,223099767,80478651,377729400,186738219,34738263,16634072,112791343,99631856,119364960,477106486,583953920,624509809,188442472,294181256,213023715,146645884,149530380,497592753,132170327,72770643,126683010,405141255,590214306,26670714,95582385,162080790,231120099,8946432,204967980,592849110,54120698,375915096,602145859,5346440,226337825,425156369,653591624,578483360,572410800,32290700,381384563,149939976,183225375,155695620,38307636,457513760,97085778,75200576,8068176,221650296,556889418,252495726,895020231,19932465,156334887,191383314,348432526,368701264,14315598,148936587,279419435,237325542,252587218,322929504,26331343,355297676,600420786,652017765,51673622,159015675};
//int a[]={1,10000000};
//int a[]={100,3,2,1};
int n=Size(a);
vector<int> num(a,a+n);
Solution s;
cout<<s.maximumGap_NLOGN(num)<<endl;
cout<<s.maximumGap(num)<<endl;
}
