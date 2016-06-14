#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
typedef long long ll;
struct Matrix{
	ll mat[2][2];
};
Matrix mul(Matrix a,Matrix b,ll mod){
	Matrix ans;
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			ans.mat[i][j]=0;
			for (int k=0;k<2;k++){
				ans.mat[i][j]=(ans.mat[i][j]+a.mat[i][k]*b.mat[k][j]);
				ans.mat[i][j]%=mod;
			}
		}
	}
	return ans;
}
Matrix Init(){
	Matrix ans;
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			if (i==j)
				ans.mat[i][j]=1;
			else
				ans.mat[i][j]=0;
		}
	}
	return ans;
}
Matrix exp(Matrix a,ll k,ll m){
	Matrix ans=Init();
	while (k){
		if (k&1)
			ans=mul(ans,a,m);
		a=mul(a,a,m);
		k>>=1;
	}
	return ans;
}
int main(){
	Matrix M;
	ll a,b,n;
	ll m;
	while (~scanf("%lld%lld%lld%lld",&a,&b,&n,&m)){
		M.mat[0][0]=M.mat[1][1]=a;
		M.mat[0][1]=b;
		M.mat[1][0]=1;
		Matrix ans=exp(M,n,m);
		/*
		for (int i=0;i<2;i++){
			for (int j=0;j<2;j++)
				cout<<ans.mat[i][j]<<" ";
			cout<<endl;
		}
		*/
		ll x=ans.mat[0][0];

		cout<<(2*x)%m<<endl;
	}
	return 0;
}