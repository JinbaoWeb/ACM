#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct node
{
    int x, y, next;
}a[220000];
int first[110000],len;
int h[110][110];
int f[11000];
int ru[11000];
int list[11000], head, tail;
void ins ( int x, int y )
{
    len ++;
    a[len].x = x; a[len].y = y;
    a[len].next = first[x]; first[x] = len;
}
int main ()
{
    memset ( h, 63, sizeof(h) );
    int n, m;
    scanf ( "%d%d", &n, &m );
    int i, j;
    for ( i = 1; i <= n; i ++ )
    	for ( j = 1; j <= m; j ++ )
     		cin>>h[i][j];
    memset ( first, 0, sizeof(first) );
	len = 0;
    memset ( ru, 0, sizeof(ru) );
    for ( i = 1; i <= n; i ++ )
    	for ( j = 1; j <= m; j ++ )
     	{
        	if ( h[i][j] > h[i-1][j] )
			{
				ins ( (i-1)*m+j, (i-2)*m+j ); 
				ru[(i-2)*m+j]++;
			}	
        	if ( h[i][j] > h[i+1][j] )
        	{
        		ins ( (i-1)*m+j, (i)*m+j );
				ru[(i)*m+j]++;
        	}
				
        	if ( h[i][j] > h[i][j-1] ) 
        	{
				ins ( (i-1)*m+j, (i-1)*m+j-1 ); 
				ru[(i-1)*m+j-1]++;
        	}
				
        	if ( h[i][j] > h[i][j+1] ) 
			{
				ins ( (i-1)*m+j, (i-1)*m+j+1 ); 
				ru[(i-1)*m+j+1]++;
			}	
     	}
    for ( i = 1; i <= n*m; i ++ ) 
		f[i] = 1;
    head = 1; 
	tail = 1;
    for ( i = 1; i <= n*m; i ++ )
    	if ( ru[i] == 0 ) 
			list[tail++] = i;
    while ( head <= n*m )
    {
        int x = list[head];
        for ( int k = first[x]; k; k = a[k].next )
        {
            int y = a[k].y;
            if ( f[x]+1 > f[y] )
				f[y] = f[x]+1;
            if ( --ru[y] == 0 ) 
				list[tail++] = y;
        }
        head ++;
    }

    int ans = 0;
    for ( i = 1; i <= n*m; i ++ )
    	if ( f[i] > ans ) ans = f[i];
    cout<<ans<<endl;
    return 0;
}

