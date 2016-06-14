#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define N 200010
int a[N], len, p[N];
inline void read(int &x){
    char c=0;
    for(;c<'0'||c>'9';c=getchar());
    for(x=0;c>='0'&&c<='9';c=getchar())x=x*10+(c-'0');
}
void manacher(int* str){
    
    for(int i=len;i>=0;i--){
        str[2*i+2]=str[i];
        str[2*i+1]=0;
    }
    str[0]=-1;
    len=len*2+2;
    int maxp=0,id;
    for(int i=1;i<len-1;i++){
        if(i<maxp) p[i]=min(maxp-i,p[id*2-i]);
        else p[i]=1;
        while(str[i-p[i]]==str[i+p[i]]) p[i]++;
        if(i+p[i]>maxp){
            maxp=i+p[i];
            id=i;
        }
    }
    /*for(int i = 0;i < len;i++)
    	printf("%2d%c", i, " \n"[i==len-1]);
    for(int i = 0;i < len;i++)
    	printf("%2d%c", a[i], " \n"[i==len-1]);
    for(int i = 0;i < len;i++)
    	printf("%2d%c", p[i], " \n"[i==len-1]);*/
}
int solve()
{
	int r = 0;
	for(int i = 1;i < len-1;i += 2)
	{
		if(p[i] == 1)
			continue;
		int start = (len + i)/2;
		if(start % 2 == 0)
			start--;
		start = min(i+p[i]-1, start);
		for(int j = start;j >= i;j-=2)
		{
			if(r >= j-i+1)
				break;
			if(p[j] >= j-i+1)
			{
				r = max(r, j-i+1);
				break;
			}
			//printf("(i, j)%d %d %d %d\n", i, j, r, j-i+1);
		}
	}
	if(r)
		return (r-1)/2*3;
	return r;
}
int main()
{
	int T, o = 0;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &len);
		for(int i = 0;i < len;i++)
			//scanf("%d", &a[i]);
			read(a[i]);
		manacher(a);
		printf("Case #%d: %d\n", ++o, solve());
	}
	return 0;
}