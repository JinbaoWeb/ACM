#include <iostream>
#include <algorithm>
using namespace std;
struct point{
	int x,y;
}p[1005];
int cmp(point a,point b){
	if (a.x<b.x)
		return 1;
	else
	{
		if (a.x>b.x)
			return 0;
		else
		{
			if (a.y<b.y)
				return 1;
			else
				return 0;
		}
	}
}
int main(){
	int t,n;
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=0;i<n;i++)
			cin>>p[i].x>>p[i].y;
		sort(p,p+n,cmp);
		int count=0;
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				if (p[i].x==p[j].x){
					for (int k=j+1;k<n;k++){
						if (p[k].x==p[i].x)
							count++;
						else
							break;
					}
				}
				else{
					if (p[i].y==p[j].y){
						for (int k=j+1;k<n;k++){
							if (p[k].y==p[i].y)	
								count++;
							else
								break;	
						}
					}
					else{
						double kk=(p[j].y-p[i].y)*1.0/(p[j].x-p[i].x);
						cout<<kk<<endl;
						for (int k=j+1;k<n;k++){
							cout<<(p[k].y-p[i].y)*1.0/(p[k].x-p[i].x)<<"-"<<endl;
							if ((p[k].y-p[i].y)*1.0/(p[i].x-p[k].x)-kk==0)
								count++;
							else
								break;
						}	
					}
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
