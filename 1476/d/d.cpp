#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char s[300009];
int f[2][2][300009];// org/inv, left/right
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			s[i]=(s[i]=='L'?0:1);
		for(int i=0;i<=1;i++)
			for(int j=0;j<=1;j++)
				for(int k=1;k<=n+1;k++)
					f[i][j][k]=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==0)
				f[0][0][i+1]=f[1][0][i]+1;
			else
				f[1][0][i+1]=f[0][0][i]+1;
		}
		for(int i=n;i>=1;i--)
		{
			if(s[i]==1)
				f[0][1][i]=f[1][1][i+1]+1;
			else
				f[1][1][i]=f[0][1][i+1]+1;
		}
		for(int i=1;i<=n+1;i++)
			printf("%d ",f[0][0][i]+f[0][1][i]-1);
		printf("\n");
	}
	return 0;
}