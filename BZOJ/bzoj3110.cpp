#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,n) for(int i = a; i < n; i++)
#define repe(i,a,n) for(int i = a; i <= n; i++)
#define per(i,n,a) for(int i = n; i >= a; i--)
#define clc(a,b) memset(a,b,sizeof(a))
const int INF = 0x3f3f3f3f, MAXN = 50000+10;
struct NODE{
	NODE *ch[2];
	int r, v, sum, cnt;
}node[MAXN*20];
int a[MAXN], mi, mx, tol;
NODE *rt[MAXN<<1];

int cmp(const NODE *a, int x){
	if(x == a->v) return -1;
	return x<a->v?0:1;
}
void push_up(NODE *u){
	u->sum = u->cnt;
	if(u->ch[0]) u->sum += u->ch[0]->sum;
	if(u->ch[1]) u->sum += u->ch[1]->sum;
}
NODE *newnode(int a){
	node[tol].v = a,node[tol].ch[0] = node[tol].ch[1] = NULL, node[tol].r = rand();
	node[tol].sum = node[tol].cnt = 1;
	return &node[tol++];
}
void clear(NODE* &u)//清空树
{
	u = NULL;
}
void rotate(NODE* &u, int d)//旋转，d = 0左旋,d = 1右旋
{
	NODE *k = u->ch[d^1];
	u->ch[d^1] = k->ch[d], k->ch[d] = u;
	push_up(u), push_up(k);  //更新sum,先更新u
	u = k;
}
void insert(NODE* &u, int v)//插入键值v(不需要保证v是否存在)
{
	if(!u) u = newnode(v);
	else
	{
		int d = cmp(u,v);//不要使用cmp(),可能已经存在相同的v
		if(-1 == d)//已经存在该点
		{
			u->cnt++;
			u->sum++;
			return;
		}
		insert(u->ch[d], v);
		if(u->r < u->ch[d]->r) //如果儿子的r比当前大则需要旋转
			rotate(u,d^1);//左儿子则右旋，右儿子左旋
	}
	push_up(u);//更新sum
}
void del(NODE* &u, int v)//删除键值v
{
	int d = cmp(u,v);
	if(~d)//没找到继续往下找
		del(u->ch[d],v);
	else
	{
		if(u->cnt > 1)
		{
			u->cnt--;
			u->sum--;
			return;
		}
		NODE *o = u;
		if(u->ch[0] && u->ch[1])//左右儿子都存在
		{
			int d2 = u->ch[0]->r > u->ch[1]->r?1:0;//优先级大的儿子旋转为根
			rotate(u,d2);
			del(u->ch[d2],v);
		}
		else
		{
			if(!u->ch[0]) u = u->ch[1];//只有右儿子
			else u = u->ch[0];//只有左儿子
			//delete o;
			//u = NULL;
		}
	}
	if(u) push_up(u);
}
int upper(NODE *u, int v)//v在树中排第几,即有几个<=v
{
	if(!u) return 0;
	if(v == u->v) return u->cnt+(u->ch[0]?u->ch[0]->sum:0);
	if(v < u->v) return upper(u->ch[0], v);
	return upper(u->ch[1],v)+(u->ch[0]?u->ch[0]->sum:0)+u->cnt;
}
void pt(NODE *u)
{
	if(NULL == u) return;
	pt(u->ch[0]);
	rep(i,0,u->cnt)
		printf("%d\n", u->v);
	pt(u->ch[1]);
}

inline int id(int x, int y){return x+y|x!=y;}
void bulid(int x, int y)
{
	int u = id(x,y);
	clear(rt[u]);
	repe(i,x,y) insert(rt[u],a[i]);
	if(x == y) return;
	int m = (x+y)>>1;
	bulid(x,m);
	bulid(m+1,y);
}
int tmp;
void update(int x, int y, int p, int v)
{
	if(x == y)
	{
		int u = id(x,y);
		tmp = rt[u]->v;
		rt[u]->v = v;
		return;
	}
	int m = (x+y)>>1;
	if(p <= m) update(x,m,p,v);
	else update(m+1,y,p,v);
	int u = id(x,y);
	del(rt[u],tmp);
	insert(rt[u],v);
}
int query(int x, int y, int ql, int qr, int v)
{
	if(ql <= x && y <= qr)
	{
		int u = id(x,y);
		return upper(rt[u],v);
	}
	int m = (x+y)>>1, ans = 0;
	if(ql <= m) ans += query(x,m,ql,qr,v);
	if(qr > m) ans += query(m+1,y,ql,qr,v);
	return ans;
}
int n;
int sloved(int x, int y, int k)
{
	int l = mi, r = mx, ans;
	while(l <= r)
	{
		int m = (l+r)>>1;
		if(query(0,n-1,x,y,m) >= k)
			ans = m, r = m-1;
		else l = m+1;
	}
	return ans;
}
int main()
{
#ifdef SHY
	freopen("d:\\1.txt", "r", stdin);
#endif
	int t;
	scanf("%d%*c", &t);
	while(t--)
	{
		int q;
		scanf("%d %d%*c", &n, &q);
		mi = INF, mx = -1;
		tol = 0;
		rep(i,0,n)
		{
			scanf("%d%*c", &a[i]);
			mi = min(mi,a[i]);
			mx = max(mx,a[i]);
		}
		bulid(0,n-1);
		while(q--)
		{
			char op[10];
			scanf("%s",op);
			if('C' == op[0])
			{
				int p,v;
				scanf("%d %d", &p,&v);
				p--;
				update(0,n-1,p,v);
				mi = min(mi,v);
				mx = max(mx,v);
			}
			else
			{
				int x,y,k;
				scanf("%d %d %d",&x, &y, &k);
				x--,y--;
				printf("%d\n", sloved(x,y,k));
			}
		}
	}
	return 0;
}