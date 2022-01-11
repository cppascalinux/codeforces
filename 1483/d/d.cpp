#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,q;
ll mat[609][609],f[609][609];
int sy[609][609],ans[609][609];
int main()
{
	scanf("%d%d",&n,&m);
	memset(mat,0x1F,sizeof(mat));
	for(int i=1;i<=n;i++)
		mat[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		mat[a][b]=mat[b][a]=c;
	}
	memcpy(f,mat,sizeof(f));
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		sy[a][b]=sy[b][a]=c;
	}
	for(int u=1;u<=n;u++)
		for(int b=1;b<=n;b++)
		{
			ll mx=-1;
			for(int v=1;v<=n;v++)
				mx=max(mx,sy[u][v]-f[b][v]);
			for(int a=1;a<=n;a++)
				ans[a][b]|=(a!=b&&f[u][a]+mat[a][b]<=mx);
		}
	int sm=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(ans[i][j])
				sm++;
	printf("%d",sm);
	return 0;
}