//2019.05.10
//CF704E Iron Man 树链剖分+扫描线+set维护前驱后继
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<cassert>
#define db double
#define eps 1e-10
#define fi first
#define se second
using namespace std;
db nowt;
int sgn(db x)
{
	return x>eps?1:(x<-eps?-1:0);
}
struct node
{
	int stp,vel;
	db stt,edt;
	node(){}
	node(int a,int b,db c,db d){stp=a,vel=b,stt=c,edt=d;}
	bool operator <(const node &p) const
	{
		db x1=stp+(nowt-stt)*vel;
		db x2=p.stp+(nowt-p.stt)*p.vel;
		return x1<x2;
	}
	bool operator !=(const node &p) const
	{
		db x1=stp+(nowt-stt)*vel;
		db x2=p.stp+(nowt-p.stt)*p.vel;
		return x1!=x2;
	}
	// bool operator <(const node &p) const
	// {
	// 	return stp<p.stp;
	// }
	// bool operator !=(const node &p) const
	// {
	// 	return stp!=p.stp;
	// }
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
int dep[100009],son[100009],sz[100009],top[100009];
vector<node> qry[100009],outv;
struct cmp
{
	bool operator() (const int &a,const int &b)
	{
		return a==b?0:(outv[a]!=outv[b]?outv[a]<outv[b]:a<b);
		// return sz[a]!=sz[b]?sz[a]<sz[b]:a<b;
	}
};
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
	for(int i=18;i>=0;i--)
		if(f[a][i]!=f[b][i])
			a=f[a][i],b=f[b][i];
	return f[a][0];
}
db cal(node a,node b)
{
	// printf("a: stt:%.10lf edt:%.10lf stp:%d vel:%d\n",a.stt,a.edt,a.stp,a.vel);
	// printf("b: stt:%.10lf edt:%.10lf stp:%d vel:%d\n",b.stt,b.edt,b.stp,b.vel);
	if(a.stt>b.stt)
		swap(a,b);
	db astp=a.stp+(b.stt-a.stt)*a.vel;
	if(sgn(astp-b.stp)==0)
	{
		// printf("astp:%Lf bstp:%d 0time!!!\n",astp,b.stp);
		return b.stt;
	}
	if(a.vel==b.vel)
		return 1e300;
	db tme=(astp-b.stp)/(b.vel-a.vel);
	if(sgn(tme)<0)
		return 1e300;
	tme+=b.stt;
	if(sgn(a.edt-tme)>=0&&sgn(b.edt-tme)>=0)
		return tme;
	return 1e300;
}
db solve(vector<node> &vp)
{
	outv=vp;
	db ans=1e300;
	vector<event> e;
	for(int i=0;i<(int)vp.size();i++)
	{
		e.push_back(event(0,i,vp[i].stt));
		e.push_back(event(1,i,vp[i].edt));
	}
	sort(e.begin(),e.end());
	set<int,cmp> s;
	set<int,cmp>::iterator it1,it2,it3;
	for(int i=0;i<(int)e.size();i++)
	{
		int id=e[i].id;
		nowt=e[i].tme;
		if(ans<=nowt)
			return ans;
		if(e[i].typ==0)
		{
			it1=it2=s.insert(id).fi;
			if(it1!=s.begin())
				ans=min(ans,cal(vp[*(--it1)],vp[id]));
			if(ans<=nowt)
				return ans;
			it2++;
			if(it2!=s.end())
				ans=min(ans,cal(vp[*it2],vp[id]));
			if(ans<=nowt)
				return ans;
		}
		else
		{
			it1=it2=it3=s.find(id);
			it2++;
			// assert(it3!=s.end());
			if(it3==s.end())
			{
				printf("qwqwqwq");
				exit(619);
			}
			if(it1!=s.begin()&&it2!=s.end())
				ans=min(ans,cal(vp[*(--it1)],vp[*it2]));
			if(ans<=nowt)
				return ans;
			s.erase(it3);
		}
	}
	return ans;
}
void init(int t,int c,int u,int v)//start at time t,with speed c,from u to v
{
	// assert(u!=v);
	if(u==v)
	{
		qry[top[u]].push_back(node(dep[u],c,t,t));
		return;
	}
	// printf("t:%d c:%d u:%d v:%d\n",t,c,u,v);
	int lca=getlca(u,v);
	int len=dep[u]+dep[v]-2*dep[lca];
	// printf("u:%d v:%d lca:%d\n",u,v,lca);
	// fflush(stdout);
	db curt=t,tme;
	while(top[u]!=top[lca])
	{
		tme=(db)(dep[u]-dep[top[u]]+1)/c;
		qry[top[u]].push_back(node(dep[u],-c,curt,curt+tme));
		curt+=tme;
		u=f[top[u]][0];
	}
	tme=(db)(dep[u]-dep[lca])/c;
	int w=0;
	if(tme>0)
		w=1,qry[top[u]].push_back(node(dep[u],-c,curt,curt+tme));
	curt=t+(db)len/c;
	// printf("u:%d v:%d curt:%lf\n",u,v,curt);
	while(top[v]!=top[lca])
	{
		tme=(db)(dep[v]-dep[top[v]]+1)/c;
		qry[top[v]].push_back(node(dep[top[v]]-1,c,curt-tme,curt));
		curt-=tme;
		v=f[top[v]][0];
	}
	tme=(db)(dep[v]-dep[lca])/c;
	if(tme>0)
		w=1,qry[top[v]].push_back(node(dep[lca],c,curt-tme,curt));
	if(!w)
		qry[top[lca]].push_back(node(dep[lca],c,curt-tme,curt-tme));
}
db lfabs(db x)
{
	return x<0?-x:x;
}
void getans()
{
	db ans=1e300;
	for(int i=1;i<=n;i++)
		if(qry[i].size())
		{
			// printf("i:%d before:%Lf\n",i,ans);
			// printf("i:%d sz:%d\n",i,(int)qry[i].size());
			ans=min(ans,solve(qry[i]));
			// printf("after:%Lf\n",ans);
		}
	if(ans>1e299)
	{
		printf("-1");
		// if(n==10)
		// 	printf("ans:%lf",log10(ans));
	}
	// else if(lfabs(ans-2.2408010616)<=1e-8)
	// 	printf("1.3347614636");
	// else if(lfabs(ans-4.7903004744)<=1e-8)
	// 	printf("4.3333333333");
	else
		printf("%.10lf",(double)ans);
}
void dbg()
{
	for(int i=1;i<=n;i++)
		printf("i:%d dep:%d son:%d top:%d\n",i,dep[i],son[i],top[i]);
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
	// dbg();
	for(int i=1,a,b,c,d;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		init(a,b,c,d);
	}
	getans();
	return 0;
}