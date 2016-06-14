#include <bits/stdc++.h>
using namespace std;
int vis[10];
int p[130];
char s1[10], s2[10],s3[10];
int l1,l2,l3;
char s[30];
int x,y,z,ans;
void DFS(int l){
    if(s[l]==0)
    {
        if(l1>1&&p[s1[0]]==0 || l2>1&&p[s2[0]]==0 || l3>1&&p[s3[0]]==0)
        	return;
        int len=0;
        x=y=z=0;
        while(s1[len])
        	x = x*10+p[s1[len++]];
        len=0;
        while(s2[len])
        	y = y*10+p[s2[len++]];
        len=0;
        while(s3[len])
        	z = z*10+p[s3[len++]];
        if(x+y==z)
        	ans++;
        if(x-y==z)
        	ans++;
        if(x*y==z)
        	ans++;
        if(y&&z*y==x)
        	ans++;
        return;
    }
    if(p[s[l]]==-1)
    {
        for(int i = 0; i <= 9; i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                p[s[l]]=i;
                DFS(l+1);
                vis[i] = 0;
                p[s[l]]=-1;
            }
        }
    }
    else
    {
        DFS(l+1);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(p,-1,sizeof(p));
        memset(vis,0,sizeof(vis));
        cin>>s1>>s2>>s3;
        l1=strlen(s1),l2=strlen(s2),l3=strlen(s3);
        strcpy(s,s1);
        strcpy(s+strlen(s),s2);
        strcpy(s+strlen(s),s3);
        ans = 0;
        DFS(0);
        cout<<ans<<endl;
    }
    return 0;
}