#include <iostream>
using namespace std;
int main()
{
	int a[6],sum;
	while (cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5])
	{
		sum=0;
		if (a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0)
			break;
		sum+=a[5]+a[4]+a[3];					//+a[3]+a[2]/4+a[1]/9+a[0]/36
		if (a[0]>=11*a[4])		//5
			a[0]-=11*a[4];
		else	
			a[0]=0;
		if (a[1]>=5*a[3])		//4
			a[1]-=5*a[3];
		else
		{
			int s=5*a[3]-a[1];
			a[1]=0;
			if (a[0]>=s*4)
				a[0]-=s*4;
			else
				a[0]=0;
		}
		sum+=a[2]/4;
		int kk=0;
		if (a[2]/4*4<a[2])
			kk=1;					
		a[2]%=4;				//3
		if (a[2]==1)
		{
			if (a[1]>=5)
			{
				a[1]-=5;
				if (a[0]>=7)
				{
					a[0]-=7;
					if (kk==1)
						sum++;
				}	
				else
					a[0]=0;
			}
			else
			{
				int l=5-a[1];
				a[1]=0;
				if (a[0]>=l*4)
				{
					a[0]-=l*4;
					if (kk==1)
						sum++;
				}	
				else
					a[0]=0;
			}
		}
		if (a[2]==2)
		{
			if (a[1]>=3)
			{
				a[1]-=3;
				if (a[0]>=6)
				{
					a[0]-=6;
					if (kk==1)
						sum++;
				}	
				else
					a[0]=0;
			}
			else
			{
				int ii=(3-a[1])*4+6;
				a[1]=0;
				if (a[0]>=ii)
				{
					a[0]-=ii;
					if (kk==1)
						sum++;
				}	
				else
					a[0]=0;
			}
		}
		if (a[2]==3)
		{
			if (a[1]>=1)
			{
				a[1]-=1;
				if (kk==1)
					sum++;
			}	
			else
			{
				if (a[0]>=5)
				{
					a[0]-=5;
					if (kk==1)
						sum++;
				}	
				else
					a[0]=0;
			}
		}
		sum+=a[1]/9;
		int ss=0;
		if (a[1]/9*9<a[1])
			ss=1;
		a[1]%=9;				//2
		int jj=(9-a[1])*4;
		if (a[0]>=jj)
		{
			a[0]-=jj;
			if (ss==1)
						sum++;
		}	
		else
			a[0]=0;
		sum+=a[0]/36;
		a[0]%=36;
		if (a[0]>=1)
			sum++;
		cout<<sum<<endl;
	}
	return 0;
}
