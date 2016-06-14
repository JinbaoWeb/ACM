#include <bits/stdc++.h>
using namespace std;
#define MAXN 4005
struct Node{
	int l,r;
	int col;
}P[MAXN];
int a[MAXN];
int b[MAXN];
struct No{
	int l,r;
	int num;
	int id;
}ans[10*MAXN];
int main(){
	int n;
	while (~scanf("%d",&n)){
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		int k=0;
		for (int i=0;i<n;i++){
			char s;
			scanf("%d%d",&P[i].l,&P[i].r);
			cin>>s;
			if (s=='b') P[i].col=0;
			else P[i].col=1;
			a[k++]=P[i].l,a[k++]=P[i].r;
		}
		sort(a,a+k);
		int cnt=unique(a,a+k)-a;
		for (int i=0;i<n;i++){
			int x=lower_bound(a,a+cnt,P[i].l)-a+1;
			int y=lower_bound(a,a+cnt,P[i].r)-a+1;
			for (int j=x;j<=y;j++){
				b[j]=P[i].col;
			}
		}
		int t=0;
		for (int i=0;i<10;i++)
			cout<<b[i];
		cout<<endl;
		for (int i=0;i<MAXN;i++){
			if (b[i]==1){
				int num=1,j;
				for (j=i+1;;j++){
					if (b[j]==1)
						num++;
					else
						break;
				}
				ans[t].l=i,ans[t].r=j-1,ans[t].num=num,ans[t].id=t;
				t++;
				i=j-1;
			}
		}
		if (t==0){
			cout<<"Oh, my god"<<endl;
			continue;
		}
		for (int i=0;i<t;i++){
			cout<<ans[i].l<<" "<<ans[i].r<<endl;
		}
		int index=-1,Max=-1;
		for (int i=0;i<t;i++){
			if (ans[i].num>Max){
				Max=ans[i].num;
				index=i;
			}
		}
		cout<<a[ans[index].l-1]<<" "<<a[ans[index].r-1]<<endl;
	}
	return 0;
}