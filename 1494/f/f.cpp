#include<bits/stdc++.h>
using namespace std;
int n,m,tot=1;
int deg[3009];
int hd[3009],eg[4500009],nxt[4500009];
int f[3009],sz[3009];
int vis[4500009];
vector<int> ans,tmp;
void adde(int a,int b)
{
	eg[++tot]=b;
	nxt[tot]=hd[a];
	hd[a]=tot;
}
void dfs(int x)
{
	for(int &i=hd[x];i;i=nxt[i])
		if(!vis[i])
		{
			vis[i]=vis[i^1]=1;
			dfs(eg[i]);
		}
	tmp.push_back(x);
}
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
int judge()
{
	for(int i=1;i<=n;i++)
		f[i]=i,sz[i]=1;
	for(int i=1;i<=n;i++)
		for(int j=hd[i];j;j=nxt[j])
			if(!vis[j])
			{
				int fa=fnd(i),fb=fnd(eg[j]);
				if(fa!=fb)
					f[fa]=fb,sz[fb]+=sz[fa];
			}
	int tl=0;
	for(int i=1;i<=n;i++)
		if(fnd(i)==i&&sz[i]>1)
			tl++;
	return tl<=1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		adde(a,b),adde(b,a);
		deg[a]++,deg[b]++;
	}
	int sm=0,tm=0;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]&1)
			sm++;
		if(deg[i]>1)
			tm++;
	}
	int fg=0;
	if(sm==0)
		fg=1;
	else if(sm==2)
	{
		for(int i=1;i<=n;i++)
			if(deg[i]&1)
				fg=i;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			int t=0;
			for(int j=hd[i];j;j=nxt[j])
				if(deg[eg[j]]&1)
					t++;
			if(deg[i]&1)
			{
				if(t==sm-2)
				{
					for(int j=hd[i];j;j=nxt[j])
						if(deg[eg[j]]&1)
							vis[j]=vis[j^1]=1;
					if(judge())
					{
						for(int j=hd[i];j;j=nxt[j])
							if(vis[j])
								ans.push_back(i),ans.push_back(eg[j]);
						fg=i;
						break;
					}
					for(int j=hd[i];j;j=nxt[j])
						vis[j]=vis[j^1]=0;
				}
				else if(t==sm-1)
				{
					for(int j=hd[i];j;j=nxt[j])
						if(deg[eg[j]]&1)
							vis[j]=vis[j^1]=1;
					for(int j=hd[i];j;j=nxt[j])
						if(vis[j])
						{
							vis[j]=vis[j^1]=0;
							if(judge())
							{
								for(int k=hd[i];k;k=nxt[k])
									if(vis[k])
										ans.push_back(i),ans.push_back(eg[k]);
								fg=i;
								break;
							}
							vis[j]=vis[j^1]=1;
						}
					if(fg)
						break;
				}
			}
			else
			{
				if(t==sm-1)
				{
					for(int j=hd[i];j;j=nxt[j])
						if(deg[eg[j]]&1)
							vis[j]=vis[j^1]=1;
					if(judge())
					{
						for(int j=hd[i];j;j=nxt[j])
							if(vis[j])
								ans.push_back(i),ans.push_back(eg[j]);
						fg=i;
						break;
					}
					for(int j=hd[i];j;j=nxt[j])
						vis[j]=vis[j^1]=0;
				}
				else if(t==sm)
				{
					for(int j=hd[i];j;j=nxt[j])
						if(deg[eg[j]]&1)
							vis[j]=vis[j^1]=1;
					for(int j=hd[i];j;j=nxt[j])
						if(vis[j])
						{
							vis[j]=vis[j^1]=0;
							if(judge())
							{
								for(int k=hd[i];k;k=nxt[k])
									if(vis[k])
										ans.push_back(i),ans.push_back(eg[k]);
								fg=i;
								break;
							}
							vis[j]=vis[j^1]=1;
						}
					if(fg)
						break;
				}
			}
		}
		ans.push_back(-1);
		reverse(ans.begin(),ans.end());
	}
	if(!fg)
		return printf("0"),0;
	dfs(fg);
	ans.insert(ans.begin(),tmp.begin(),tmp.end());
	printf("%d\n",(int)ans.size());
	for(int v:ans)
		printf("%d ",v);
	return 0;
}