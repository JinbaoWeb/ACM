#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;


const int MAXN=50;
#define inf 0xffffffff


int a[MAXN][MAXN];//增广矩阵
int x[MAXN];//解集
bool free_x[MAXN];//标记是否是不确定的变元
inline int gcd(int a,int b){
    int t;
    while(b!=0){
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}
inline int lcm(int a,int b){
    return a/gcd(a,b)*b;//先除后乘,防溢出
}
/* 高斯消元法解方程组(Gauss-Jordan elimination).(-2表示有浮点数解，但无整数解，
*  -1表示无解，0表示唯一解，大于0表示无穷解，并返回自由变元的个数)
*  有equ个方程，var个变元。增广矩阵行数为equ,分别为0到equ-1,列数为var+1,分别为0到var.
*/
int i,j,k;
int max_r;
int col;
int ta,tb;
int LCM;
int temp;
int free_x_num;
int free_index;
int Gauss(int equ,int var){
    for(int i=0;i<=var;i++){
        x[i]=0;
        free_x[i]=true;
    }    
    /*	  equ:方程的个数
    *	  var:变元的个数
    *	  col:当前处理的列 
	*	    k:当前处理的行
	*	max_r：第col列元素绝对值最大的行
	*	枚举从0-equ的行，找到该col列元素绝对值最大的那行与第k行交换
	*	如果col列第k行以下的元素全部为0，那么处理第k行col+1列
	*	最后转换为阶梯矩阵
    */
    col=0;
    for(k = 0;k < equ && col < var;k++,col++){
        max_r=k;
        for(i=k+1;i<equ;i++){
            if(abs(a[i][col])>abs(a[max_r][col])) max_r=i;
        }
        if(max_r!=k){
            for(j=k;j<var+1;j++) swap(a[k][j],a[max_r][j]);
        }
        if(a[k][col]==0){
            k--;
            continue;
        }
        for(i=k+1;i<equ;i++){
            if(a[i][col]!=0){
                LCM = lcm(abs(a[i][col]),abs(a[k][col]));
                ta = LCM/abs(a[i][col]);
                tb = LCM/abs(a[k][col]);
                if(a[i][col]*a[k][col]<0)	tb=-tb;//异号的情况是相加
                for(j=col;j<var+1;j++){
                    a[i][j] = a[i][j]*ta-a[k][j]*tb;
                }
            }
        }
    }
    /*	1.无解：当增广矩阵中存在(0, 0, ..., a)的形式且a！=0时，说明无解
    *	2.唯一解：增广矩阵为严格的上三角阵，说明有唯一解
    *	3.无穷解：当增广矩阵中出现(0, 0, ..., 0)这样的行，即说明没有形成严格的上三角阵，且出现的行数是自由变元的个数
    */
    for (i = k; i < equ; i++){
        if (a[i][col] != 0) return -1;
    }
    if (k < var){
        for (i = k - 1; i >= 0; i--){
            free_x_num = 0;
            for (j = 0; j < var; j++){
                if (a[i][j] != 0 && free_x[j]) free_x_num++, free_index = j;
            }
            if (free_x_num > 1) continue;
            temp = a[i][var];
            for (j = 0; j < var; j++){
                if (a[i][j] != 0 && j != free_index) temp -= a[i][j] * x[j];
            }
            x[free_index] = temp / a[i][free_index];
            free_x[free_index] = 0;
        }
        return var - k;
    }
    for (i = var - 1; i >= 0; i--){
        temp = a[i][var];
        for (j = i + 1; j < var; j++){
            if (a[i][j] != 0) temp -= a[i][j] * x[j];
        }
        if (temp % a[i][i] != 0) return -2; // 说明有浮点数解，但无整数解.
        x[i] = temp / a[i][i];
    }
    return 0;
}
int solve(int t){	//枚举自由变元
	if (t==-1)
		cout<<"无解"<<endl;
	else if (t==-2)
		cout<<"有浮点数解，但无整数解"<<endl;
	else if (t==0){
		int ans=0;
		for (int i=0;i<equ*equ;i++){
			ans+=x[i];
		}
		return ans;
	}
	else{
		int ans = inf;
        int tot = (1<<t);
        for(int i = 0;i < tot;i++){
            int cnt = 0;
            for(int j = 0;j < t;j++){
                if(i&(1<<j)){
                    x[free_x[j]] = 1;
                    cnt++;
                }
                else x[free_x[j]] = 0;
            }
            for(int j = var-t-1;j >= 0;j--){
                int idx;
                for(idx = j;idx < var;idx++)
                    if(a[j][idx])
                        break;
                x[idx] = a[j][var];
                for(int l = idx+1;l < var;l++)
                    if(a[j][l]){
                        x[idx] ^= x[l];
                    }
                cnt += x[idx];
            }
            ans = min(ans,cnt);
        }
        return ans;
	}

}


int main(){

	return 0;
}