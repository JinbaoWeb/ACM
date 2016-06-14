#include <bits/stdc++.h>
using namespace std;
const int MAXN = 32;
typedef long long ll;
int b[MAXN];
int main(){
	int n;
	int x,y;
	while (~scanf("%d",&n)){
		memset(b,0,sizeof(b));
		scanf("%d",&y);
		for (int i=1;i<n;i++){
			scanf("%d",&x);
			int temp=0;
			for (int j=0;j<=31;j++){
				if (x&(1<<j)){
					temp=max(temp,b[j]+1);
				}
			}
			for (int j=0;j<=31;j++){
				if (x&(1<<j)){
					b[j]=max(temp,b[j]);
				}
			}
		}
		int Max=1;
		for (int i=0;i<32;i++)
			Max=max(Max,b[i]);
		printf("%d\n",Max);
	}
	return 0;
}