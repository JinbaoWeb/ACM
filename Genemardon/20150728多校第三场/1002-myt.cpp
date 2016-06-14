#include <stdio.h>
#include <string.h>
#include <algorithm>
int f[1000010],pri[1000010];
int cnt[8];
int pos[8][1000010];
inline void read(int &x){
    char c=0;
    for(;c<'0'||c>'9';c=getchar());
    for(x=0;c>='0'&&c<='9';c=getchar())x=x*10+(c-'0');
}
int main(int argc, char const *argv[])
{
    memset(pri,0,sizeof(pri));
    memset(f,0,sizeof(f));
    memset(pos,0,sizeof(pos));
    for (int i=2;i<=1000000;i++) if (pri[i]==0)
        for (int j=i;j<=1000000;j=j+i)
        {
            pri[j]=1;
            f[j]++;
        }
    int LL;
    for (int i=1;i<=7;i++)
    {
        LL=0;
        for (int j=2;j<=1000000;j++)
        { 	
        	if (f[j]==i)
            LL++;
            pos[i][j]=LL;
            
        }
    }
    //printf("%d %d\n",pos[4][210],pos[4][330] );
    //for (int i=210;i<=420;i++) if (f[i]==4) printf("%d\n",i );
    //for (int i=1;i<=7;i++) printf("%d  ",len[i] );printf("\n");
    int t,l,r;
    read(t);
    int ans=0;
    while (t--)
    {
        read(l),read(r);
        for (int i=1;i<=7;i++)
        {
            cnt[i]=pos[i][r]-pos[i][l];
            if (f[l]==i) cnt[i]++;
        }
        if (cnt[7]>=2)
            printf("7\n");
        else
            if (cnt[6]>=2)
                printf("6\n");
        else
            if (cnt[5]>=2)
                printf("5\n");
        else
            if (cnt[4]>=2)
                printf("4\n");
        else 
            if (cnt[3]+cnt[6]>=2)
                printf("3\n");
        else
            if (cnt[2]+cnt[4]+cnt[6]>=2)
                printf("2\n");
        else
            printf("1\n");
    }
    return 0;
}