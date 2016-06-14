#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,i,j,k,v[4002],d[4002],p[4002],cnt=0,v1,d1,p1,x;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>v[i]>>d[i]>>p[i];
	i=0;
	queue<int> q;
	vector<int> hhh;
	for (i=0;i<n;i++){
		if (p[i]<0)
			continue;
		hhh.push_back(i+1);
		v1=v[i];
		j=i+1;
		while (j<n){
			if (p[j]>=0){
				p[j]-=v1;
				if (p[j]<0)
					q.push(j);
				v1--;
				if (v1<=0)
					break;
			}
			j++;
		}
		while (q.empty()==0){
			x=q.front();
			for (k=x+1;k<n;k++){
				if (p[k]>=0){
					p[k]-=d[x];
					if (p[k]<0)
						q.push(k);
				}
			}
			q.pop();
		}
	}
	cout<<hhh.size()<<endl;
	for (i=0;i<hhh.size();i++){
		cout<<hhh[i]<<" ";
	}
	cout<<endl;
	return 0;
}