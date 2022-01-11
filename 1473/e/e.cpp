#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
#define pb push_back
using namespace std;
struct node
{
	int v;
	ll l;
	bool operator<(const node &p)const{return l>p.l;}
};
int n,m;
int ea[200009],eb[200009],ec[200009];
int vis[600009];
ll dis[600009];
ll ans[200009];
vector<node> e[600009];
void dij()
{
	priority_queue<node> pq;
	memset(dis,0x7F,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	pq.push(node{1,0});
	while(!pq.empty())
	{
		node t=pq.top();
		pq.pop();
		if(vis[t.v])
			continue;
		vis[t.v]=1;
		for(node u:e[t.v])
			if(!vis[u.v]&&dis[u.v]>t.l+u.l)
				dis[u.v]=t.l+u.l,pq.push(node{u.v,dis[u.v]});
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		ea[i]=a,eb[i]=b,ec[i]=c;
		e[a].pb(node{b,c}),e[b].pb(node{a,c});
		e[a+n].pb(node{b+n,c}),e[b+n].pb(node{a+n,c});
		e[a+2*n].pb(node{b+2*n,c}),e[b+2*n].pb(node{a+2*n,c});
		e[a].pb(node{b+n,0}),e[b].pb(node{a+n,0});
		e[a+n].pb(node{b+2*n,2*c}),e[b+n].pb(node{a+2*n,2*c});
	}
	dij();
	memset(ans,0x7F,sizeof(ans));
	for(int i=1;i<=n;i++)
		ans[i]=min(ans[i],min(dis[i],dis[i+2*n])),e[i].clear();
	for(int i=1;i<=m;i++)
	{
		int a=ea[i],b=eb[i],c=ec[i];
		e[a].pb(node{b,c}),e[b].pb(node{a,c});
		e[a+n].pb(node{b+n,c}),e[b+n].pb(node{a+n,c});
		e[a+2*n].pb(node{b+2*n,c}),e[b+2*n].pb(node{a+2*n,c});
		e[a].pb(node{b+n,2*c}),e[b].pb(node{a+n,2*c});
		e[a+n].pb(node{b+2*n,0}),e[b+n].pb(node{a+2*n,0});
	}
	dij();
	for(int i=2;i<=n;i++)
	{
		ans[i]=min(ans[i],min(dis[i],dis[i+2*n]));
		printf("%lld ",ans[i]);
	}
	return 0;
}