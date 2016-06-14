/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-06-19 00:30
 * Filename :        308A.cpp
 * Description :     
 * *****************************************************************************/

#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int main(){
	int map[101][101];
	int n,x1,y1,x2,y2;
	while (cin>>n){
		memset(map,0,sizeof(map));
		for (int i=0;i<n;i++){
			cin>>x1>>y1>>x2>>y2;
			for (int x=x1;x<=x2;x++)
				for (int y=y1;y<=y2;y++)
					map[x][y]++;
		}
		ll sum=0;
		for (int i=1;i<=100;i++)
			for (int j=1;j<=100;j++)
				sum+=map[i][j];
		cout<<sum<<endl;

	}
    return 0;
}