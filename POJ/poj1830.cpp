#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int map[30][30];
int t,n,x,a,b;
int Guass(){
	int res=0,r=0;
	for (int i=0;i<n;i++){
		for (int j=r;j<n;j++){
			if (map[j][i]>0){
				for (int k=i;k<=n;k++){
					int temp=map[j][k];
					map[j][k]=map[r][k];
					map[r][k]=temp;
				}
				break;
			}
		}
		if (map[r][i]==0){
			res++;
			continue;
		}
		for (int j=0;j<n;j++){
			if (i!=j&&map[j][i]!=0){
				for (int k=i;k<=n;k++){
					map[j][k]=map[j][k]^map[i][k];
				}
			}	
		}
		r++;
	}
	int k;
	for (k=n-1;k>=0;k--){
		if (map[k][k]!=0)
			break;
		if (map[k][k]==0&&map[k][k+1]!=0)
			return -1;
	}
	if (k==n-1)
		return 1;
	else
		return pow(2.0,n-1-k);
}

int main(){
	cin>>t;
	while (t--){
		cin>>n;
		memset(map,0,sizeof(map));
		for (int i=0;i<n;i++){
			cin>>x;
			map[i][n]=-x;
		}
		for (int i=0;i<n;i++){
			cin>>x;
			map[i][n]+=x;
			map[i][n]%=2;
			map[i][i]=1;
		}
		while (cin>>a>>b){
			if (a==0&&b==0)
				break;
			map[b-1][a-1]=1;
		}
		int ans=Guass();
		if (ans<0)
			cout<<"Oh,it's impossible~!!"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}