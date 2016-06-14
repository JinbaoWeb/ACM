#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAXN = 32000+10;
int a[MAXN];
int ans[MAXN];
int lowbit(int x)
{
    return x & (-x);
}
void modify(int x,int add)
{  
    while(x<=MAXN)  //MAXN为数组的大小
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

int main(){
	int n,x,y;
	while (~scanf("%d",&n)){
		for (int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			x++;
			ans[get_sum(x)]++;
			modify(x,1);
		}
		for (int i=0;i<n;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}