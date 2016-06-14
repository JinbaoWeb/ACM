#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
ll n,m,k;
struct Matrix{
	ll mat[31][31];
};
Matrix add(Matrix a,Matrix b){
	Matrix ans;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			ans.mat[i][j]=a.mat[i][j]+b.mat[i][j];
			if (ans.mat[i][j]>=m){
				ans.mat[i][j]%=m;
			}
		}
	}
	return ans;
}
Matrix mul(Matrix a,Matrix b){
	Matrix ans;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			ans.mat[i][j]=0;
			for (int k=0;k<n;k++){
				ans.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
				if (ans.mat[i][j]>=m){
					ans.mat[i][j]%=m;
				}
			}
		}
	}
	return ans;
}
Matrix Init(){
	Matrix ans;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i==j)
				ans.mat[i][j]=1;
			else
				ans.mat[i][j]=0;
		}
	}
	return ans;
}
Matrix exp(Matrix a,int k){
	Matrix ans=Init();
	while (k){
		if (k&1)
			ans=mul(ans,a);
		a=mul(a,a);
		k>>=1;
	}
	return ans;
}
Matrix Calculate(Matrix a,int k){
	Matrix ans;
	memset(ans.mat,0,sizeof(ans.mat));
	Matrix temp=Init();
	if (k==1)
		return a;
	if (k%2)
		ans=add(Calculate(a,k-1),exp(a,k));
	else{
		Matrix s=Calculate(a,k/2);
		ans=add(s,mul(s,exp(a,k/2)));
	}
	return ans;
}
int main(){
	Matrix a;
	while (cin>>a.mat[0][0]>>k){
		n=1;
		m=1000000007;
		if (a.mat[0][0]==1&& k==1)
		{
			cout<<1<<endl;
			continue;
		}
		Matrix ans=Calculate(a,k);
		cout<<ans.mat[0][0]+1<<endl;
		
	}
	return 0;
}