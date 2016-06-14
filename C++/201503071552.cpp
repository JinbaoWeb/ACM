#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
struct city{
	int num;
	int first,second;
	int c;
}p[102];
bool cmp(city a,city b){
	if (a.c>b.c)
		return true;
	else{
		if (a.c==b.c){
			if (a.second<b.second)
				return true;
			else{
				if (a.second==b.second){
					if (a.num<b.num)
						return true;
					else
						return false;
				}
				else
					return false;
			}
		}
		else
			return false;
	}
}
int main(){
	int n;
	while (cin>>n){
		for (int i=0;i<n;i++){
			cin>>p[i].first>>p[i].second;
			p[i].num=i;
			p[i].c=p[i].first-p[i].second;
		}
		sort(p,p+n,cmp);
		for (int i=0;i<n;i++){
			if (i==0)
				cout<<p[i].num;
			else
				cout<<" "<<p[i].num;
		}
		cout<<endl;
	}
	return 0;
}