#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define M 100005
struct point{
	int x,y;
}p[M];
bool cmp(point a,point b){
	if (a.x<b.x)
		return true;
	return false;
}
int main(){
	int t,n,x,y;
	cin>>t;
	while(t--){
		cin>>n;
		int max=0;
		for (int i=0;i<n;i++){
			cin>>p[i].x>>p[i].y;
			if (p[i].y>max)
				max=p[i].y;
		}
		sort(p,p+n,cmp);
		int maxmax=0;
		for (int i=0;i<=max;i++){
			int count=0;
			for (int j=0;j<n;j++){
				if (p[j].x<=i&&p[j].y>=i)
					count++;
				if (p[j].y<i)
					break;
			}
			if (count>maxmax)
				maxmax=count;
		}
		cout<<maxmax<<endl;
	}
	return 0;
}