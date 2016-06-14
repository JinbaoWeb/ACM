#include <stdio.h>
#include <string.h>
int maz[105][105];
int vis[105][105];
struct data
{
    int x,y;
};
int n,m;
data flshr(data now)
{
    while(vis[now.x][now.y+1]!=1&&now.y<m)
    {
        printf("R");
        vis[now.x][now.y+1]=1;
        now.y++;
        //printf("%d %d\n",now.x,now.y);
    }
    return now;
}
data flshl(data now)
{
    while(vis[now.x][now.y-1]!=1&&now.y>1)
    {
        printf("L");
        vis[now.x][now.y-1]=1;
        now.y--;
    }
    return now;
}
data flshu(data now)
{
    while(vis[now.x-1][now.y]!=1&&now.x>1)
    {
        printf("U");
        vis[now.x-1][now.y]=1;
        now.x--;
    }
    return now;
}
data flshd(data now)
{
    while(vis[now.x+1][now.y]!=1&&now.x<n)
    {
        printf("D");
        vis[now.x+1][now.y]=1;
        now.x++;
    }
    return now;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(maz,0,sizeof(maz));
        memset(vis,0,sizeof(vis));
        int minn=100000000;
        int ans=0;
        data target;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&maz[i][j]);
                ans+=maz[i][j];
                if((i+j)%2==1)
                {
                    if(minn>maz[i][j])
                    {
                        minn=maz[i][j];
                        target.x=i;
                        target.y=j;
                    }
                }
            }
        }
        for(int i=0;i<=n+2;i++)
        {
            vis[i][0]=1;
            vis[i][m+1]=1;
        }
        for(int j=0;j<=m+2;j++)
        {
            vis[0][j]=1;
            vis[n+1][j]=1;
        }
        /*for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=m+1;j++)
            {
                printf("%d ",vis[i][j]);
            }
            printf("\n");
        }*/
        if(n%2==1)
        {
            printf("%d\n",ans);
            data now;
            now.x=1;
            now.y=1;
            vis[now.x][now.y]=1;
            for(int i=1;i<=n-2;i+=2)
            {
                now=flshr(now);
                now.x++;
                vis[now.x][now.y]=1;
                printf("D");
                now=flshl(now);
                now.x++;
                vis[now.x][now.y]=1;
                printf("D");
            }
            now=flshr(now);
            printf("\n");
        }
        else if(m%2==1)
        {
            printf("%d\n",ans);
            data now;
            now.x=1;
            now.y=1;
            vis[now.x][now.y]=1;
            for(int i=1;i<=m-2;i+=2)
            {
                now=flshd(now);
                now.y++;
                printf("R");
                vis[now.x][now.y]=1;
                now=flshu(now);
                now.y++;
                vis[now.x][now.y]=1;
                printf("R");
            }
            now=flshd(now);
            printf("\n");
        }
        else
        {
            if(target.x%2==1)
            {
                printf("%d\n",ans-minn);
                data now;
                now.x=1;
                now.y=1;
                vis[now.x][now.y]=1;
                vis[target.x][target.y]=1;
                for(int i=1;i<=target.x-2;i+=2)
                {
                    now=flshr(now);
                    now.x++;
                    vis[now.x][now.y]=1;
                    printf("D");
                    now=flshl(now);
                    now.x++;
                    vis[now.x][now.y]=1;
                    printf("D");
                }
                for(int i=1;i<=target.y-1;i+=2)
                {
                    now=flshd(now);
                    now.y++;
                    vis[now.x][now.y]=1;
                    printf("R");
                    now=flshu(now);
                    now.y++;
                    vis[now.x][now.y]=1;
                    printf("R");
                }
                vis[now.x][now.y]=1;
                //printf("%d %d %d\n",now.x,now.y,vis[now.x][now.y]);
                while(true)
                {
                    if(vis[now.x-1][now.y]==0)
                    {
                        printf("U");
                        now.x--;
                        vis[now.x][now.y]=1;
                        now=flshr(now);
                        if(vis[now.x+1][now.y]==0)
                        {
                            now.x++;
                            vis[now.x][now.y]=1;
                            printf("D");
                            now=flshl(now);
                        }
                        if(vis[now.x+1][now.y]==0)
                        {
                            now.x++;
                            vis[now.x][now.y]=1;
                            printf("D");
                        }
                    }
                    if(vis[now.x][now.y-1]==0)
                    {
                        printf("L");
                        now.y--;
                        vis[now.x][now.y]=1;
                        now=flshd(now);
                        if(vis[now.x][now.y+1]==0)
                        {
                            now.y++;
                            vis[now.x][now.y]=1;
                            printf("R");
                            now=flshu(now);
                        }
                        if(vis[now.x][now.y+1]==0)
                        {
                            now.y++;
                            vis[now.x][now.y]=1;
                            printf("R");
                        }
                    }
                    //printf("%d %d %d\n",now.x,now.y,vis[now.x][now.y]);
                    //int temp;
                    //scanf("%d",&temp);
                    if(now.x==n&&now.y==m)
                    {
                        printf("\n");
                        break;
                    }
                }
            }
        }
    }
    return 0;
}