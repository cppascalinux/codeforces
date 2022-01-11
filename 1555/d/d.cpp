#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[200009];
int sm[6][200009];
int p[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		s[i]-='a';
	for(int i=0;i<6;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sm[i][j]=sm[i][j-1];
			if(s[j]!=p[i][j%3])
				sm[i][j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int ans=1e9;
		for(int j=0;j<6;j++)
			ans=min(ans,sm[j][b]-sm[j][a-1]);
		printf("%d\n",ans);
	}
	return 0;
}