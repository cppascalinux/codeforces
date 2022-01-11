#include<bits/stdc++.h>
using namespace std;
int n,p,ans;
int s[20];
void dfs(int d,int sm)
{
	if(d>n)
	{
		if(s[p]==sm)
			ans=1;
		return;
	}
	if(d==p)
	{
		dfs(d+1,sm);
	}
	else
	{
		dfs(d+1,sm+s[d]);
		dfs(d+1,sm);
		dfs(d+1,sm-s[d]);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			p=i;
			dfs(1,0);
		}
		printf("%s\n",ans?"YES":"NO");
	}
	return 0;
}