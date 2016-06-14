#include <iostream>
using namespace std;
#define MAX 40005
int a[MAX],f[MAX],dp[MAX];    //dp[i]���ڼ�¼a[0........i]����󳤶ȣ�
int bsearch(const int *f,int size,const int &a){
    int l=0,r=size-1;
    while (l<=r){
        int mid=(l+r)/2;
        if (a>f[mid-1] && a<=f[mid])        //����ǵݼ��Ļ����ѷ��Ż�һ�£�
            return mid;                                
        else if (a<f[mid])
                    r=mid-1;
                else
                    l=mid+1;
    }
}
int LIS(const int *a,const int &n){
    int i,j,size=1;
    f[0]=a[0];
    dp[0]=1;
    for (i=1;i<n;i++){                                //����ǵݼ��Ļ����ѷ��Ż�һ�£�
        if (a[i]<=f[0])
            j=0;
        else if (a[i]>f[size-1])                    //����ǵݼ��Ļ����ѷ��Ż�һ�£�
                    j=size++;
                else
                        j=bsearch(f,size,a[i]);
                f[j]=a[i];
                dp[i]=j+1;
    }
    return size;
}
int main()
{
	int t,n;
	cin>>t;
	for (int cases=1;cases<=t;cases++)
	{
		cin>>n;
		for (int i=0;i<n;i++)
			cin>>a[i];
		cout<<LIS(a,n)<<endl;;
	}
	return 0;
} 
