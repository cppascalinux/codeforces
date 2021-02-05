#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cassert>
#define ll long long
using namespace std;
int n,m;
int ql[500009],qr[500009];
int ansp[500009],ansq[500009];
int deg0[500009],del[500009];
int f[500009];
int st[500009],tot;
int vis[500009];
vector<int> g0[500009],g1[500009];
set<int> g2[500009];
void clr()
{
	memset(deg0,0,(n+1)*4);
	memset(del,0,(n+1)*4);
	memset(vis,0,(n+1)*4);
	for(int i=1;i<=n;i++)
		g0[i].clear(),g1[i].clear(),g2[i].clear();
}
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
void bfs(int s)
{
	queue<int> q;
	f[s]=fnd(s+1);
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		st[++tot]=x;
		q.pop();
		int ls=0;
		g0[x].push_back(n+1);
		for(int rb:g0[x])
		{
			// printf("x:%d rb:%d\n",x,rb);
			if(rb-1>=ls+1)
			{
				int p=fnd(ls+1);
				while(p<=rb-1)
				{
					g1[x].push_back(p),g1[p].push_back(x);
					q.push(p);
					f[p]=fnd(p+1);
					p=fnd(p);
				}
			}
			ls=rb;
		}
	}
}
void gett()
{
	for(int i=1;i<=n+1;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		if(del[i])
			f[fnd(i)]=fnd(i+1);
	for(int i=1;i<=n;i++)
		if(fnd(i)==i)
		{
			// printf("i:%d",i),fflush(stdout);
			tot=0;
			bfs(i);
			for(int j=1;j<=tot;j++)
			{
				int x=st[j];
				if(vis[x])
					continue;
				for(int v:g1[x])
					if(!vis[v])
						vis[v]=x,g2[x].insert(v);
				if(g2[x].empty())
				{
					int v=g1[x][0];
					int rt=vis[v];
					if(rt==v)
						g2[rt].insert(x),vis[x]=rt;
					else if(g2[rt].size()==1)
						g2[rt].clear(),g2[v].insert(rt),g2[v].insert(x),vis[rt]=vis[v]=vis[x]=v;
					else
						g2[rt].erase(v),g2[x].insert(v),vis[v]=vis[x]=x;
				}
			}
		}
	int sm=0;
	// puts("qwq");
	// for(int i=1;i<=n;i++)
	// 	for(int j:g1[i])
	// 		if(i<j)
	// 			printf("%d %d\n",i,j);
	// puts("pwp");
	for(int i=1;i<=n;i++)
		if(g2[i].size())
		{
			// printf("i:%d------------\n",i);
			// for(int v:g2[i])
			// 	printf("%d ",v);
			// printf("\n");
			ansp[i]=sm+1,ansq[i]=sm+g2[i].size()+1;
			int tp=0;
			for(int v:g2[i])
				tp++,ansp[v]=sm+tp+1,ansq[v]=sm+tp;
			sm=ansq[i];
		}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1,a,b;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			ql[i]=a,qr[i]=b;
			deg0[a]++,deg0[b]++;
		}
		int tp=n;
		for(int i=1;i<=n;i++)
			if(deg0[i]==n-1)
				ansp[i]=ansq[i]=tp--,del[i]=1;
		for(int i=1;i<=m;i++)
			if(!del[ql[i]]&&!del[qr[i]])
				g0[ql[i]].push_back(qr[i]),g0[qr[i]].push_back(ql[i]);
		for(int i=1;i<=n;i++)
			sort(g0[i].begin(),g0[i].end());
		// printf("qwq");
		gett();
		for(int i=1;i<=n;i++)
		{
			assert(ansp[i]);
			assert(ansq[i]);
		}
		for(int i=1;i<=m;i++)
			assert((ll)(ansp[ql[i]]-ansp[qr[i]])*(ansq[ql[i]]-ansq[qr[i]])>0);
		for(int i=1;i<=n;i++)
			printf("%d ",ansp[i]);
		printf("\n");
		for(int i=1;i<=n;i++)
			printf("%d ",ansq[i]);
		printf("\n");
		clr();
	}
	return 0;
}