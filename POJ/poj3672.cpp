#include <iostream>
using namespace std;
int main(){
	int m,t,u,f,d;
	char path[100005];
	int distance=0;
	while (cin>>m>>t>>u>>f>>d){
		distance=0;
		for (int i=0;i<t;i++){
			cin>>path[i];
			if (m==0)
				continue;
			if (path[i]=='u'||path[i]=='d'){
				if (m<(u+d))
					m=0;
				else{
					distance++;
					m-=(u+d);
				}
					
			}
			else{
				if (m<f+f)
					m=0;
				else{
					distance++;
					m-=2*f;
				}
			}
		}
		cout<<distance<<endl;	
		
	}
	return 0;
}
