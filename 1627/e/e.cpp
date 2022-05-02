#include<bits/stdc++.h>
#define inf 0x3F3F3F3F3F3F3F3FLL
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct edge
{
	int v;
	ll l;
	edge(){}
	edge(int a,ll b):v(a),l(b){}
	bool operator<(const edge &o)const{return l>o.l;}
};
int n,m,k,tot;
int sx[100009];
vector<edge> g1[200009],g2[200009];
int vis[200009];
ll dis[200009];
void clear()
{
	for(int i=1;i<=tot;i++)
		g1[i].clear(),g2[i].clear();
	tot=0;
}
void dij(vector<int> &s)
{
	if(s.empty())
		return;
	priority_queue<edge> pq;
	// printf("qwq\n");
	for(int v:s)
	{
		pq.emplace(v,dis[v]);
		// printf("%d ",v);
	}
	while(!pq.empty())
	{
		edge t=pq.top();
		pq.pop();
		if(vis[t.v])
			continue;
		vis[t.v]=1;
		for(edge nt:g2[t.v])
			if(!vis[nt.v]&&dis[nt.v]>t.l+nt.l)
			{
				dis[nt.v]=t.l+nt.l;
				pq.emplace(nt.v,dis[nt.v]);
			}
	}
	for(int v:s)
		if(dis[v]<inf)
			for(edge t:g1[v])
				dis[t.v]=min(dis[t.v],dis[v]+t.l);
}
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",sx+i);
		map<pii,int> mp;
		tot=0;
		mp[pii(1,1)]=++tot;
		mp[pii(n,m)]=++tot;
		for(int i=1;i<=k;i++)
		{
			int a,b,c,d,h;
			scanf("%d%d%d%d%d",&a,&b,&c,&d,&h);
			int &v1=mp[pii(a,b)],&v2=mp[pii(c,d)];
			if(!v1)
				v1=++tot;
			if(!v2)
				v2=++tot;
			g1[v1].emplace_back(v2,-h);
		}
		for(int i=1;i<=tot;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		dis[1]=0;
		pair<pii,int> lst(pii(0,0),0);
		vector<int> tmp;
		for(auto t:mp)
		{
			if(lst.fi.fi==t.fi.fi)
			{
				g2[t.se].emplace_back(lst.se,(ll)abs(t.fi.se-lst.fi.se)*sx[t.fi.fi]);
				g2[lst.se].emplace_back(t.se,(ll)abs(t.fi.se-lst.fi.se)*sx[t.fi.fi]);
			}
			else
			{
				dij(tmp);
				tmp.clear();
			}
			tmp.push_back(t.se);
			lst=t;
		}
		dij(tmp);
		if(dis[2]<inf)
			printf("%lld\n",dis[2]);
		else
			printf("NO ESCAPE\n");
		clear();
	}
	return 0;
}