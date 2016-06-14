#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=5005;
int v[Maxn],d[Maxn],p[Maxn];
int ans[Maxn],cnt=0;
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>v[i]>>d[i]>>p[i];
	}
	for (int i=1;i<=n;i++){
		if (p[i]>=0){
			for (int j=i+1;j<=n;j++){
				p[j]-=v[i]--;
				if (v[i]==0)
					break;
			}
		}
		else{
			for (int j=i+1;j<=n;j++){
				p[j]-=d[i];
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (p[i]>=0){
			ans[++cnt]=i;
		}
	}
	cout<<cnt<<endl;
	if (cnt>0){
		cout<<ans[1];
	}
	for (int i=2;i<=cnt;i++){
		cout<<" "<<ans[i];
	}
	cout<<endl;
	return 0;
}