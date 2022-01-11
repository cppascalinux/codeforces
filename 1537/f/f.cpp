#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,odd;
int v[200009],cl[200009];
vector<int> g[200009];
void dfs(int x,int d)
{
	if(cl[x]>=0)
	{
		if(cl[x]!=d)
			odd=1;
		return;
	}
	// printf("x:%d\n",x);
	cl[x]=d;
	for(int v:g[x])
		dfs(v,d^1);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",v+i);
			g[i].clear();
		}
		ll sm=0;
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			v[i]-=a;
			sm+=v[i];
		}
		for(int i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			// a=i,b=i%n+1;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		if(sm&1)
		{
			printf("NO\n");
			continue;
		}
		for(int i=1;i<=n;i++)
			cl[i]=-1;
		odd=0;
		dfs(1,0);
		if(odd)
		{
			printf("YES\n");
			continue;
		}
		ll sm1=0;
		for(int i=1;i<=n;i++)
			if(cl[i])
				sm1+=v[i];
		printf("%s\n",sm1*2==sm?"YES":"NO");
	}
	return 0;
}