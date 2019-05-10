//2019.05.10
//CF704E Iron Man 树链剖分+扫描线+set维护前驱后继
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#define db double
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
struct node
{
	int stp,vel;
	db stt,edt;
	node(){}
	node(int a,int b,db c,db d){stp=a,vel=b,stt=c,edt=d;}
};
struct event
{
	int typ,id;
	db tme;
	event(){}
	event(int a,int b,db c){typ=a,id=b,tme=c;}
	bool operator <(const event &p) const
	{
		return tme<p.tme||(tme==p.tme&&typ<p.typ);
	}
};
int n,m,tot;
int hd[100009],eg[200009],nxt[200009];
int f[100009][19];
int dep[100009],son[100009],sz[100009],top[100009],bson[100009];
vector<node> qry[100009];
void ins(int a,int b)
{
	eg[++tot]=b;
	nxt[tot]=hd[a];
	hd[a]=tot;
}
void dfs1(int x,int fa)
{
	sz[x]=1;
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=18;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int i=hd[x];i;i=nxt[i])
		if(eg[i]!=fa)
		{
			dfs1(eg[i],x);
			sz[x]+=sz[eg[i]];
			if(sz[eg[i]]>sz[son[x]])
				son[x]=eg[i];
		}
	bson[son[x]]=1;
}
void dfs2(int x,int tp)
{
	top[x]=tp;
	if(son[x])
		dfs2(son[x],tp);
	for(int i=hd[x];i;i=nxt[i])
		if(eg[i]!=f[x][0]&&eg[i]!=son[x])
			dfs2(eg[i],eg[i]);
}
int getlca(int a,int b)
{
	if(dep[a]<dep[b])
		swap(a,b);
	int l=dep[a]-dep[b];
	for(int i=0;i<=18;i++)
		if(l&(1<<i))
			a=f[a][i];
	if(a==b)
		return a;
	for(int i=18;i>=1;i--)
		if(f[a][i]!=f[b][i])
			a=f[a][i],b=f[b][i];
	return f[a][0];
}
db solve(vector<node> &v)
{
	db ans=1e300;
	vector<event> e;
	for(int i=0;i<(int)e.size();i++)
	{
		e.push_back(event(0,i,v[i].stt));
		e.push_back(event(1,i,v[i].edt));
	}
	sort(e.begin(),e.end());
	set<pii> s;
	set<pii>::iterator it1,it2;
	for(int i=0;i<(int)e.size();i++)
	{
		if(e[i].typ==0)
		{
			int id=e[i].id;
			it1=it2=s.insert(pii(v[id].stp,id)).fi;
			if(it1!=s.begin())
			{
				it1--;
				int p=it1->se;
				
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=n-1;i++)
		scanf("%d%d",&a,&b),ins(a,b),ins(b,a);
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1,a,b,c,d;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);

	}
	return 0;
}