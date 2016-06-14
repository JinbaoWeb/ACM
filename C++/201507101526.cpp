#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L(x) (x << 1)
#define R(x) (x << 1 | 1)
#define N 10010

struct node
{
    int l, r;
    int c;
}node[N*14];

struct po
{
    int p;
    int num;
}po[N*2];

int flag[N*4], num;

int cmp(const void *a, const void *b)
{
    struct po * c = (struct po *)a;
    struct po * d = (struct po *)b;
    return c->p - d->p;
}

void creat(int t, int l, int r)
{
    node[t].l = l;
    node[t].r = r;
    node[t].c = 0;
    if(l == r)    return;
    int mid = (node[t].l + node[t].r) >> 1;
    creat(L(t),l, mid);
    creat(R(t), mid + 1, r);
}

void updata(int t, int l, int r, int c)
{
    if(node[t].l >= l && node[t].r <= r)
    {
        node[t].c = c;
        return;
    }
    if(node[t].c > 0)
    {
        node[L(t)].c = node[t].c;
        node[R(t)].c = node[t].c;
        node[t].c = 0;
    }
    int mid = (node[t].l + node[t].r) >> 1;
    if(l > mid)
        updata(R(t), l, r, c);
    else if(r <= mid)
        updata(L(t), l, r, c);
    else
    {
        updata(L(t), l, mid, c);
        updata(R(t), mid + 1, r, c);
    }
}

void count(int t)
{
    if(node[t].c > 0)
    {
        if(flag[node[t].c] == 0)
        {
            num++;
            flag[node[t].c]++;
        }
        return;
    }
    if(node[t].l == node[t].r)
        return;
    count(L(t));
    count(R(t));
}

int main()
{
    int f[N][3];
    int t, n, i;
    //freopen("data.in", "r", stdin);
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            memset(flag, 0, sizeof(flag));
            memset(f, 0, sizeof(f));
            scanf("%d", &n);
            for(i = 1; i <= n; i++)
            {
                scanf("%d%d", &f[i][0], &f[i][1]);
                po[2*i-1].p = f[i][0];
                po[2*i-1].num = i;
                po[2*i].p = f[i][1];
                po[2*i].num = -1*i;
            }
            qsort(po+1, 2*n, sizeof(po[1]), cmp);
            int t = 1, tmp = po[1].p;
            for(i = 1; i <= 2*n; i++)
            {
                if(tmp != po[i].p)
                {
                    tmp = po[i].p;
                    t++;
                }
                if(po[i].num > 0)
                    f[po[i].num][0] = t;
                else
                    f[-1*po[i].num][1] = t;
            }
            for (int ii=1;ii<=n;ii++){
                printf("%d %d\n",f[ii][0],f[ii][1]);
            }
            creat(1, 1, t);
            for(i = 1; i <= n; i++)
            {
                //printf("%d %d\n", f[i][0], f[i][1]);
                updata(1, f[i][0], f[i][1], i);
            }
            num = 0;
            count(1);
            printf("%d\n",num);
        }
    }
    return 0;
}
/*
1
5
3 10000
9 1000000
5 100000
1 1000
7 1000000

*/