#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
#define N 100005
#define WN 100005
#define AL 26
string A[N];
char temp[10005];
struct Trie
{
    int next[WN][AL], fail[WN], end[WN];
    int root, L;
    int newnode()
    {
        for(int i = 0;i < AL;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now]++;
    }
    void build()
    {
        queue<int> Q;
        fail[root] = root;
        for(int i = 0;i < AL;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < AL;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int query(string buf)
    {
        //int len = strlen(buf);
        int len = buf.length();
        int now = root;
        __int64 res = 0;
        for(int i = 0;i < len;i++)
        {
            now = next[now][buf[i]-'a'];
            int temp = now;
            while( temp != root )
            {
                res += (__int64)end[temp];
                //end[temp] = 0;
                temp = fail[temp];
            }
        }
        printf("%I64d\n", res);
        //return res;
    }
}ac;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 0;i < n;i++)
		{
			scanf("%s", temp);
			A[i] = temp;
		}
		ac.init();
		for(int i = 0;i < m;i++)
		{
			scanf("%s", temp);
			ac.insert(temp);
		}
		ac.build();
		for(int i = 0;i < n;i++)
		{
			//const char *k = A[i].c_str();
			ac.query(A[i]);
		}
	}
	return 0;
}