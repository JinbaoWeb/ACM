#include <iostream>
#include <cmath>
using namespace std;
int map[32][32];
int ans[32];
void Guass(){
	for (int i=0;i<30;i++){	//控制行
		if (map[i][i]==0){	
			for (int j=i+1;j<30;j++){	//找到不为0的那一行，然后进行交换
				if (map[j][i]!=0){
					for (int k=i;k<31;k++){
						swap(map[j][k],map[i][k]);
					}
					break;
				}
			}
		}
		
		for (int j=0;j<30;j++){
			if (i!=j&&map[j][i]){
				for (int k=i;k<31;k++){
					map[j][k]=map[i][k]^map[j][k];
				}
			}
		}
	}
	for (int i=0;i<30;i++){
		ans[i]=map[i][30];
	}
}
int main(){
	int t,kn,km,kx,ky;
	cin>>t;
	for (int cas=1;cas<=t;cas++){
		for (int i=0;i<30;i++)
			cin>>map[i][30];
		for(int i=0;i<30;i++){      //构造30个方程    
            kn=i/6;  
            km=i%6;  
            for(int j=0;j<30;j++){  
                kx=j/6;   
                ky=j%6;  
                if(abs(kx-kn)+abs(ky-km)<=1)  
                    map[i][j]=1;  
                else  
                    map[i][j]=0;  
            }  
        }
        Guass();
        cout<<"PUZZLE #"<<cas<<endl;
        for (int i=0;i<30;i++){
        	if ((i+1)%6==0)
        		cout<<ans[i]<<endl;
        	else
        		cout<<ans[i]<<" ";
        }
	}
	return 0;
}