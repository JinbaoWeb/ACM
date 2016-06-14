#include <iostream>
using namespace std;
int main()
{
	int t;
	char map[4][4];
	cin>>t;
	for (int cas=1;cas<=t;cas++)
	{
		int num=0;			//0表示Draw，1表示Game has not completed，2表示X won，3表示O won
		for (int i=0;i<4;i++)
			for (int j=0;j<4;j++)
			{
				cin>>map[i][j];
				if (map[i][j]=='.')
					num=1;
			}
		/*********判断行*************/
		int a=0,b=0,c=0;
		for (int i=0;i<4;i++)
		{
			a=0;b=0;c=0;
			for (int j=0;j<4;j++)
			{
				if (map[i][j]=='T')
					a++;
				if (map[i][j]=='X')
					b++;
				if (map[i][j]=='O')
					c++;
			}
			if ((b==4)||(b==3&&a==1))
			{
				num=2;
				goto C;
			}	
			if ((c==4)||(c==3&&a==1))
			{
				num=3;
				goto C;
			}	
		}	
		/***************************/ 
		/*********判断列*************/
		for (int i=0;i<4;i++)
		{
			int a=0,b=0,c=0;
			for (int j=0;j<4;j++)
			{
				if (map[j][i]=='T')
					a++;
				if (map[j][i]=='X')
					b++;
				if (map[j][i]=='O')
					c++;
			}
			if ((b==4)||(b==3&&a==1))
			{
				num=2;
				goto C;
			}	
			if ((c==4)||(c==3&&a==1))
			{
				num=3;
				goto C;
			}	
		}	
		/***************************/ 
		/*******判断左对角*********/
		a=0;b=0;c=0;
		for (int i=0;i<4;i++)
		{
			if (map[i][i]=='T')
				a++;
			if (map[i][i]=='X')
				b++;
			if (map[i][i]=='O')
				c++;	
		} 
		if ((b==4)||(b==3&&a==1))
		{
			num=2;
			goto C;
		}	
		if ((c==4)||(c==3&&a==1))
		{
			num=3;
			goto C;
		}	
		/***************************/
		/*******判断右对角*********/
		a=0;b=0;c=0;
		for (int i=0;i<4;i++)
		{
			if (map[i][3-i]=='T')
				a++;
			if (map[i][3-i]=='X')
				b++;
			if (map[i][3-i]=='O')
				c++;	
		} 
		if ((b==4)||(b==3&&a==1))
		{
			num=2;
			goto C;
		}	
		if ((c==4)||(c==3&&a==1))
		{
			num=3;
			goto C;
		}	
		/***************************/
		C:
		cout<<"Case #"<<cas<<": ";
		switch (num)
		{
			case 0:
				cout<<"Draw"<<endl;
				break;
			case 1:
				cout<<"Game has not completed"<<endl;
				break;
			case 2:
				cout<<"X won"<<endl;
				break;
			case 3:
				cout<<"O won"<<endl;
				break;
		}
	}
	return 0;
}
