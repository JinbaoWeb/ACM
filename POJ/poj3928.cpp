#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 100000+10;
typedef long long ll;
//BIT
int c[MAXN];
int lowbit(int x){
	return x&(-x);
}
void update(int x,int add){
	while (x<MAXN){
		c[x]+=add;
		x+=lowbit(x);
	}
}
ll get_sum(int x){
	ll ans=0;
	while (x>0){
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
int a[MAXN];
ll l[MAXN],r[MAXN];
ll l2[MAXN],r2[MAXN];
int main(){
	int t,n;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		memset(c,0,sizeof(c));
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
			l[i]=get_sum(a[i]-1);
			update(a[i],1);
		}
		memset(c,0,sizeof(c));
		for (int i=n-1;i>=0;i--){
			r[i]=get_sum(MAXN-5)-get_sum(a[i]);
			update(a[i],1);
		}
		memset(c,0,sizeof(c));
		for (int i=0;i<n;i++){
			r2[i]=get_sum(MAXN-5)-get_sum(a[i]);
			update(a[i],1);
		}
		memset(c,0,sizeof(c));
		for (int i=n-1;i>=0;i--){
			l2[i]=get_sum(a[i]-1);
			update(a[i],1);
		}
		ll ans=0;
		for (int i=0;i<n;i++){
			//cout<<l[i]<<" "<<r[i]<<" "<<l2[i]<<" "<<r2[i]<<endl;
			ans+=l[i]*r[i]+l2[i]*r2[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}