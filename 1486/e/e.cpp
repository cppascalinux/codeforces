#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
#define inf 0x7F7F7F7F
using namespace std;
struct node
{
	int v,l;
	bool operator<(const node &p)const{return l>p.l;}
};
struct edge
{
	int v,l,nxt;
};
int n,m,tot;
int vis[5100009];
int dis[5100009];
vector<node> g0[100009];
int hd[5100009];
edge eg[21000009];
void dij()
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x7F,sizeof(dis));
	dis[1]=0;
	priority_queue<node> pq;
	pq.push(node{1,0});
	while(!pq.empty())
	{
		node x=pq.top();
		pq.pop();
		if(vis[x.v])
			continue;
		vis[x.v]=1;
		for(int i=hd[x.v];i;i=eg[i].nxt)
			if(!vis[eg[i].v]&&dis[eg[i].v]>x.l+eg[i].l)
				dis[eg[i].v]=x.l+eg[i].l,pq.push(node{eg[i].v,dis[eg[i].v]});
	}
}
void adde(int a,int b,int c)
{
	eg[++tot]=edge{b,c,hd[a]};
	hd[a]=tot;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		g0[a].push_back(node{b,c}),g0[b].push_back(node{a,c});
	}
	int sm=n;
	for(int i=1;i<=n;i++)
	{
		for(node t:g0[i])
		{
			adde(sm+t.l,t.v,0);
			for(int j=1;j<=50;j++)
				adde(t.v,sm+j,(j+t.l)*(j+t.l));
		}
		sm+=50; 
	}
	dij();
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]<inf?dis[i]:-1);
	return 0;
}