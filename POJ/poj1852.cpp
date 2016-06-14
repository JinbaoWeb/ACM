#include <iostream>
#include <algorithm>
using namespace std;
#define M 1000005
int main()
{
	int t,len,n,a;
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		cin>>len>>n;
		int min=0;
		int minmin=0xffffff,maxmax=0;
		for (int i=0;i<n;i++)
		{
			cin>>a;
			int s=a<(len-a)?a:(len-a);
			if (s>min)
				min=s;
			if (minmin>a)
				minmin=a;
			if (maxmax<a)
				maxmax=a; 
		}
		int max=(len-minmin)>maxmax?(len-minmin):maxmax;
		cout<<min<<" "<<max<<endl;
	}
	return 0;
}
