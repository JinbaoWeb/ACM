#include <iostream>
#include <string.h>
using namespace std;
int wall[1000015],color[33];
int main(){
	int n,m;
	char s;
	int a,b,c;
	while (cin>>n>>m){
		if (n==0&&m==0)
			break;
		memset(wall,2,sizeof(wall));
		for (int i=0;i<m;i++){
			cin>>s;
			if (s=='P'){
				cin>>a>>b>>c;
				for (int j=a;j<=b;j++)
					wall[j]=c;
			}
			else{
				cin>>a>>b;
				memset(color,0,sizeof(color));
				for (int j=a;j<=b;j++)
					color[wall[j]]++;
				int flag=0;
				for (int i=0;i<=30;i++)
				{
					
					if (color[i])
					{
						if (flag)
							cout<<" ";
						cout<<i;
						flag=1;
					}
				}	
				cout<<endl;
			}
		}
	}
	return 0;
}
