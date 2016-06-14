#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main(){
	int a[6];
	bool used[6];
	while (cin>>a[0]){
		for (int i=1;i<6;i++)
			cin>>a[i];
		memset(used,false,sizeof(used));
		sort(a,a+6);
		int flag=0;
		for (int i=0;i<6;i++){
			int count=0;
			for (int j=0;j<6;j++){
				if (a[i]==a[j])
					count++;
			}
			if (count==4){
				for (int j=0;j<6;j++)
					if (a[i]==a[j])
						used[j]=true;
				flag=1;
				break;
			}
			else{
				if (count>4){
					int ccount=0;
					flag=1;
					for (int j=0;j<6;j++){
						if (a[i]==a[j]){
							used[j]=true;
							ccount++;
							if (ccount==4)
								break;
						}
					}
				}
			}
		}
		if (flag){
			for (int i=0;i<6;i++){
				if (used[i]==true)
					continue;
				for (int j=i+1;j<6;j++){
					if (used[j]==true)
						continue;
					if (a[i]!=a[j])
						cout<<"Bear"<<endl;
					else
						cout<<"Elephant"<<endl;
				}
			}
		}
		else{
			cout<<"Alien"<<endl;
		}
	}
	return 0;
}
