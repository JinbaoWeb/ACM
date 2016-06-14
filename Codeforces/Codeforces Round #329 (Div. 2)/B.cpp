#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2*100010;
int a[4*MAXN];
int lowbit(int x)
{
    return x & (-x);
}
void modify(int x,int add)//一维
{  
    while(x<=MAXN)  //n为数组的大小
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
struct point{
	int x,y;
}P[MAXN];
/*
bool cmp(point aa,point bb){
	if (aa.x!=bb.x)
		return aa.x<bb.x;
	return aa.y>bb.y;
}
*/
bool cmp(point aa,point bb){
	if (aa.y!=bb.y)
		return aa.y<bb.y;
	return aa.x<bb.x;
}
int PP[2*MAXN];
int main(){
	int n,x1,x2;
	scanf("%d",&n);
	scanf("%d%d",&x1,&x2);
	memset(a,0,sizeof(a));
	int k=0;
	for (int i=0;i<n;i++){
		int kk,b;
		scanf("%d%d",&kk,&b);
		P[i].x=kk*x1+b;
		P[i].y=kk*x2+b;
		PP[k++]=P[i].x;
		PP[k++]=P[i].y;
	}
	sort(P,P+n,cmp);
	sort(PP,PP+k);
	k=unique(PP,PP+k)-PP;
	int flag=0;
	for (int i=0;i<n;i++){
		int x=lower_bound(PP,PP+k,P[i].x)-PP+1;
		int temp=get_sum(MAXN)-get_sum(x);
		//cout<<temp<<" "<<x<<endl;
		if (temp>=1){
			flag=1;
			break;
		}
		modify(x,1);
	}
	if (flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}