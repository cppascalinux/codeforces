#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
int n,rt,fl;
int deg[200009],sl[200009],sn[200009];
vector<int> g[200009];
vector<pii> ans;
void dfs(int x,int fa)
{
	// printf("x:%d fa:%d\n",x,fa);
	vector<int> s0,s1;
	for(int v:g[x])
		if(v!=fa)
		{
			dfs(v,x);
			// printf("v:%d sl:%d sn:%d\n",v,sl[v],sn[v]);
			if(fl)
				return;
			if(sl[v]==0)
				s0.push_back(v);
			else
				s1.push_back(v);
		}
	if(fa==0)
	{
		if(s0.empty())
		{
			fl=1;
			return;
		}
		ans.emplace_back(x,s0[0]);
		return;
	}
	if(s0.size()==s1.size()+2)
	{
		ans.emplace_back(x,s0.back());
		s0.pop_back();
		while(!s1.empty())
		{
			int tv=s1.back();
			ans.emplace_back(x,tv);
			ans.emplace_back(tv,sn[tv]);
			s1.pop_back();
			tv=s0.back();
			ans.emplace_back(x,tv);
			s0.pop_back();
		}
		sl[x]=1;
		sn[x]=s0[0];
		return;
	}
	if(s0.size()==s1.size()+1)
	{
		while(!s1.empty())
		{
			int tv=s1.back();
			ans.emplace_back(x,tv);
			ans.emplace_back(tv,sn[tv]);
			s1.pop_back();
			tv=s0.back();
			ans.emplace_back(x,tv);
			s0.pop_back();
		}
		sl[x]=1;
		sn[x]=s0[0];
		return;
	}
	if(s0.size()==s1.size())
	{
		while(!s1.empty())
		{
			int tv=s0.back();
			ans.emplace_back(x,tv);
			s0.pop_back();
			tv=s1.back();
			ans.emplace_back(x,tv);
			ans.emplace_back(tv,sn[tv]);
			s1.pop_back();
		}
		sl[x]=0;
		return;
	}
	if(s0.size()+1==s1.size())
	{
		while(!s1.empty())
		{
			int tv=s1.back();
			ans.emplace_back(x,tv);
			ans.emplace_back(tv,sn[tv]);
			s1.pop_back();
			if(!s0.empty())
			{
				tv=s0.back();
				ans.emplace_back(x,tv);
				s0.pop_back();
			}
		}
		sl[x]=0;
		return;
	}
	fl=1;
	return;
}
void clr()
{
	fl=rt=0;
	ans.clear();
	for(int i=1;i<=n;i++)
	{
		deg[i]=sl[i]=sn[i]=0;
		g[i].clear();
	}
}
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		for(int i=1,a,b;i<=n-1;i++)
		{
			scanf("%d%d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
			deg[a]++,deg[b]++;
		}
		for(int i=1;i<=n;i++)
			if(deg[i]==1)
				rt=i;
		dfs(rt,0);
		if(fl)
			printf("NO\n");
		else
		{
			printf("YES\n");
			for(pii t:ans)
				printf("%d %d\n",t.first,t.second);
		}
		clr();
	}
	return 0;
}