/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-02 23:02
 * Filename :        301B.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
using namespace std;
#define min(a,b) a<b?a:b
int main(){
	int n,p,k,x,y;
	while (~scanf("%d%d%d%d%d",&n,&k,&p,&x,&y)){
		int count=0,sum=0;	//count表示小于y的个数，sum表示这个k个数的和
		for (int i=0;i<k;i++){
			int mark;
			scanf("%d",&mark);
			count+=mark<y;
			sum+=mark;
		}
		int low=n/2-count;	//还要添加小于y的个数
		int high=(n+1)/2-(k-count);	//还要添加大于y的个数
		if (low<0 || high<0 || sum+low+high*y>x){
			printf("-1\n");
			continue;
		}
		
		for (int i=0;i<low;i++)
			printf("1 ");
		for (int i=0;i<high-1;i++)
			printf("%d ",y);
		if (high>0)
			printf("%d\n",y);
	}
	return 0;
}
