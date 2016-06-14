#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <cstdlib>
using namespace std;
int witness(int a, int n)
{
    int x, d=1, i = ceil(log(n - 1.0) / log(2.0)) - 1;
    for ( ; i >= 0; i--) {
        x = d; d = (d * d) % n;
        if (d==1 && x!=1 && x!=n-1) return 1;
        if (((n-1) & (1<<i)) > 0) d = (d * a) % n;
    }
    return (d == 1 ? 0 : 1);
}
int miller(int n, int s = 50)
{
    if (n == 2) return 1;
    if ((n % 2) == 0) return 0;
    int j, a;
    for (j = 0; j < s; j++) {
        a = rand() * (n-2) / RAND_MAX + 1;
        // rand()只能随机产生[0, RAND_MAX)内的整数
        // 而且这个RAND_MAX只有32768直接%n的话永远也产生不了
        // [RAND-MAX, n)之间的数
        if (witness(a, n)) return 0;
    }
    return 1;
}

int main(){
    int n;
    while (scanf("%d",&n)!=EOF){
        int i,flag=0;
        for (i=1;i*i<=n;i++){
            if (n%i!=0)
                continue;
            if (miller(n/i)==1){
                flag=1;
                break;
            }
            else{
                n/=i;
                i=0;
            }
        }
        if (flag==0)
        	printf("0\n");
        else
        	printf("%d\n",i);
        
    }
    return 0;
}