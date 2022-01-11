#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7F7F7F7F
using namespace std;
int n;
char p[100019];
int f[100009][2][2];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char *s=p+10;
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;i++)
		{
			memset(f[i],0x7F,sizeof(f[i]));
			f[i][1][0]=min(f[i-1][0][0],f[i-1][0][1])+1;
			f[i][1][1]=min(f[i-1][1][0],f[i-1][1][1])+1;
			if(s[i]==s[i-1]&&s[i]==s[i-2])
			{
				f[i][0][0]=inf;
				f[i][0][1]=f[i-1][1][1];
			}
			else if(s[i]==s[i-1]&&s[i]!=s[i-2])
			{
				f[i][0][0]=inf;
				f[i][0][1]=min(f[i-1][1][0],f[i-1][1][1]);
			}
			else if(s[i]!=s[i-1]&&s[i]==s[i-2])
			{
				f[i][0][0]=f[i-1][0][1];
				f[i][0][1]=f[i-1][1][1];
			}
			else
			{
				f[i][0][0]=min(f[i-1][0][0],f[i-1][0][1]);
				f[i][0][1]=min(f[i-1][1][0],f[i-1][1][1]);
			}
		}
		int ans=inf;
		for(int j=0;j<=1;j++)
			for(int k=0;k<=1;k++)
				ans=min(ans,f[n][j][k]);
		printf("%d\n",ans);
	}
	return 0;
}