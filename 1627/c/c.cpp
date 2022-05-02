#include<bits/stdc++.h>
using namespace std;
struct node
{
	int v,id;
	node(){}
	node(int a,int b):v(a),id(b){}
};
int n;
int deg[100009],ans[100009];
vector<node> g[100009];
void dfs(int x,int fa,int cl)
{
	for(node t:g[x])
		if(t.v!=fa)
		{
			ans[t.id]=cl;
			dfs(t.v,x,cl^1);
		}
}
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			deg[i]=0;
		}
		for(int i=1;i<=n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			g[a].emplace_back(b,i);
			g[b].emplace_back(a,i);
			deg[a]++,deg[b]++;
		}
		int err=0;
		for(int i=1;i<=n;i++)
			if(deg[i]>2)
				err=1;
		if(err)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++)
			if(deg[i]==1)
			{
				dfs(i,0,0);
				break;
			}
		for(int i=1;i<=n-1;i++)
			printf("%d ",ans[i]+2);
		printf("\n");
	}
	return 0;
}