#include <iostream>
#include <algorithm>
using namespace std;
bool used[500][500][500];
int main(){
	cout<<"test"<<endl;
	int a[3];
	int x,y,z;
	for (x=1;x<500;x++){
		for (y=x;y<500;y++){
			for (z=y;z<500;z++){
				if ((x+y+z)%3!=0)
					continue;
				a[0]=x,a[1]=y,a[2]=z;
				int count=0;
				//cout<<"----";
				//cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
				while (1){
					count++;
					if (count>10000000){
						cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
						break;
					}
					if (a[0]==a[1] && a[1]==a[2])
						break;
					sort(a,a+3);
					a[2]-=a[0];
					a[0]*=2;
				}

			}
		}
	}

	return 0;
}