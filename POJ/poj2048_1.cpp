#include <iostream>
using namespace std;
#include <string.h>
int flag[30][30];
int mov[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int n,k;
int p,q;
char path[30][2];
int tag;
int dfs(int x,int y,int step)
{ 
	int n_x,n_y,i;
    if(step==p*q)
    {
        tag=1;
        return 1;
    }

    for(i=0;i<8;i++)
    {
        n_x=x+mov[i][0];
        n_y=y+mov[i][1];
        if(n_x>=1 && n_x<=q && n_y>=1 && n_y<=p && !flag[n_x][n_y])
        {
            path[step][0]=n_x+'A'-1;
            path[step][1]=n_y+'0';
            flag[n_x][n_y]=1;
            dfs(n_x,n_y,step+1);
            if(tag)
             return 1;
            flag[n_x][n_y]=0;
        }
    }
    return 0;
}

int main()
{
    
    int i;
    cin>>n; 
    for(k=1;k<=n;k++)
    {
    	cin>>p>>q;
        memset(path,0,sizeof(path));
        memset(flag,0,sizeof(flag));

        tag=0;
        flag[1][1]=1;
        path[0][0]='A';
        path[0][1]='1';
		cout<<"Scenario #"<<k<<":"<<endl;
        if(dfs(1,1,1))
        {
            for(i=0;i<p*q;i++)
            	cout<<path[i][0]<<path[i][1];
        }
        else
        	cout<<"impossible";
        cout<<endl<<endl;
    }
    return 0;
}
