#include <iostream>
#include <string.h>
using namespace std;
int dp[1002];
int num[12];	//bag
int c[12];	//weight
int w[12];	//value
int t,n,m,c0,d0,ai,bi,ci,di;
void ZeroOne_Pack(int cost,int weight,int n){
    for(int i=n; i>=cost; i--)
        dp[i] = max(dp[i],dp[i-cost] + weight);
}

void Complete_Pack(int cost,int weight,int n){
    for(int i=cost; i<=n; i++)
        dp[i] = max(dp[i],dp[i-cost] + weight);
}

int Multi_Pack(int c[],int w[],int num[],int n,int m){
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++){
        if(num[i]*c[i] > m)
            Complete_Pack(c[i],w[i],m);
        else{
            int k = 1;
            while(k < num[i]){
                ZeroOne_Pack(k*c[i],k*w[i],m);
                num[i] -= k;
                k <<= 1;
            }
            ZeroOne_Pack(num[i]*c[i],num[i]*w[i],m);
        }
    }
    return dp[m];
}

int main(){
	cin>>t;
	while (t--){
		cin>>n>>m>>c0>>d0;
		for(int i=1;i<=m;i++){
			cin>>ai>>bi>>ci>>di;
			num[i]=ai/bi;
			c[i]=ci;
			w[i]=di;
		}
		num[m+1]=n/c0;
		c[m+1]=c0;
		w[m+1]=d0;
		cout<<Multi_Pack(c,w,num,m+1,n)<<endl;
	}
	return 0;
}
