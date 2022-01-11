#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
int n,d;
int sa[200009],dep[200009],ft[200009];
ll f[200009];
vector<int> g[200009],ds[200009];
struct node
{
	ll val;
	int id;
	bool operator<(const node &p)const{return val<p.val;}
};
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	ft[x]=fa;
	d=max(d,dep[x]);
	ds[dep[x]].push_back(x);
	for(int v:g[x])
		if(v!=fa)
			dfs(v,x);
}
bool cmp(int a,int b)
{
	return sa[a]<sa[b];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			g[i].clear(),ds[i].clear(),f[i]=0;
		for(int i=2;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			g[a].push_back(i),g[i].push_back(a);
		}
		for(int i=2;i<=n;i++)
			scanf("%d",sa+i);
		dfs(1,0);
		for(int i=2;i<=d;i++)
		{
			sort(ds[i].begin(),ds[i].end(),cmp);
			priority_queue<ll> ad,sb;
			int mn=0x7F7F7F7F,mx=0;
			for(int v:ds[i])
			{
				if(!sb.empty())
					f[v]=max(f[v],sb.top()+sa[v]);
				sb.push(f[ft[v]]-sa[v]);
				mn=min(mn,sa[v]);
				mx=max(mx,sa[v]);
			}
			for(auto it=ds[i].rbegin();it!=ds[i].rend();it++)
			{
				int v=*it;
				if(!ad.empty())
					f[v]=max(f[v],ad.top()-sa[v]);
				ad.push(f[ft[v]]+sa[v]);
			}
			for(int v:ds[i])
				f[v]=max(f[v],f[ft[v]]+max(sa[v]-mn,mx-sa[v]));
		}
		ll ans=0;
		for(int v:ds[d])
			ans=max(ans,f[v]);
		printf("%lld\n",ans);
	}
	return 0;
}