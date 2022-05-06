#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct edge
{
	int v,id;
	edge(){}
	edge(int b,int c):v(b),id(c){}
};
int n,m,tp;
int clv[200009],cle[200009];
vector<edge> g[200009];
void dfs(int x,int fa,int tid,int sm)
{
	if(!fa)
		clv[x]=n;
	else
	{
		if(sm==0)
		{
			cle[tid]=++tp;
			clv[x]=tp+n;
		}
		else
		{
			clv[x]=++tp;
			cle[tid]=tp+n;
		}
	}
	for(edge t:g[x])
		if(t.v!=fa)
			dfs(t.v,x,t.id,sm^1);
}
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&m);
		tp=0;
		n=1<<m;
		for(int i=1;i<=n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			g[a].emplace_back(b,i);
			g[b].emplace_back(a,i);
		}
		dfs(1,0,0,0);
		printf("1\n");
		for(int i=1;i<=n;i++)
			printf("%d ",clv[i]);
		printf("\n");
		for(int i=1;i<=n-1;i++)
			printf("%d ",cle[i]);
		printf("\n");
		for(int i=1;i<=n;i++)
			g[i].clear();
	}
	return 0;
}