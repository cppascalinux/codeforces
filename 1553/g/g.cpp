#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mod 1000003
#define ll long long
using namespace std;
struct node
{
	int u,v,id;
	int hash()
	{
		return ((ll)u*129834724+v)%mod;
	}
};
int n,m,q,tot,sme;
int pm[1000009],np[1000009];
int s[150009];
int vis[1000009];
int f[1000009];
vector<int> fv[1000009],ps[1000009];
int bel[1000009];
int hd[mod],nxt[300009];
node eg[300009];
int dupe[300009];
int ans[300009];
int tmp[1000009];
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
void init()
{
	for(int i=2;i<=m;i++)
	{
		if(!np[i])
			pm[++tot]=i;
		for(int j=1;j<=tot&&i*pm[j]<=m;j++)
		{
			np[i*pm[j]]=1;
			if(i%pm[j]==0)
				break;
		}
	}
}
void add(node t)
{
	int h=t.hash();
	eg[++sme]=t;
	nxt[sme]=hd[h];
	hd[h]=sme;
}
int ask(pii p)
{
	int h=node{p.fi,p.se,0}.hash();
	for(int i=hd[h];i;i=nxt[i])
		if(eg[i].u==p.fi&&eg[i].v==p.se)
			return eg[i].id;
	return 0;
}
void clr(vector<int> &s)
{
	vector<int> tmp;
	tmp.swap(s);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",s+i);
		vis[s[i]]=1;
		m=max(m,s[i]+1);
	}
	init();
	for(int i=1;i<=m;i++)
		f[i]=i;
	for(int i=1;i<=tot;i++)
	{
		int ft=0;
		for(int j=pm[i];j<=m;j+=pm[i])
		{
			if(vis[j]||vis[j-1])
				fv[j].push_back(pm[i]);
			if(!ft&&vis[j])
			{
				// printf("1 i:%d j:%d\n",pm[i],j);
				ft=fnd(j);
				ps[ft].push_back(pm[i]);
				bel[pm[i]]=ft;
			}
			else if(vis[j])
			{
				// printf("2 i:%d j:%d\n",pm[i],j);
				int fa=fnd(ft),fb=fnd(j);
				if(fa!=fb)
				{
					if(ps[fb].size()>ps[fa].size())
						swap(fa,fb);
					for(int v:ps[fb])
					{
						bel[v]=fa;
						ps[fa].push_back(v);
					}
					clr(ps[fb]);
					f[fb]=fa;
					ft=fa;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
		clr(ps[i]);
	map<pii,int> mp;
	for(int i=1;i<=q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a=s[a],b=s[b];
		int fa=fnd(a),fb=fnd(b);
		if(fa==fb)
			ans[i]=0;
		else
		{
			if(fa>fb)
				swap(fa,fb);

			dupe[i]=mp[pii(fa,fb)];
			mp[pii(fa,fb)]=i;
			ans[i]=2;
			if(!dupe[i])
				add(node{fa,fb,i});
		}
	}
	for(int i=1;i<=m;i++)
	{
		fv[i].shrink_to_fit();
	}
	for(int i=1;i<=n;i++)
	{
		int tp=0;
		for(int v:fv[s[i]])
			if(bel[v])
				tmp[++tp]=bel[v];
		for(int v:fv[s[i]+1])
			if(bel[v])
				tmp[++tp]=bel[v];
		sort(tmp+1,tmp+tp+1);
		int d=unique(tmp+1,tmp+tp+1)-tmp-1;
		for(int i=1;i<=d;i++)
			for(int j=i+1;j<=d;j++)
				ans[ask(pii(tmp[i],tmp[j]))]=1;
	}
	for(int i=1;i<=q;i++)
	{
		if(dupe[i])
			ans[i]=ans[dupe[i]];
		printf("%d\n",ans[i]);
	}
	return 0;
}