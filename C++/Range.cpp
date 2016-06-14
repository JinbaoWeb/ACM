#include <iostream>
#include <stdio.h>
using namespace std;
int a[500000+5];
void swap(int &a,int &b){
	int temp=b;
	b=a;
	a=temp;
}
void ksort(int l, int h){
	if (h < l + 2) return;
	int e = h, p = l;
	while (l < h) {
		while (++l < e && a[l] <= a[p]);
		while (--h > p && a[h] >= a[p]);
		if (l < h) swap(a[l], a[h]);
	}
	swap(a[h], a[p]);
	ksort(p, h); ksort(l, e);
}
 
int find_left(int l,int r, int v) { //���ֲ�����߽� 
    if (l == r) {
       return l;
    }
    int mid = (l+r)/2;
    if (a[mid] < v) {
       return find_left(mid+1,r,v);
    }
    else {
         return find_left(l,mid,v);
    }
}
 
int find_right(int l,int r,int v) { //���ֲ����ұ߽� 
    if (l == r) {
       return l;
    }
    int mid = (l+r+1)/2;
    if (a[mid] > v) {
       return find_right(l,mid-1,v);
    }
    else {
         return find_right(mid,r,v);
    }
}
 
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    ksort(0,n-1); //������ 
     
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (l > r) {
           swap(l,r); //ȷ��������С�������� 
        }
        if (l > a[n-1] || r < a[0]) { //ȷ��һ�����ҵ��� 
           printf("0\n");
        }
        else {
             printf("%d\n",find_right(0,n-1,r)-find_left(0,n-1,l)+1); //���ֲ����ҵ��������߽߱� 
        }
    }
    return 0;
}
