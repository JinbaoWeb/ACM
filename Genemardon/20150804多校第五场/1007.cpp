#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
using namespace std;
inline void read(int &x){
    char c=0;
    for(;c<'0'||c>'9';c=getchar());
    for(x=0;c>='0'&&c<='9';c=getchar())x=x*10+(c-'0');
}
int main(){
	int n,x,y;
	int inf=-1e9-9;
	while (~scanf("%d",&n)){
		int cnt=0,cnt2=0;
		int Max=inf;
		while (n--){
			read(x);
			if (x==1){
				scanf("%d",&y);
				cnt++;
				if (Max<y){
					Max=y;
					cnt2=0;
				}
				if (Max==y)
					cnt2++;
			}
			if (x==2){
				if (cnt<=0){
					Max=inf;
					continue;
				}
				if (cnt==cnt2)
					cnt2--;
				cnt--;
				if (cnt2==0){
					Max=inf;
				}
			}
			if (x==3){
				if (cnt==0){
					printf("0\n");
					continue;
				}
				printf("%d\n",Max);
			}
			
		}
	}

	return 0;
}