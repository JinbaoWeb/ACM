#include <bits/stdc++.h>
#include <string.h>
using namespace std;
typedef long long ll;
int a[100010];
int aa[100010];
int bb[100010];
int x[100010];
int y[100010];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int k=0;
	for (int i=0;i<n;i++){
		if (i==0){
			aa[k]=a[i];
			bb[k++]=1;
		}
		else{
			if (a[i]==a[k-1]){
				bb[k-1]++;
			}
			else{
				aa[k]=a[i];
				bb[k++]=1;
			}
		}
	}
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	for (int i=0;i<k;i++){
		int cnt=0;
		for (int j=i+1;j<k;j++){
			if (aa[j]<=aa[i]&&aa[i]-aa[j]<=1)
				cnt+=bb[j];
			else
				break;
		}
		x[i]=cnt;
		cnt=0;
		for (int j=i-1;j>=0;j--){
			if (aa[j]<=aa[i] && aa[i]-aa[j]<=1)
				cnt+=bb[j];
			else
				break;
		}
		y[i]=cnt;
	}
	int ans=0;
	for (int i=0;i<n;i++){
		cout<<x[i]<<" "<<y[i]<<endl;
		ans=max(x[i]+y[i]+1,ans);
	}
	cout<<ans<<endl;
	return 0;
}