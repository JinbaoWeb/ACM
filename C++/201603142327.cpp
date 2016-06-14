#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXM=520;
int n,k;
int s[MAXM];//状态数
int c[MAXM];//1的个数
long long f[13][MAXM][103];
int ck;
void dfs(int x,int val,int cnt)//DFS寻找每行的状态数
{
    if(x==n)
    {
        s[++ck]=val;
        cout<<ck<<" "<<val<<" "<<cnt<<endl;
        c[ck]=cnt;
        return;
    }
    dfs(x+1,val<<1,cnt);
    if(!(val&1))
    dfs(x+1,val<<1|1,cnt+1);
}
bool cont(int s1,int s2)//判断与题意是否矛盾
{
    if(s1&s2) return false;//和正上方判断
    if(s1&(s2<<1))return false;//和右上方判断
    if(s1&(s2>>1))return false;//和左上方判断
    return true;
}
void dp()
{
        //初始化状态
        memset(f,0,sizeof(f));
        f[0][1][0]=1;
        //dp
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=ck;j++)
            {
                for(int g=1;g<=ck;g++)
                {
                    for(int p=0;p<=k;p++)
                    {
                        if((p-c[j]>=0)&&cont(s[j],s[g]))
                        f[i][j][p]+=f[i-1][g][p-c[j]];
                    }
                }
            }
        }
}

int main()
{
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        ck=0;
        dfs(0,0,0);
        printf("-----------\n");
        dp();
        long long ans=0;
        
        for(int i=1;i<=ck;++i)
        {
            ans+=f[n][i][k];
            cout<<f[n][i][k]<<" ";
        }

        printf("%I64d\n",ans);

    }


    return 0;
}