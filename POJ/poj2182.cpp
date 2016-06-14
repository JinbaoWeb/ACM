#include <iostream>
#include <stdio.h>
using namespace std;
const int Max = 8005;
 
struct Node{
    int l, r, len;      //  用len存储这个区间的数字个数。
}node[3*Max];
int pre[Max], ans[Max];
 
void BuildTree(int left, int right, int u){     //  建树。
    node[u].l = left;
    node[u].r = right;
    node[u].len = right - left + 1;
    if(left == right) return;
    BuildTree(left, (left+right)>>1, u<<1);
    BuildTree(((left+right)>>1)+1, right, (u<<1)+1);
}
 
int query(int u, int num){       //  查询+维护，关键一点：所求值为当前区间的左起第num个元素。
    node[u].len --;              //  对访问到的区间维护len。
    if(node[u].l == node[u].r)
        return node[u].l;
 
     //  情况1：左子区间的数字个数不够，则查询右子区间的左起第num - node[u<<1].len个元素。
    if(node[u<<1].len < num)
        return query((u<<1)+1, num - node[u<<1].len);
 
    //  情况2：左子区间的数字个数足够，则依旧查询左子区间的左起第num个元素。
    if(node[u<<1].len >= num)
        return query(u<<1, num);
}
void Debug(int n){
    for (int i=0;i<4*n;i++){
        cout<<node[i].len<<" ";
    }
    cout<<endl;
}
int main(){
    int n, i;
    scanf("%d", &n);
    pre[1] = 0;
    for(i = 2; i <= n; i ++)
        scanf("%d", &pre[i]);
    BuildTree(1, n, 1);
    for(i = n; i >= 1; i --)     //  从后往前推断出每次最后一个数字。
    {
        ans[i] = query(1, pre[i]+1);
       // Debug(n);
    }
    for(i = 1; i <= n; i ++)
        printf("%d\n", ans[i]);
    return 0;
}