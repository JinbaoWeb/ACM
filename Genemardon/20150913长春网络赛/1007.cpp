#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node
{
	int l,r,big;
}tree[10000];
int water[10000];
void build(int p,int L,int R)
{
	tree[p].l=L;
	tree[p].r=R;
	if (L==R) tree[p].big=water[L];
	else
	{
		build(p*2,L,(L+R)/2);
		build(p*2+1,(L+R)/2+1,R);
		tree[p].big=max(tree[p*2].big,tree[p*2+1].big);
	}
}
int search(int p,int L,int R)
{
	if (tree[p].l==L && tree[p].r==R)
		return tree[p].big;
	if (tree[p*2].r>=R)
		return search(p*2,L,R);
	else if (tree[p*2+1].l<=L)
		return search(p*2+1,L,R);
	else 
		return max(search(p*2,L,tree[p*2].r),search(p*2+1,tree[p*2+1].l,R));
}
int main(int argc, char const *argv[])
{
	int t,n,q;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&water[i]);
		build(1,1,n);
		scanf("%d",&q);
		for (int i=0;i<q;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			printf("%d\n",search(1,u,v) );
		}
	}
	return 0;
}