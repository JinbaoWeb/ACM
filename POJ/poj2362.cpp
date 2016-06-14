#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int t,n,a[25],s,flag;
bool used[25];
bool dfs(int num,int len,int n)
{
	if (len==s)
	{
		num++;
		n=flag;
		len=0;
	}
	if (num==4)
		return true;
	for (int i=n-1;i>=0;i--)
	{
		if (a[i]+len<=s&&used[i]==false)
		{
			used[i]=true;
			if (dfs(num,len+a[i],i)==true)
				return true;
			used[i]=false;
		}
	}
	return false;
}
int main()
{
	
	cin>>t;
	while (cin>>n)
	{
		memset(used,false,sizeof(used));
		int sum=0;
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}	
		sort(a,a+n);
		flag=n;
		s=sum/4;
		if (sum%4==0&&n>=4&&s>=a[n-1])
		{
			if (dfs(0,0,n)==true)
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}
		else
			cout<<"no"<<endl;
	}
	return 0;
} 



/*20 491 1050 1123 376 1045 1391 656 190 1305 537 20 533 1193 465 398 1258 756 
1005 949 63
20 1431 949 852 616 899 1257 413 335 528 107 1126 146 782 571 407 114 1393 
681 1229 1340
20 715 321 723 362 778 156 402 25 145 414 571 835 198 393 289 851 390 234 
1288 450
20 1450 1289 710 1209 287 202 1394 732 480 1121 1246 286 146 1333 1467 926 
471 453 921 889
20 407 1269 625 577 184 617 1357 994 107 250 783 117 1352 1355 820 16 336 
147 697 1134
20 679 1102 1502 1321 374 1472 288 428 1210 1497 1244 1412 573 1224 654 1465 
528 891 1417 311
20 1063 872 1391 987 513 566 1258 831 1295 604 1512 549 365 712 1146 1133 89 
561 1065 1476
20 1515 1473 1033 159 312 502 1342 1097 1231 476 1419 737 1200 174 1486 1311 
1261 416 1109 43
20 930 1165 584 56 1122 858 955 564 932 375 1267 580 1515 553 423 467 605 
722 1183 792
20 1035 1338 77 1253 243 715 177 951 852 1409 736 1170 694 945 555 289 1410 
539 869 1059*/
