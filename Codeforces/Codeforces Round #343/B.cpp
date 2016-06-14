#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Pe{
	char s;
	int l,r;
}P[6000];

int main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>P[i].s>>P[i].l>>P[i].r;
	int ans=0;
	for (int i=1;i<367;i++){
		int f=0,m=0;
		for (int j=0;j<n;j++){
			if (P[j].l<=i && i<=P[j].r){
				if (P[j].s=='F')
					f++;
				else
					m++;
			}
		}
		int k=min(f,m);
		ans=max(ans,k);
	}
	cout<<ans*2<<endl;
	return 0;
}