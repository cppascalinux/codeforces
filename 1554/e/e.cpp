#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n,fil;
vector<int> g[100009];
int deg[100009],ans[100009];
int f[100009];
void dfs(int x,int fa,int dv)
{
	for(int v:g[x])
		if(v!=fa)
		{
			dfs(v,x,dv);
			if(fil)
				return;
		}
	if(fa)
	{
		if(f[x]%dv==0)
			f[fa]++;
		else if((f[x]+1)%dv==0)
			f[x]++;
		else
			fil=1;
	}
	else
	{
		if(f[x]%dv==0)
			f[fa]++;
		else
			fil=1;
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
			g[i].clear(),deg[i]=ans[i]=0;
		for(int i=1;i<=n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			g[a].push_back(b),g[b].push_back(a);
			deg[a]++,deg[b]++;
		}
		for(int i=2;i<=n-1;i++)
			if((n-1)%i==0)
			{
				for(int j=1;j<=n;j++)
					f[j]=0;
				fil=0;
				dfs(1,0,i);
				if(!fil)
					ans[i]=1;
			}
		for(int i=2;i<=n-1;i++)
			for(int j=i*2;j<=n-1;j+=i)
				if(ans[i]&&ans[j])
					ans[i]=0;
		ans[1]=1;
		for(int i=1;i<=n-1;i++)
			ans[1]=ans[1]*2%mod;
		for(int i=2;i<=n-1;i++)
			ans[1]=(ans[1]+mod-ans[i])%mod;
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}