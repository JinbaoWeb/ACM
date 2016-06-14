#include <iostream>
#include <string.h>
using namespace std;
#define MAX 15010
int main(){
    int n;	
    int a[MAX];	//�洢�����n������
    int sum[MAX];	//��sum[i]�洢1-i�ĺͶ�nģ���Ľ��
    int used[MAX];	//��¼ÿ��sum[i]�����ֵ��±�
    while (cin>>n){
	sum[0]=a[0]=0;
	for (int i=1;i<=n;i++){
	    cin>>a[i];
	    sum[i]=(a[i]+sum[i-1])%n;
	}
	memset(used,-1,sizeof(used));
	used[0]=0;
	for (int i=1;i<=n;i++){
	    if (used[sum[i]]==-1)
		used[sum[i]]=i;
	    else{
		cout<<i-used[sum[i]]<<endl;
		for (int x=sum[i]+1;x<=i;x++)
		    cout<<a[x]<<endl;
		break;
	    }
    	}
    }
    return 0;
}