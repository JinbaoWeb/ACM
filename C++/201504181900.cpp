#include <iostream>
using namespace std;
int main(){
	int x[4],y[4],z[4];
	int p1,p2,p3,p4;
	int t;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		int flag=0;
		for (int i=0;i<4;i++)
			cin>>x[i]>>y[i]>>z[i];
		for (int i=0;i<4;i++){
			for (int j=0;j<4;j++){
				if (i==j)
					continue;
				p1=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]);
				for (int k=0;k<4;k++){
					if (k==i || k==j)
						continue;
					p2=(x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k])+(z[i]-z[k])*(z[i]-z[k]);
					for (int s=0;s<4;s++){
						if (s==i || s==j || s==k)
							continue;
						p3=(x[s]-x[j])*(x[s]-x[j])+(y[s]-y[j])*(y[s]-y[j])+(z[s]-z[j])*(z[s]-z[j]);
						p4=(x[s]-x[k])*(x[s]-x[k])+(y[s]-y[k])*(y[s]-y[k])+(z[s]-z[k])*(z[s]-z[k]);
						if (p1==p2 && p2==p3 && p3==p4){
							flag=1;
							goto C;
						}
					}
				}
			}
		}
C:
		cout<<"Case #"<<cas<<": ";
		if (flag==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}