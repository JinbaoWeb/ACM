#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 400000+10
struct Node{
	int x,y;
	int id;
}P[N];
int ans[N];
int a[N];
int b[N];
int c[N];
bool cmp(Node s1,Node s2){
	if (s1.y!=s2.y)
		return s1.y<s2.y;
	return s1.x<s2.x;
}
int lowbit(int x)
{
    return x & (-x);
}
void modify(int x,int add)//一维
{  
    while(x<=N)  
    {      
        c[x]+=add;    
        x+=lowbit(x); 
    }
}
int get_sum(int x)
{  
    int ret=0; 
    while(x!=0)  
    {       
        ret+=c[x];   
        x-=lowbit(x);   
    }  
    return ret;
}
int main(){
	int n;
	while (~scanf("%d",&n)){
		memset(c,0,sizeof(c));
		for (int i=0;i<2*n;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		sort(b,b+n*2);
		int cnt=unique(b,b+n*2)-b;
		for (int i=0;i<2*n;i+=2){
			int x=lower_bound(b,b+cnt,a[i])-b+1;
			int y=lower_bound(b,b+cnt,a[i+1])-b+1;
			P[i/2].x=x,P[i/2].y=y,P[i/2].id=i/2;
		}
		sort(P,P+n,cmp);
		for (int i=0;i<n;i++){
			ans[P[i].id]=get_sum(N)-get_sum(P[i].x-1);
			modify(P[i].x,1);
		}
		for (int i=0;i<n;i++){
			cout<<ans[i]<<endl;
		}
		cout<<endl;
	}
	return 0;
}