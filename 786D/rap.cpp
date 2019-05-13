//2019.05.12
//CF786D Rap God 点分树+二分哈希判字典序
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define inf 0x7F7F7F7F
#define li long long
#define pii pair<int,int>
#define ppi pair<pii,int>
#define fi first
#define se second
#define mod1 1000000007
#define mod2 1000000009
#define base 619
using namespace std;
pii operator *(pii a,pii b){return pii((li)a.fi*b.fi%mod1,(li)a.se*b.se%mod2);}
pii operator +(pii a,pii b){return pii((a.fi+b.fi)%mod1,(a.se+b.se)%mod2);}
pii operator -(pii a,pii b){return pii((a.fi-b.fi+mod1)%mod1,(a.se-b.se+mod2)%mod2);}
pii operator *(pii a,int v){return pii((li)a.fi*v%mod1,(li)a.se*v%mod2);}
pii operator +(pii a,int v){return pii((a.fi+v)%mod1,(a.se+v)%mod2);}
pii operator -(pii a,int v){return pii((a.fi-v+mod1)%mod1,(a.se-v+mod2)%mod2);}
struct node
{
	int o[27],rep,rnk,ed;
	node()
	{
		memset(o,0,sizeof(o));
		ed=rep=rnk=0;
	}
};
int n,m,tot,mn,rt;
int hd[20009],eg[40009],nxt[40009],ch[40009];
int dep[20009],sz[20009],vis[20009],num[20009];
int f[20009][15];
int fat[20009];
pii mul[20009],inv[20009];
pii hs1[20009],hs2[20009];//hs1: 1 to n, hs2: n to 1
vector<node> tr0[20009],tr1[20009];
vector<ppi > ths0[20009],ths1[20009];
void ins(int a,int b,int c)
{
	eg[++tot]=b;
	ch[tot]=c;
	nxt[tot]=hd[a];
	hd[a]=tot;
}
int qpow(int a,int b,int mod)
{
	int ans=1;
	for(;b;b>>=1,a=(li)a*a%mod)
		if(b&1)
			ans=(li)ans*a%mod;
	return ans;
}
void init()
{
	mul[0]=pii(1,1);
	for(int i=1;i<=n;i++)
		mul[i]=mul[i-1]*base;
	inv[n]=pii(qpow(mul[n].fi,mod1-2,mod1),qpow(mul[n].se,mod2-2,mod2));
	for(int i=n-1;i>=0;i--)
		inv[i]=inv[i+1]*base;
}
void dfs1(int x,int fa,int c)
{
	dep[x]=dep[fa]+1;
	hs1[x]=hs1[fa]+mul[dep[x]]*c;
	hs2[x]=hs2[fa]*base+c;
	num[x]=c;
	f[x][0]=fa;
	for(int i=1;i<=14;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int i=hd[x];i;i=nxt[i])
		if(eg[i]!=fa)
			dfs1(eg[i],x,ch[i]);
}
int getlca(int a,int b)
{
	if(dep[a]<dep[b])
		swap(a,b);
	int l=dep[a]-dep[b];
	for(int i=0;i<=14;i++)
		if(l&(1<<i))
			a=f[a][i];
	if(a==b)
		return a;
	for(int i=14;i>=0;i--)
		if(f[a][i]!=f[b][i])
			a=f[a][i],b=f[b][i];
	return f[a][0];
}
pii geths(int u,int v,int lca,int len)//get the hash value from u to v,with length of len
{
	if(len<=dep[u]-dep[lca])
	{
		int fu=u;
		for(int i=0;i<=14;i++)
			if(len&(1<<i))
				fu=f[fu][i];
		return hs2[u]-hs2[fu]*mul[len];
	}
	pii lans=hs2[u]-hs2[lca]*mul[dep[u]-dep[lca]];
	int rlen=dep[u]+dep[v]-2*dep[lca]-len;
	int fv=v;
	for(int i=0;i<=14;i++)
		if(rlen&(1<<i))
			fv=f[fv][i];
	pii rans=(hs1[fv]-hs1[lca])*inv[dep[lca]+1]*mul[dep[u]-dep[lca]];
	return lans+rans;
}
int getx(int u,int v,int lca,int len,int typ)//get the len'th node from u to v
{
	if(len>dep[u]+dep[v]-2*dep[lca])
		return 0;
	if(len<=dep[u]-dep[lca])
	{
		len=len-1+typ;
		int fu=u;
		for(int i=0;i<=14;i++)
			if(len&(1<<i))
				fu=f[fu][i];
		return fu;
	}
	len=dep[u]+dep[v]-2*dep[lca]-len;
	int fv=v;
	for(int i=0;i<=14;i++)
		if(len&(1<<i))
			fv=f[fv][i];
	return fv;
}
int cmpstr(int u1,int v1,int u2,int v2,int len)//1<2:-1 1=2:0 1>2:1
{
	int lca1=getlca(u1,v1),lca2=getlca(u2,v2);
	int len1=dep[u1]+dep[v1]-2*dep[lca1],len2=dep[u2]+dep[v2]-2*dep[lca2];
	len=min(len,max(len1,len2));
	if(len==0)
		return 0;
	int l=0,r=min(len,min(len1,len2));//find the longest length of 1 2 the same
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(geths(u1,v1,lca1,mid)==geths(u2,v2,lca2,mid))
			l=mid;
		else
			r=mid-1;
	}
	if(l==len)//all the same
		return 0;
	int c1=num[getx(u1,v1,lca1,l+1,0)];
	int c2=num[getx(u2,v2,lca2,l+1,0)];
	if(c1==c2)
		return 0;
	return c1<c2?-1:1;
}
void getrt(int x,int fa,int siz)
{
	int mx=0;
	sz[x]=1;
	for(int i=hd[x];i;i=nxt[i])
		if(eg[i]!=fa&&!vis[eg[i]])
		{
			getrt(eg[i],x,siz);
			mx=max(mx,sz[eg[i]]);
			sz[x]+=sz[eg[i]];
		}
	mx=max(mx,siz-sz[x]);
	if(mx<mn)
	{
		mn=mx;
		rt=x;
	}
}
void dfs2(int x,int fa,int cur,vector<node> &tr)//build trie using dfs
{
	for(int i=hd[x];i;i=nxt[i])
		if(eg[i]!=fa&&!vis[eg[i]])
		{
			int &np=tr[cur].o[ch[i]];
			if(!np)
				np=tr.size(),tr.push_back(node());
			// if(n!=100||m!=85)
			// if(np>=tr.size())
			// {
			// 	printf("mdzz cur:%d np:%d size:%d",cur,np,(int)tr.size());
			// 	exit(2333);
			// }
			int npp=tr[cur].o[ch[i]];
			tr[npp].rep++;
			dfs2(eg[i],x,npp,tr);
		}
}
void dfs3(int cur,vector<node> &tr,int &sm,int d,pii hs,vector<ppi> &ths)//get hash & rank using trie
{
	node &p=tr[cur];
	p.ed=p.rnk=(sm+=p.rep);
	ths.push_back(ppi(hs,cur));
	for(int i=1;i<=26;i++)
		if(p.o[i])
		{
			dfs3(p.o[i],tr,sm,d+1,hs+mul[d]*i,ths);
			p.ed=max(p.ed,tr[p.o[i]].ed);
		}
}
void cal(int x,int typ,int fromc)
{
	int sm=0;
	if(typ==0)
	{
		node tmp;
		tmp.rep=1;
		tr0[x].push_back(tmp);
		dfs2(x,0,0,tr0[x]);
		dfs3(0,tr0[x],sm,0,pii(0,0),ths0[x]);
	}
	else
	{
		node tmp;
		tmp.o[fromc]=1;
		tr1[typ].push_back(tmp);
		tmp.o[fromc]=0;
		tmp.rep=1;
		tr1[typ].push_back(tmp);
		dfs2(x,0,1,tr1[typ]);
		dfs3(0,tr1[typ],sm,0,pii(0,0),ths1[typ]);
		// ths1[typ].push_back(ppi(pii(0,0),0));
	}
}
void solve(int x,int siz)
{
	vis[x]=1;
	cal(x,0,0);
	for(int i=hd[x];i;i=nxt[i])
		if(!vis[eg[i]])
		{
			int nsz=sz[eg[i]]>sz[x]?siz-sz[x]:sz[eg[i]];
			mn=inf;
			getrt(eg[i],0,nsz);
			cal(eg[i],rt,ch[i]);
			fat[rt]=x;
			solve(rt,nsz);
		}
	sz[x]=siz;
}
int getsm(int c,int u,int v,vector<node> &tr,vector<ppi> &ths,int siz)
{//find number of strings that is less than u to v on center c
	int len=dep[u]+dep[c]-2*dep[getlca(u,c)];
	int res=cmpstr(u,v,u,c,len);
	if(res==1)
		return siz;
	if(res==-1)
		return 0;
	int nu=getx(u,v,getlca(u,v),len,1);
	int nlca=getlca(nu,v);
	int l=0,r=dep[nu]+dep[v]-2*dep[nlca];
	// printf("c:%d u:%d v:%d len:%d nu:%d l:%d r:%d ",c,u,v,len,nu,l,r);
	vector<ppi>::iterator it;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		pii t=geths(nu,v,nlca,mid);
		it=lower_bound(ths.begin(),ths.end(),ppi(t,-1));
		if(it!=ths.end()&&it->fi==t)
			l=mid;
		else
			r=mid-1;
	}
	int p=lower_bound(ths.begin(),ths.end(),ppi(geths(nu,v,nlca,l),-1))->se;
	// printf("ans:%d p:%d\n",l,p);
	if(l==dep[nu]+dep[v]-2*dep[nlca])
		return /* cerr<<1, */tr[p].rnk-tr[p].rep;
	int id=num[getx(nu,v,nlca,l+1,0)];
	// printf("id:%d\n",id);
	for(int i=id;i>=1;i--)
		if(tr[p].o[i])
			return /* cerr<<2, */tr[tr[p].o[i]].ed;
	return /* cerr<<3, */tr[p].rnk;
}
void getans(int x,int y)
{
	int ans=0;
	for(int p=x,q=0;p;q=p,p=fat[p])
	{
		// printf("x:%d y:%d p:%d q:%d---------------------------------------\n",x,y,p,q);
		ans+=getsm(p,x,y,tr0[p],ths0[p],sz[p]);
		// printf("ans1:%d-----------------------\n",ans);
		if(q)
			ans-=getsm(p,x,y,tr1[q],ths1[q],sz[q]);
		// printf("ans2:%d-----------------------\n",ans);
	}
	printf("%d\n",ans-1);
}
void dbg()
{
	// freopen("/dev/pts/1","r",stdin);
	// freopen("/dev/pts/1","w",stdout);
	for(int i=1;i<=n;i++)
		printf("i:%d dep:%d sz:%d num:%d fat:%d\n",i,dep[i],sz[i],num[i],fat[i]);
	// for(int i=1,a,b,c,d,e;i<=m;i++)
	// {
	// 	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	// 	printf("u1:%d v1:%d u2:%d v2:%d len:%d cmp:%d\n",a,b,c,d,e,cmpstr(a,b,c,d,e));
	// }
}
void dbg2()
{
	for(int i=0;i<(int)tr1[9].size();i++)
		printf("i:%d rep:%d rnk:%d\n",i,tr1[9][i].rep,tr1[9][i].rnk);
	for(int i=0;i<(int)ths1[9].size();i++)
		printf("i:%d fi:%d se:%d id:%d\n",i,ths1[9][i].fi.fi,ths1[9][i].fi.se,ths1[9][i].se);
}
void dbg3()
{
	printf("geths:%d\n",geths(3,2,2,1));
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("rap.in","r",stdin);
	freopen("rap.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=n-1;i++)
	{
		char s[2];
		scanf("%d%d%s",&a,&b,s);
		ins(a,b,s[0]-'a'+1);
		ins(b,a,s[0]-'a'+1);
	}
	init();
	dep[0]=-1;
	dfs1(1,0,0);
	mn=inf;
	getrt(1,0,n);
	solve(rt,n);
	// dbg();
	for(int i=1;i<=n;i++)
	{
		sort(ths0[i].begin(),ths0[i].end());
		sort(ths1[i].begin(),ths1[i].end());
	}
	// dbg2();
	// dbg3();
	for(int i=1,a,b;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		getans(a,b);
	}
	return 0;
}