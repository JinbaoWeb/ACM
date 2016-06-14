#include <stdio.h>
#include <iostream>
using namespace std;
#define mod 1000000007
typedef long long ll;
struct Matrix{
	ll mat[2][2];
}; 
void Init(Matrix &x){
	x.mat[0][0]=1;
	x.mat[0][1]=x.mat[1][0]=0;
	x.mat[1][1]=1;
}
Matrix mul(Matrix a,Matrix b){
	Matrix ans;
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			ans.mat[i][j]=0;
			for (int k=0;k<2;k++)
				ans.mat[i][j]=(ans.mat[i][j]+a.mat[i][k]*b.mat[k][j])%(mod-1);
			ans.mat[i][j]%=(mod-1);
		}
	}
	return ans;
}
Matrix mod_pow(Matrix a,ll n){
	Matrix ans;
	Init(ans);
	while (n>0){
		if (n&1)
			ans=mul(ans,a);
		a=mul(a,a);
		n/=2;
	}
	return ans;
}
ll pow(ll a,ll b){
    ll res=1;
    while (b>0){
        if (b&1)    res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int main(){
	ll x,y,n;
	while (cin>>x>>y>>n){
		Matrix a;
		a.mat[0][0]=a.mat[0][1]=a.mat[1][0]=1;
		a.mat[1][1]=0;
		Matrix ans=mod_pow(a,n);
		ll x_pow=ans.mat[1][1];
		ll y_pow=ans.mat[1][0];
		cout<<(pow(x,x_pow)*pow(y,y_pow))%mod<<endl;
	}
	return 0;
}