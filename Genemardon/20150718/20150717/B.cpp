#include <stdio.h>
#include <string.h>
using namespace std;
int n;
int point[40][2];
int map[300][300];
int MAX;
bool isin(int p1,int p2,int x,int y,int com)
{
	int res=1;
	if (y<=point[p1][1] && y>=point[p2][1] && x>=point[p1][0] && x<=point[p2][0]) res=0;
	return res;
}
bool isinin(int p1,int p2,int x,int y,int com)
{
	if (x>point[p1][0] && x<point[p2][0] && y>point[p2][1] && y<point[p1][1]) return 0;
	return 1;
}
int cal(int p1,int p2,int p3,int p4)
{
	return (point[p2][0]-point[p1][0])*(point[p1][1]-point[p2][1])+(point[p4][0]-point[p3][0])*(point[p3][1]-point[p4][1]);
}
void judge(int p1,int p2,int p3,int p4)
{
	if (point[p1][0]<point[p2][0] && point[p1][1]>point[p2][1])
		if (point[p3][0]<point[p4][0] && point[p3][1]>point[p4][1])
			if (map[point[p1][0]][point[p2][1]] && map[point[p2][0]][point[p1][1]])
				if (map[point[p3][0]][point[p4][1]] && map[point[p4][0]][point[p3][1]])
				{
					if (!isinin(p1,p2,point[p3][0],point[p3][1],1) && !isinin(p1,p2,point[p4][0],point[p4][1],2) && !isinin(p1,p2,point[p3][0],point[p4][1],3) && !isinin(p1,p2,point[p4][0],point[p3][1],4))
					{
						int area=(point[p2][0]-point[p1][0])*(point[p1][1]-point[p2][1]);
						if (area>MAX) MAX=area;
					}
					else
					if (!isinin(p3,p4,point[p1][0],point[p1][1],1) && !isinin(p3,p4,point[p2][0],point[p2][1],2) && !isinin(p3,p4,point[p1][0],point[p2][1],3) && !isinin(p3,p4,point[p2][0],point[p1][1],4))
					{
						int area=(point[p4][0]-point[p3][0])*(point[p3][1]-point[p4][1]);
						if (area>MAX) MAX=area;
					}
					else
					{
					if (isin(p1,p2,point[p3][0],point[p3][1],1) && isin(p1,p2,point[p4][0],point[p4][1],2) && isin(p1,p2,point[p3][0],point[p4][1],3) && isin(p1,p2,point[p4][0],point[p3][1],4))
						if (isin(p3,p4,point[p1][0],point[p1][1],1) && isin(p3,p4,point[p2][0],point[p2][1],2) && isin(p3,p4,point[p1][0],point[p2][1],3) && isin(p3,p4,point[p2][0],point[p1][1],4))
							//if (isinin(p1,p2,p3,p4))
							{
								//printf("(%d,%d) (%d,%d)  (%d,%d)  (%d,%d)\n",point[p1][0],point[p1][1],point[p2][0],point[p2][1],point[p3][0],point[p3][1],point[p4][0],point[p4][1] );
								int area=cal(p1,p2,p3,p4);
								if (area>MAX) MAX=area;
							}
					}
				}
}
int main(int argc, char const *argv[])
{
	while (scanf("%d",&n) && n)
	{
		memset(map,0,sizeof(map));
		memset(point,0,sizeof(point));
		MAX=0;
		for (int i=0;i<n;i++)
		{
			scanf("%d%d",&point[i][0],&point[i][1]);
			map[point[i][0]][point[i][1]]=1;
		}
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				for (int k=0;k<n;k++)
					for (int q=0;q<n;q++)
					{
						judge(i,j,k,q);
					}
		if (MAX>0) printf("%d\n",MAX );else printf("imp\n");
	}
	return 0;
}