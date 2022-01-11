#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,q,tot;
int p[200009],st[200009];
int sa[200009],sb[200009];
int f[200009][19],dep[200009];
int vis[200009],rep[200009];
int dfn[200009];
ll dp[200009],psm[200009];
int anc[200009];
vector<int> g[200009];
void dfs1(int x,int fa)
{
	dfn[x]=++tot;
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=18;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	dp[x]=sa[x]-sb[x];
	for(int v:g[x])
	{
		dfs1(v,x);
		dp[x]+=min(0LL,dp[v]);
		dp[x]+=sb[v];
	}
}
void dfs2(int x)
{
	if(x==0)
		psm[x]=dp[x];
	for(int v:g[x])
	{
		psm[v]=psm[x]+max(0LL,dp[v]);
		dfs2(v);
	}
}
int getkf(int x,int k)
{
	for(int i=0;i<=18;i++)
		if(k>>i&1)
			x=f[x][i];
	return x;
}
int getlca(int a,int b)
{
	if(dep[a]<dep[b])
		swap(a,b);
	a=getkf(a,dep[a]-dep[b]);
	if(a==b)
		return a;
	for(int i=18;i>=0;i--)
		if(f[a][i]!=f[b][i])
			a=f[a][i],b=f[b][i];
	return f[a][0];
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",p+i);
	for(int i=1;i<=n;i++)
		scanf("%d",sa+i);
	for(int i=1;i<=n;i++)
		scanf("%d",sb+i);
	int tp=0;
	for(int i=1;i<=n;i++)
	{
		while(tp&&p[i]>=p[st[tp]])
			tp--;
		// printf("i:%d fa:%d\n",i,st[tp]);
		g[st[tp]].push_back(i);
		st[++tp]=i;
	}
	dfs1(0,0);
	dfs2(0);
	set<pii> s;
	s.insert(pii(dfn[0],0));
	rep[0]=1;
	ll ans=dp[0];
	// for(int i=1;i<=n;i++)
		// printf("i:%d dfn:%d\n",i,dfn[i]);
	// printf("ans:%lld\n",ans);
	// printf("2: 5: %d\n",getlca(2,5));
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d psm:%lld\n",i,psm[i]);
	for(int i=1;i<=q;i++)
	{
		int a;
		scanf("%d",&a);
		int fa=f[a][0];
		if(!vis[a])
		{
			vis[a]=1;
			if(!rep[fa])
			{
				assert(!s.count(pii(dfn[fa],fa)));
				auto it=s.lower_bound(pii(dfn[fa],fa));
				it--;
				int lca=getlca(fa,it->se);
				it++;
				if(it!=s.end())
				{
					int nlca=getlca(fa,it->se);
					if(dep[nlca]>dep[lca])
						lca=nlca;
				}
				// printf("a:%d b:%d lca:%d\n",fa,it->se,lca);
				// int sn=getkf(fa,dep[fa]-dep[lca]-1);
				ans+=psm[fa]-psm[lca];
				if(!s.count(pii(dfn[lca],lca)))
				{
					assert(rep[lca]==0);
					rep[lca]=1;
					auto ti=s.upper_bound(pii(dfn[lca],lca));
					anc[lca]=anc[ti->se];
					anc[ti->se]=lca;
					s.insert(pii(dfn[lca],lca));
				}
				if(fa!=lca)
				{
					rep[lca]++;
					anc[fa]=lca;
					s.insert(pii(dfn[fa],fa));
				}
			}
			rep[fa]++;
		}
		else
		{
			vis[a]=0;
			rep[fa]--;
			assert(s.count(pii(dfn[fa],fa)));
			while(!rep[fa])
			{
				int lca=anc[fa];
				// printf("a:%d b:%d lca:%d\n",fa,it->se,lca);
				// int sn=getkf(fa,dep[fa]-dep[lca]-1);
				ans-=psm[fa]-psm[lca];
				s.erase(pii(dfn[fa],fa));
				rep[anc[fa]]--;
				fa=anc[fa];
			}
		}
		// for(int i=0;i<=n;i++)
		// 	printf("i:%d rep:%d\n",i,rep[i]);
		printf("%lld\n",ans);
	}
	return 0;
}