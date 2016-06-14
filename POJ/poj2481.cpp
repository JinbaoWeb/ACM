#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAXN = 100000+10;
struct Node{
	int l,r,id;
}cow[MAXN];
int a[MAXN];
int ans[MAXN];
int lowbit(int x)
{
    return x & (-x);
}
void modify(int x,int add)
{  
    while(x<=MAXN)
    {      
        a[x]+=add;    
        x+=lowbit(x); 
    }
}
int get_sum(int x)
{  
    int ret=0; 
    while(x!=0)  
    {       
        ret+=a[x];   
        x-=lowbit(x);   
    }  
    return ret;
}
bool cmp(Node x,Node y){
	if (x.r!=y.r)
		return x.r>y.r;
	return x.l<y.l;
}
int main(){
	int n;
	while (~scanf("%d",&n)){
		if (n==0)
			break;
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		for (int i=0;i<n;i++){
			scanf("%d%d",&cow[i].l,&cow[i].r);
			cow[i].l++,cow[i].r++,cow[i].id=i;
		}
		sort(cow,cow+n,cmp);
		for (int i=0;i<n;i++){
			if (i!=0 && cow[i].l==cow[i-1].l && cow[i].r==cow[i-1].r)
				ans[cow[i].id]=ans[cow[i-1].id];
			else
				ans[cow[i].id]=get_sum(cow[i].l);
			modify(cow[i].l,1);

		}
		for (int i=0;i<n;i++){
			if (i==n-1)
				printf("%d\n",ans[i]);
			else
				printf("%d ",ans[i]);
		}
	}

	return 0;
}