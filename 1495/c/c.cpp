#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[509];
int mat[509][509];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
				mat[i][j]=s[j]=='X'?1:0;
		}
		for(int i=1;i<=n;i+=3)
			for(int j=1;j<=m;j++)
				mat[i][j]=1;
		for(int i=1;i+3<=n;i+=3)
		{
			int fg=0;
			for(int j=1;j<=m;j++)
			{
				if(mat[i+1][j]||mat[i+2][j])
				{
					fg=j;
					break;
				}
			}
			if(fg)
				mat[i+1][fg]=mat[i+2][fg]=1;
			else
				mat[i+1][1]=mat[i+2][1]=1;
		}
		if(n%3==0)
		{
			for(int j=1;j<=m;j++)
				if(mat[n][j])
					mat[n-1][j]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				printf("%c",mat[i][j]?'X':'.');
			printf("\n");
		}
	}
	return 0;
}