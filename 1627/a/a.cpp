#include<bits/stdc++.h>
using namespace std;
char s[109];
int mt[109][109];
int n,m,r,c;
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		int sm=0,fg=0;
		scanf("%d%d%d%d",&n,&m,&r,&c);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
				if(s[j]=='B')
				{
					mt[i][j]=1;
					sm++;
					if(i==r||j==c)
						fg=1;
				}
				else
					mt[i][j]=0;
		}
		if(sm==0)
		{
			printf("-1\n");
			continue;
		}
		if(mt[r][c]==1)
		{
			printf("0\n");
			continue;
		}
		printf("%d\n",fg?1:2);
	}
	return 0;
}