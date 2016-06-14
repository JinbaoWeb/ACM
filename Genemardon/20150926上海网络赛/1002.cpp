#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
const int segma_size = 26;
const int maxsize = 10010;
struct TrieNode{
    int val;
    int cnt;
    int next[segma_size];
    TrieNode(){
        memset(next, 0, sizeof(next));
        cnt=0;
    }
};
TrieNode trie[maxsize];
int tcnt;
void init()
{
    tcnt = 1;
}
void insert(char *key)
{
    char *p = key;//初始化时，*表示p是一个指针变量
    int u = 0;
    while(*p)
    {
        if(trie[u].next[*p-'a'] == 0)//使用时p是地址，*p是所指的字符
            trie[u].next[*p-'a'] = tcnt++;
        u = trie[u].next[*p-'a'];
        p++;
    }
    trie[u].cnt = 1;
}

struct node
{
	int x, y;
}pre[maxsize];
char str[maxsize], get[maxsize];
void insert(int x, int y)
{
	if(a[x].ch == 0)
		a[x].ch = str[x];
	if(a[x].next[str[y]-'0'] == 0)
		
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		for(int i = 1;i < n;i++)
			scanf("%d%d", &pre[i].x, &pre[i].y);
		scanf("%s%s", str+1, get);
		for(int i = 1;i < n;i++)
			insert(pre[i].x, pre[i].y);
	}
	return 0;
}