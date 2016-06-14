#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int p,n;
const int mod=10000;

int dfs(int p,int now){
	int col,row;
	row=(now+1)/p+1;
	col=(now+1)%p;
	if (col==0){
		col=p;
		row--;
	}

	if (now<p*p){
		//cout<<p<<" "<<now<<endl;
		//cout<<"ret:"<<col*row%mod<<endl;;
		return (col*row)%mod;
	}

	int k=dfs(p,now/(p*p));

	//cout<<p<<" "<<now<<endl;
	//cout<<"ret:"<<k*row%mod*col%mod<<endl;

	int left=now%(p*p);
	row=(left+1)/p+1;
	col=(left+1)%p;
	if (col==0){
		col=p;
		row--;
	}
	//cout<<"ret:"<<k*row%mod*col%mod<<endl;
	return k*row%mod*col%mod;
}

int main(){
	int ca=0;
	while (~scanf("%d%d",&p,&n)){
		if (n==0 && p==0) break;
		ca++;

		int ans=dfs(p,n);
		printf("Case %d: %04d\n",ca,ans);
	}
	return 0;
}
