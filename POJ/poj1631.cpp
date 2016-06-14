#include <iostream>
using namespace std;
#define MAX 40005
int a[MAX],f[MAX],dp[MAX];    //dp[i]用于记录a[0........i]的最大长度；
int bsearch(const int *f,int size,const int &a){
    int l=0,r=size-1;
    while (l<=r){
        int mid=(l+r)/2;
        if (a>f[mid-1] && a<=f[mid])        //如果是递减的话，把符号换一下；
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
    for (i=1;i<n;i++){                                //如果是递减的话，把符号换一下；
        if (a[i]<=f[0])
            j=0;
        else if (a[i]>f[size-1])                    //如果是递减的话，把符号换一下；
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
