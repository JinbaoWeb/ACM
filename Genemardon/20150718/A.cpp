#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int num[1005][200], line, mp, ans[200], len[1005], stop[1005];
char str[1005][200];
void output()
{
	memset(ans, 0, sizeof(ans));
	for(int j = 0;j < mp;j++)
		for(int i = 0;i < line;i++)
			if(num[i][j] > ans[j])
				ans[j] = num[i][j];
	//for(int i = 0;i < mp;i++)
		//printf("%d%c", ans[i], " \n"[i == mp-1]);
	for(int i = 0;i < line;i++)
	{
		int j = ans[0], p = 0, s = 0;
		for(int k = 0;k <= stop[i];)
		{
			if(str[i][k] == ' ')
			{
				while(k - s <= ans[p])
				{
					printf(" ");
					s--;
				}
				while(str[i][k] == ' ')
					k++;
				p++;
				s = k;
			}
			else
				printf("%c", str[i][k++]);
		}
		printf("\n");
	}	
}

int main()
{
	//freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	getchar();
	while(T--)
	{
		memset(num, 0, sizeof(num));
		memset(len, 0, sizeof(len));
		line = mp = 0;
		while(1)
		{
			char c;
			while(1)
			{
				c = getchar();
				if(c == '\n')
					continue;
				if(c != ' ')
				{
					ungetc(c, stdin);
					break;
				}
			}
			gets(str[line]);
			//printf("%s\n", str[line]);
			if(str[line][0] == '@')
				break;
			len[line] = strlen(str[line]);
			int p = 0, s = 0;
			for(int i = len[line]-1;i >= 0;i--)
			{
				if(str[line][i] != ' ')
				{
					stop[line] = i;
					break;
				}
			}
			str[line][len[line]] = ' ', str[line][len[line]+1] = '\0';
			for(int i = 0;i <= len[line];)
			{
				if(str[line][i] == ' ')
				{
					num[line][p++] = i - s;
					while(str[line][i] == ' ')
						i++;
					s = i;
				}
				else if(str[line][i] == '\n')
					break;
				else
					i++;
			}
			for(int i = len[line]-1;i >= 0;i--)
			{
				if(str[line][i] != ' ')
				{
					stop[line] = i;
					break;
				}
			}
			//for(int i = 0;i < p;i++)
				//printf("%d  ", num[line][i]);
			//printf("-------%d\n", stop[line]);
			if(p > mp)
				mp = p;
			line++;
		}
		output();
	}
	return 0;
}