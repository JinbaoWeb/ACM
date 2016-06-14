#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
bool vis[100000+500];
int t[100000+500];
int countt[100000+500];
char ch[11];
void fileBegin(int fileID){
    sprintf(ch, "%d.in", fileID);
    freopen(ch, "w", stdout);
}

int main(){
    int id = 0;
    int n, m,k;
    srand(2);

    // 小数据

    n = 2, m = 1, k = 1;
    fileBegin(id++);
    printf("%d %d %d\n", n, m,k);
    printf("1 20\n");
    printf("1 1\n");
    fclose(stdout);

    // 小数据
    n = 12, m = 10, k = 2;
    fileBegin(id++);
    printf("%d %d %d\n", n, m,k);
    printf("5 20\n");
    printf("1 20\n");
    printf("3 20\n");
    printf("2 20\n");
    printf("4 20\n");
    printf("7 20\n");
    printf("6 20\n");
    printf("8 20\n");
    printf("10 20\n");
    printf("9 20\n");

    printf("5 4\n");
    printf("10 6\n");
    fclose(stdout);

    n = 103, m = 100, k = 3;
    fileBegin(id++);
    printf("%d %d %d\n", n, m,k);
    printf("5 20\n");
    printf("1 0\n"); 
    printf("3 0\n");
    printf("2 0\n");
    printf("4 0\n");
    printf("7 0\n");
    printf("6 0\n");
    printf("8 0\n");
    printf("10 20\n");
    printf("9 20\n");
    printf("51 20\n");
    printf("11 20\n");
    printf("31 20\n");
    printf("21 20\n");
    printf("41 20\n");
    printf("71 20\n");
    printf("61 20\n");
    printf("81 20\n");
    printf("10 20\n");
    printf("91 20\n");
    printf("92 20\n");
    printf("53 20\n");
    printf("13 20\n");
    printf("33 20\n");
    printf("23 20\n");
    printf("43 20\n");
    printf("73 20\n");
    printf("63 20\n");
    printf("83 20\n");
    printf("93 20\n");
    printf("52 20\n");
    printf("12 20\n");
    printf("32 20\n");
    printf("22 20\n");
    printf("42 20\n");
    printf("72 20\n");
    printf("62 20\n");
    printf("82 20\n");
    printf("94 20\n");
    printf("54 20\n");
    printf("14 20\n");
    printf("34 20\n");
    printf("24 20\n");
    printf("44 20\n");
    printf("74 20\n");
    printf("64 20\n");
    printf("84 20\n");
    printf("95 20\n");
    printf("55 20\n");
    printf("15 20\n");
    printf("35 20\n");
    printf("25 20\n");
    printf("45 20\n");
    printf("75 20\n");
    printf("65 20\n");
    printf("85 20\n");
    printf("96 20\n");
    printf("56 20\n");
    printf("16 20\n");
    printf("36 20\n");
    printf("26 20\n");
    printf("46 20\n");
    printf("76 20\n");
    printf("66 20\n");
    printf("86 20\n");
    printf("97 20\n");
    printf("57 20\n");
    printf("17 20\n");
    printf("37 20\n");
    printf("27 20\n");
    printf("47 20\n");
    printf("77 20\n");
    printf("67 20\n");
    printf("87 20\n");
    printf("98 20\n");
    printf("58 20\n");
    printf("18 20\n");
    printf("38 20\n");
    printf("28 20\n");
    printf("48 20\n");
    printf("78 20\n");
    printf("68 20\n");
    printf("88 20\n");
    printf("99 20\n");
    printf("59 20\n");
    printf("19 20\n");
    printf("39 20\n");
    printf("29 20\n");
    printf("49 20\n");
    printf("79 20\n");
    printf("69 20\n");
    printf("89 20\n");
    printf("90 20\n");
    printf("50 20\n");
    printf("30 20\n");
    printf("20 20\n");
    printf("40 20\n");
    printf("70 20\n");
    printf("60 20\n");
    printf("80 20\n");

    printf("10 8\n");
    printf("50 6\n");
    printf("100 86\n");
    fclose(stdout);
    // 随机
    for(int i = 4; i < 11; i++)
    {
        fileBegin(id++);
        m = rand() % (100000 -1);
        k = rand() % m;
        printf("%d %d %d\n", m+k, m, k);
        for(int j = 0; j < m; j++)
        {
           
            printf("%d %d\n",j+1,rand() % 10000);
        }
        int cnt = 0;
        int ans = 0;
        for(int i = 0 ; i < k; i++)
        {
            t[i] = rand() % m +1;
        }
        sort(t,t+k);
       // memset(count , 0 , sizeof(count));
        for(int ii = 0 ; ii< k;ii ++)
        {
            countt[ii] = (rand() % (t[ii] - cnt + 1)) ;
            cnt+=countt[ii];
            printf("%d %d\n",t[ii],countt[ii]);
        }

        fclose(stdout);
    }

    return 0;
}

