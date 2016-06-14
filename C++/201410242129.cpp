#include <iostream>
#include <cmath>
using namespace std;
#define MAX 44722
long long num[MAX];

int main(){
	long long a,b;
	for (int i=1;i<MAX;i++)
		num[i]=i*i;
	while (cin>>a>>b){
		int x=0,y=0,flag1=0,flag2=0;
		for (int i=1;i<MAX;i++){
			if (num[i]<a)
				x++;
			if (num[i]==a){
				x++;
				flag1=1;
			}
			if (num[i]<b)
				y++;
			else{
				if (num[i]==b){
					y++;
					flag2=1;
				}
				else
					break;
			}
		}
		if ((flag1==1&&flag2==1) || (flag1==1&&flag2==0))
			cout<<y-x+1<<endl;
		else{
			//if (flag1==0&&flag2==1)
				cout<<y-x<<endl;
		}
		//cout<<x<<" "<<y<<endl;
	//	cout<<y-x+1<<endl;
	}
	return 0;
}
