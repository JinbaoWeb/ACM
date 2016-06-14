#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;
struct node
{
    stack<int>box[8];
    int qid;
    long long nid;
    node  () {}
    node (int qid, long long nid) : qid(qid), nid(nid) {}
};
int ans[8][2000000];
long long base[100];
void init()
{
    base[0] = 1;
    base[1] = 1;
    for (int i = 2; i <= 50; i++) base[i] = base[i - 1] * 2;
}
int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int cantor(int s[], int x)
{
    int i, j, temp, num;
    num = 0;
    for (i = 1; i < x; i++)
    {
        temp = 0;
        for (int j = i + 1; j <= x; j++)
        {
            if (s[j] < s[i]) temp++;
        }
        num += fac[x - i] * temp;
    }
    return (num + 1);
}
void bfs(int x)
{

    queue<node>q;
    map<long long, int>M;
    M.clear();
    printf("%d\n", M[10] );
    int cnt = 0;
    int head = 0;
    for (int i = 1; i <= x; i++)
        head = head + base[(i - 1) * x + i];
    node nn = node(cnt, head);
    for (int i = 1; i <= x; i++) nn.box[i].push(i);
    q.push(nn);
    M[head] = 1;
    while (!q.empty())
    {

        node tmp = q.front();
        //printf("%d %lld\n",tmp.qid,tmp.nid );
        int flag = 1;
        int list[10];
        for (int i = 1; i <= x; i++)
        {
            if (!tmp.box[i].empty()) list[i] = tmp.box[i].top();
            if (tmp.box[i].size() != 1)
            {
                flag = 0;
                break;
            }
        }
        if (flag) ans[x][cantor(list, x)] = tmp.qid;
        q.pop();
        //printf("111\n");
        for (int i = 1; i <= x; i++)
            if (!(tmp.box[i].empty()))
            {
            	//printf("222\n");
                if (i > 1)
                {
                	//printf("333\n");
                    if (tmp.box[i - 1].empty() || tmp.box[i - 1].top() > tmp.box[i].top())
                    {
                        long long id = tmp.nid - base[(i - 1) * x + tmp.box[i].top()] + base[(i - 2) * x + tmp.box[i].top()];
                        if (M[id] == 0)
                        {
                            stack<int>save[8];
                            M[id] = tmp.qid + 1;
                            node nnn = node(tmp.qid + 1, id);
                            for (int j = 1; j <= x; j++)
                            {
                                while (!tmp.box[j].empty())
                                {
                                    save[j].push(tmp.box[j].top());
                                    tmp.box[j].pop();
                                }
                                while (!save[j].empty())
                                {
                                    tmp.box[j].push(save[j].top());
                                    nnn.box[j].push(save[j].top());
                                    save[j].pop();
                                }
                            }
                            nnn.box[i - 1].push(nnn.box[i].top());
                            nnn.box[i].pop();
                            q.push(nnn);
                        }
                    }
                }
                if (i < x)
                {
                	//printf("444\n");
                    if (tmp.box[i + 1].empty() || tmp.box[i + 1].top() > tmp.box[i].top())
                    {
                        long long id = tmp.nid - base[(i - 1) * x + tmp.box[i].top()] + base[(i) * x + tmp.box[i].top()];
                        if (M[id] == 0)
                        {
                            stack<int>save[8];
                            M[id] = tmp.qid + 1;
                            node nnn = node(tmp.qid + 1, id);
                            for (int j = 1; j <= x; j++)
                            {
                                while (!tmp.box[j].empty())
                                {
                                    save[j].push(tmp.box[j].top());
                                    tmp.box[j].pop();
                                }
                                while (!save[j].empty())
                                {
                                    tmp.box[j].push(save[j].top());
                                    nnn.box[j].push(save[j].top());
                                    save[j].pop();
                                }
                            }
                            nnn.box[i + 1].push(nnn.box[i].top());
                            nnn.box[i].pop();
                            q.push(nnn);
                        }
                    }
                }
            }
    }
}
int main(int argc, char const *argv[])
{
    init();
    memset(ans,-1,sizeof(ans));
    for (int i=1;i<=7;i++) bfs(i);
    printf("1111\n");
     int list[10]={0,3,2,1};
     printf("%d\n",ans[3][cantor(list,3)] );
    return 0;
}