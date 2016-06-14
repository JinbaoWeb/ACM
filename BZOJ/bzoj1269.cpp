#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define Key_value ch[ch[root][1]][0]
const int MAXN = 2*1024*1024+10;
const int INF = (1<<30);
int pre[MAXN],ch[MAXN][2],size[MAXN],rev[MAXN];
char key[MAXN];
int root,tot1;	//root表示根节点，tot1表示
int s[MAXN],tot2;//s表示Splay Tree ，tot2表示树的大小
int n,q;
char text[MAXN];	//插入的字符串
int pos=0;
void NewNode(int &r,int father,char k)	// r表示插入的位置，k表示插入元素的值，father表示要插入的元素的父节点
{
	if(tot2) r = s[tot2--];//取的时候是tot2--,存的时候就是++tot2
	else r = ++tot1;
	pre[r] = father;
	ch[r][0] = ch[r][1] = 0;	//左右子节点为空
	key[r] = k;
	rev[r] = 0;
	size[r] = 1;
}
void Update_Rev(int r)
{
	if(!r)return;
	swap(ch[r][0],ch[r][1]);
	rev[r] ^= 1;
}
void push_up(int r)
{
	int lson = ch[r][0], rson = ch[r][1];
	size[r] = size[lson] + size[rson] + 1;
}
void push_down(int r)
{
	if(rev[r])
	{
		Update_Rev(ch[r][0]);
		Update_Rev(ch[r][1]);
		rev[r] = 0;
	}
}
void Build(int &x,int l,int r,int father)
{
	if(l > r)return;
	int mid = (l+r)/2;
	NewNode(x,father,text[mid]);
	Build(ch[x][0],l,mid-1,x);
	Build(ch[x][1],mid+1,r,x);
	push_up(x);
}
void Init()
{
	pos=0;
	root = tot1 = tot2 = 0;
	ch[root][0] = ch[root][1] = size[root] = pre[root] = rev[root] = 0;
	NewNode(root,0,' ');
	NewNode(ch[root][1],root,' ');
	push_up(ch[root][1]);
	push_up(root);
}
//旋转,0为左旋，1为右旋
void Rotate(int x,int kind)
{
	int y = pre[x];
	push_down(y);
	push_down(x);
	ch[y][!kind] = ch[x][kind];
	pre[ch[x][kind]] = y;
	if(pre[y])
		ch[pre[y]][ch[pre[y]][1]==y] = x;
	pre[x] = pre[y];
	ch[x][kind] = y;
	pre[y] = x;
	push_up(y);
}
//Splay调整，将r结点调整到goal下面
void Splay(int r,int goal)
{
	push_down(r);
	while(pre[r] != goal){
		if(pre[pre[r]] == goal)
		{
			push_down(pre[r]);
			push_down(r);
			Rotate(r,ch[pre[r]][0] == r);
		}
		else
		{
			push_down(pre[pre[r]]);
			push_down(pre[r]);
			push_down(r);
			int y = pre[r];
			int kind = ch[pre[y]][0]==y;
			if(ch[y][kind] == r)
			{
				Rotate(r,!kind);
				Rotate(r,kind);
			}
			else
			{
				Rotate(y,kind);
				Rotate(r,kind);
			}
		}
	}
	push_up(r);
	if(goal == 0) root = r;
}
int Get_kth(int r,int k)
{
	push_down(r);
	int t = size[ch[r][0]] + 1;
	if(t == k)return r;
	if(t > k)return Get_kth(ch[r][0],k);
	else return Get_kth(ch[r][1],k-t);
}
//在第pos个数后面插入tot个数
void Insert(int tot)
{
	Splay(Get_kth(root,pos+1),0);
	Splay(Get_kth(root,pos+2),root);
	Build(Key_value,0,tot-1,ch[root][1]);
	push_up(ch[root][1]);
	push_up(root);
}
//删除子树
void erase(int r)
{
	if(!r)return;
	s[++tot2] = r;
	erase(ch[r][0]);
	erase(ch[r][1]);
}
//从第pos个数开始连续删除tot个数
void Delete(int tot)
{
	Splay(Get_kth(root,pos+1),0);
	Splay(Get_kth(root,pos+tot+1+1),root);
	erase(Key_value);
	pre[Key_value] = 0;
	Key_value = 0;
	push_up(ch[root][1]);
	push_up(root);
}
//将第pos个数开始的连续tot个数进行反转
void Reverse(int tot)
{
	Splay(Get_kth(root,pos+1),0);
	Splay(Get_kth(root,pos+tot+1+1),root);
	Update_Rev(Key_value);
	push_up(ch[root][1]);
	push_up(root);
}
int main()
{
	while(~scanf("%d",&n))
	{
		Init();
		char op[20];
		int x;
		while(n--)
		{
			scanf("%s",op);
			if(op[0]=='I')
			{
				scanf("%d",&x);
				gets(text);
				Insert(x);
			}
			else if(op[0]=='M')
			{
				scanf("%d",&x);
				pos=x;
			}
			else if(op[0]=='D')
			{
				scanf("%d",&x);
				Delete(x);
			}
			else if(op[0]=='R')
			{
				scanf("%d",&x);
				Reverse(x);
			}
			else if(op[0]=='G')
			{
				printf("%c\n",key[Get_kth(root,pos+2)]);
			}
			else if(op[0]=='P')
				pos--;
			else if(op[0]=='N')
				pos++;
		}
	}
	return 0;
}