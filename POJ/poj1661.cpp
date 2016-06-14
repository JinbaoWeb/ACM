/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-09 13:37
 * Filename :        poj1661.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct line{
	int x,y,h;
}l[1005];
int dp[1005];
bool cmp(line a,line b){
	if (a.h>b.h)
		return true;
	return false;
}
int main(){
	int t,n,x,y,max;
	cin>>t;
	while (t--){
		cin>>n>>x>>y>>max;
		memset(dp,0,sizeof(dp));
		for (int i=0;i<n;i++)
			cin>>l[i].x>>l[i].y>>l[i].h;
		l[n].x=-20001;
		l[n].y=20001;
		l[n].h=0;
		sort(l,l+n+1,cmp);
	//	cout<<"----------------------------------"<<endl;
//		for (int i=0;i<=n;i++)
//			cout<<l[i].x<<" "<<l[i].y<<" "<<l[i].h<<endl;
//		cout<<"-----------------------------------"<<endl;
		int i;
		for (i=0;i<=n;i++){//找到第一个下落平台
			if (l[i].x<=x && x<=l[i].y && y-l[i].h<=max){
	 			dp[1]=dp[0]+y-l[i].h;
				y=l[i].h;
				break;
			}
		}
		int index=2;
		for (;i<=n;i++){
			int left_time=0,right_time=0,j,k;
			//向左走
			for (j=i+1;j<=n;j++){
	 			if (l[j].x<=l[i].x && l[i].x<=l[j].y && y-l[j].h<=max){
 					left_time=x-l[i].x+y-l[j].h;
					break;
				}
			}
			//向右走
			for (k=i+1;k<=n;k++){
 				if (l[k].x<=l[i].y && l[i].y<=l[k].y && y-l[k].h<=max){
 					right_time=l[i].y-x+y-l[k].h;
					break;
				}
			}
		//	cout<<left_time<<" "<<right_time<<endl;
			if (left_time<right_time && left_time!=0){
				i=j;
				x=l[i].x;
				y=l[j].h;
				dp[index]=left_time+dp[index-1];
				index++;
			}
			if (right_time<left_time && right_time!=0){
	 			i=k;
				x=l[i].y;
				y=l[k].h;
				dp[index]=right_time+dp[index-1];
				index++;
			}
		}
	//	for (int i=0;i<=n+1;i++)
	//		cout<<dp[i]<<" ";
	//	cout<<endl;
		if (index==2)
			cout<<dp[1]<<endl;
		else
			cout<<dp[index]<<endl;
	}
	return 0;
}
