#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int n,gl;
vector<int> g[100009],pos[100009],ds[100009];
int deg[100009],dep[100009],sm[100009];
int vl[100009],rep[100009];
int f[100009],lsp[100009],lsv[100009];
int ans[100009];
int out[100009];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	for(int u:g[x])
		if(u!=fa)
			dfs(u,x);
}
int main()
{
	scanf("%d%d",&n,&gl);
	for(int i=2,a;i<=n;i++)
	{
		scanf("%d",&a);
		g[a].pb(i),g[i].pb(a);
		deg[a]++,deg[i]++;
	}
	dfs(1,0);
	int mxd=0;
	for(int i=1;i<=n;i++)
		sm[dep[i]]++,ds[dep[i]].pb(i),mxd=max(mxd,dep[i]);
	for(int i=1;i<=n;i++)
		if(sm[i])
			pos[sm[i]].pb(i);
	map<int,int> mp;
	for(int i=1;i<=n;i++)
		if(sm[i])
			mp[sm[i]]++;
	int tp=0;
	for(auto t:mp)
		vl[++tp]=t.fi,rep[tp]=t.se;
	f[0]=1;
	for(int i=1;i<=tp;i++)
	{
		for(int j=0;j<vl[i];j++)
		{
			int lst=-1;
			for(int k=j;k<=n;k+=vl[i])
			{
				if(f[k])
					lst=k;
				else if(lst!=-1&&(k-lst)/vl[i]<=rep[i])
				{
					f[k]=1;
					lsp[k]=lst;
					lsv[k]=vl[i];
				}
			}
		}
	}
	if(f[gl])
	{
		for(int i=gl;i;i=lsp[i])
		{
			int v=lsv[i];
			int rp=(i-lsp[i])/v;
			for(int j=1;j<=rp;j++)
				ans[pos[v].back()]=1,pos[v].pop_back();
		}
		printf("%d\n",mxd);
		for(int i=1;i<=n;i++)
			printf("%c",ans[dep[i]]?'a':'b');
		return 0;
	}
	int sma=gl,smb=n-gl;
	for(int i=1;i<=mxd;i++)
	{
		if(sm[i]<=sma)
		{
			for(int j:ds[i])
				out[j]=1;
			sma-=sm[i];
			continue;
		}
		if(sm[i]<=smb)
		{
			for(int j:ds[i])
				out[j]=0;
			smb-=sm[i];
			continue;
		}
		int tsm=0;
		for(int j:ds[i])
			if(deg[j]>1)
				tsm++;
		if(tsm<=sma)
		{
			for(int j:ds[i])
				if(deg[j]>1)
					out[j]=1;
			sma-=tsm;
			for(int j:ds[i])
				if(deg[j]==1)
				{
					if(sma)
						out[j]=1,sma--;
					else
						out[j]=0,smb--;
				}
		}
		else
		{
			for(int j:ds[i])
				if(deg[j]>1)
					out[j]=0;
			smb-=tsm;
			for(int j:ds[i])
				if(deg[j]==1)
				{
					if(smb)
						out[j]=0,smb--;
					else
						out[j]=1,sma--;
				}
			continue;
		}
	}
	printf("%d\n",mxd+1);
	for(int i=1;i<=n;i++)
		printf("%c",out[i]?'a':'b');
	return 0;
}