#include <iostream>  
#include <cstdio>  
#include <algorithm>  
#include <string.h>  
using namespace std;  
  
const int N = 300010,M = 300010;  
struct tree{  
    int lp,rp,len,num;  
    int getmid(){  
       return (lp + rp) / 2;  
    }  
}tt[N * 4];  

struct line{  
    int lp,rp,cnt,value;  
}LL[M * 2];  
void built_tree(int lpos,int rpos,int pos){  
    tt[pos].lp = lpos;  
    tt[pos].rp = rpos;  
    tt[pos].len = tt[pos].num = 0;  
    if(tt[pos].lp + 1 == tt[pos].rp)  
        return;  
    int mid = tt[pos].getmid();  
    built_tree(lpos,mid,pos*2);  
    built_tree(mid,rpos,pos*2+1);  
}  
bool cmp(line a,line b){  
    return a.value > b.value;  
}  
void getlen(int pos){  
    if(tt[pos].num > 0)  
        tt[pos].len = tt[pos].rp - tt[pos].lp;  
    else if(tt[pos].lp + 1 == tt[pos].rp)  
        tt[pos].len = 0;  
    else  
        tt[pos].len = tt[pos * 2].len + tt[pos * 2 + 1].len;  
}  
void update(int pos,int id){  
    if(tt[pos].lp >= LL[id].lp && tt[pos].rp <= LL[id].rp){  
        tt[pos].num += LL[id].cnt;  
        getlen(pos);  
        return;  
    }  
    if(tt[pos].lp + 1 == tt[pos].rp)  
        return;  
    int mid = tt[pos].getmid();  
    if(LL[id].lp >= mid){  
       update(pos * 2 + 1,id);  
    }  
    else if(LL[id].rp <= mid){  
       update(pos * 2,id);  
    }  
    else{  
       update(pos * 2,id);  
       update(pos * 2 + 1,id);  
    }  
    getlen(pos);  
}  
int a[N];
int b[N];
int main(){  
    int n,m; 
    while (~scanf("%d%d",&n,&m)){
    	for (int i=1;i<=n;i++){
    		scanf("%d",&a[i]);
    		b[a[i]]=i;
    	}
    	for (int i=0;i<m;i++){
    		int x,y;
    		scanf("%d%d",&x,&y);
    		int ix=b[x],iy=b[y];
    		if (ix>iy) swap(ix,iy);
    		LL[i].lp=
    	}
    }
    int a,b,c,d,tot = 0;  
    while(scanf("%d%d%d%d",&a,&b,&c,&d) && (a + b + c + d) != -4){  
        tot = 0;  
        LL[tot].lp = a; LL[tot].rp = c; LL[tot].value = d; LL[tot++].cnt = 1;  
        LL[tot].lp = a; LL[tot].rp = c; LL[tot].value = b; LL[tot++].cnt = -1;  
        int x1,y1,x2,y2;  
        while(1){  
           scanf("%d%d%d%d",&x1,&y1,&x2,&y2);  
           if(x1 + y1 + x2 + y2 == -4)  
               break;  
           LL[tot].lp = x1; LL[tot].rp = x2; LL[tot].value = y2; LL[tot++].cnt = 1;  
           LL[tot].lp = x1; LL[tot].rp = x2; LL[tot].value = y1; LL[tot++].cnt = -1;  
        }  
        built_tree(0,N,1);  
        sort(LL,LL+tot,cmp);  
        update(1,0);  
        long long ans = 0;  
        for(int i = 1; i < tot; ++i){  
           ans += tt[1].len * (LL[i-1].value - LL[i].value);  
           update(1,i);  
        }  
        printf("%lld\n",ans);  
    }  
    return 0;  
}  