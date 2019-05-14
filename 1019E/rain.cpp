//2019.05.14
//CF1019E Raining season 辅助点+点分治+凸包闵可夫斯基和
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cassert>
#include<cmath>
#define gc() (p1==p2&&(p2=(p1=buffer)+fread(buffer,1,10000000,stdin),p1==p2)?EOF:*p1++)
#define inf 0x7F7F7F7F
#define li long long
#define i128 __float128
#define db double
#define ldb long double
#define eps 1e-12l
using namespace std;
struct pt
{
	li x,y;
	pt(){}
	pt(li a,li b){x=a,y=b;}
	bool operator <(const pt &p) const{return x<p.x||(x==p.x&&y<p.y);}
	bool operator ==(const pt &p) const{return x==p.x&&y==p.y;}
	pt operator +(pt p){return pt(x+p.x,y+p.y);}
	pt operator -(pt p){return pt(x-p.x,y-p.y);}
	i128 operator ^(pt p){return (i128)x*p.y-(i128)y*p.x;}
	i128 cross(pt p,pt q){return (p-*this)^(q-*this);}
	ldb geta(){return atan2l(-x,y);}
};
char *p1,*p2,buffer[10000009];
int n,m,tot1,tot2,mn,rt;
int hd1[100009],eg1[200009],nxt1[200009],va1[200009],vb1[200009];
int hd2[200009],eg2[400009],nxt2[400009],va2[400009],vb2[400009];
int sz[200009],vis[200009];
vector<pt> res;
void rd(int &x)
{
	char ch=0;
	x=0;
	while(ch<'0'||ch>'9')
		ch=gc();
	while(ch>='0'&&ch<='9')
		x=x*10+(ch&15),ch=gc();
}
void ins1(int a,int b,int c,int d)
{
	eg1[++tot1]=b;
	va1[tot1]=c;
	vb1[tot1]=d;
	nxt1[tot1]=hd1[a];
	hd1[a]=tot1;
}
void ins2(int a,int b,int c,int d)
{
	eg2[++tot2]=b;
	va2[tot2]=c;
	vb2[tot2]=d;
	nxt2[tot2]=hd2[a];
	hd2[a]=tot2;
}
void dfs1(int x,int fa,int &np)
{
	int deg=0;
	for(int i=hd1[x];i;i=nxt1[i])
		if(eg1[i]!=fa)
		{
			dfs1(eg1[i],x,np);
			deg++;
		}
	if(deg<=2)
	{
		for(int i=hd1[x];i;i=nxt1[i])
			if(eg1[i]!=fa)
			{
				ins2(x,eg1[i],va1[i],vb1[i]);
				ins2(eg1[i],x,va1[i],vb1[i]);
			}
	}
	else
	{
		int lst=x;
		for(int i=hd1[x];i;i=nxt1[i])
			if(eg1[i]!=fa)
			{
				ins2(lst,eg1[i],va1[i],vb1[i]);
				ins2(eg1[i],lst,va1[i],vb1[i]);
				np++;
				ins2(lst,np,0,0);
				ins2(np,lst,0,0);
				lst=np;
			}
	}
}
template<class T>
int sgn(T x)
{
	return x<0?-1:(x>0?1:0);
}
template<class T>
void output(T x)
{
	if(x>=10)
		output(x/10);
	putchar(x%10+'0');
}
vector<pt> getcv(vector<pt> p)//get convex hull of p
{
	sort(p.begin(),p.end());
	int l=unique(p.begin(),p.end())-p.begin();
	p.resize(l);
	if(p.size()<=2)
		return p;
	vector<pt> ans(p.size()+10);
	int tp=-1;
	for(int i=0;i<(int)p.size();i++)
	{
		while(tp>0&&ans[tp-1].cross(ans[tp],p[i])<=0)
			tp--;
		ans[++tp]=p[i];
	}
	int tmp=tp;
	// printf("tp:%d\n",tp);
	for(int i=(int)p.size()-2;i>=0;i--)
	{
		while(tp>tmp&&ans[tp-1].cross(ans[tp],p[i])<=0)
			tp--;
		ans[++tp]=p[i];
	}
	// assert(tp>0);
	ans.resize(tp);
	return ans;
}
vector<pt> mrg(vector<pt> a,vector<pt> b)//merge a and b
{
	a.insert(a.end(),b.begin(),b.end());
	return getcv(a);
}
int sgnl(ldb x)
{
	return x<-eps?-1:(x>eps?1:0);
}
int cmp(pt a,pt b)//-1:a<b 0:a=b 1:a>b
{
	ldb p1=a.geta(),p2=b.geta();
	return sgn(p1-p2);
}
vector<pt> getsm(vector<pt> a,vector<pt> b)//minkowski sum of convex a and b
{
	vector<pt> ans;
	if(a.size()>b.size())
		a.swap(b);
	if(a.empty())
		return b;
	if((int)a.size()==1)
	{
		for(int i=0;i<(int)b.size();i++)
			b[i]=b[i]+a[0];
		return b;
	}
	int lp=0,rp=0;
	a.push_back(a[0]),b.push_back(b[0]);
	while(lp<(int)a.size()-1||rp<(int)b.size()-1)
	{
		ans.push_back(a[lp]+b[rp]);
		if(lp==(int)a.size()-1)
			rp++;
		else if(rp==(int)b.size()-1)
			lp++;
		else
		{
			int t=cmp(a[lp+1]-a[lp],b[rp+1]-b[rp]);
			if(t==0)
				lp++,rp++;
			else if(t==-1)
				lp++;
			else
				rp++;
		}
	}
	return ans;
}
void getrt(int x,int fa,int siz)
{
	int mx=0;
	sz[x]=1;
	for(int i=hd2[x];i;i=nxt2[i])
		if(!vis[eg2[i]]&&eg2[i]!=fa)
		{
			getrt(eg2[i],x,siz);
			sz[x]+=sz[eg2[i]];
			mx=max(mx,sz[eg2[i]]);
		}
	mx=max(mx,siz-sz[x]);
	if(mx<mn)
		mn=mx,rt=x;
}
void dfs2(int x,int fa,li sma,li smb,vector<pt> &v)
{
	v.push_back(pt(sma,smb));
	for(int i=hd2[x];i;i=nxt2[i])
		if(!vis[eg2[i]]&&eg2[i]!=fa)
			dfs2(eg2[i],x,sma+va2[i],smb+vb2[i],v);
}
void cal(int x)
{
	// printf("center x:%d+++++++++++++++++++++++++++++++++++++++++\n",x);
	vector<pt> p,np;
	p.push_back(pt(0,0));
	for(int i=hd2[x];i;i=nxt2[i])
		if(!vis[eg2[i]])
		{
			p=mrg(p,np);
			// printf("eg:%d\n",eg2[i]);
			np.resize(0);
			dfs2(eg2[i],0,va2[i],vb2[i],np);
			np=getcv(np);
			// for(int i=0;i<(int)np.size();i++)
			// 	printf("i:%d npx:%I64d npy:%I64d\n",i,np[i].x,np[i].y);
			vector<pt> tmp=getsm(p,np);
			// for(int i=0;i<(int)tmp.size();i++)
			// 	printf("i:%d tmpx:%I64d tmpy:%I64d\n",i,tmp[i].x,tmp[i].y);
			res.insert(res.end(),tmp.begin(),tmp.end());
		}
	// for(int i=0;i<(int)p.size();i++)
	// 	printf("i:%d x:%I64d y:%I64d\n",i,p[i].x,p[i].y);
}
void solve(int x,int siz)
{
	vis[x]=1;
	cal(x);
	for(int i=hd2[x];i;i=nxt2[i])
		if(!vis[eg2[i]])
		{
			int nsz=sz[eg2[i]]>sz[x]?siz-sz[x]:sz[eg2[i]];
			mn=inf;
			getrt(eg2[i],0,nsz);
			solve(rt,nsz);
		}
}
void getans()
{
	res.push_back(pt(0,0));
	res=getcv(res);
	res.push_back(res[0]);
	reverse(res.begin(),res.end());
	res.pop_back();
	// printf("res*************************************************************\n");
	// for(int i=0;i<(int)res.size();i++)
	// 	printf("i:%d x:%I64d y:%I64d\n",i,res[i].x,res[i].y);
	int p=0;
	for(int i=0;i<=m-1;i++)
	{
		while(p<(int)res.size()-1&&res[p+1].x>=res[p].x&&
		(i128)(res[p+1].y-res[p].y)>=(i128)(res[p+1].x-res[p].x)*-i)
			p++;
		output(res[p].x*i+res[p].y);
		printf(" ");
	}
}
void dbg1(int x,int fa)
{
	printf("x:%d---------------------\n",x);
	for(int i=hd2[x];i;i=nxt2[i])
		if(eg2[i]!=fa)
			printf("eg:%d va:%d vb:%d\n",eg2[i],va2[i],vb2[i]);
	for(int i=hd2[x];i;i=nxt2[i])
		if(eg2[i]!=fa)
			dbg1(eg2[i],x);
}
void test()
{
	printf("\n%lf\n",atan2(0,-1));
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("rain.in","r",stdin);
	freopen("rain.out","w",stdout);
#endif
	rd(n),rd(m);
	if(n==1)
	{
		for(int i=0;i<=m-1;i++)
			puts("0");
		return 0;
	}
	for(int i=1,a,b,c,d;i<=n-1;i++)
	{
		rd(a),rd(b),rd(c),rd(d);
		ins1(a,b,c,d);
		ins1(b,a,c,d);
	}
	int np=n;
	dfs1(1,0,np);
	// dbg1(1,0);
	n=np;
	mn=inf;
	getrt(1,0,n);
	solve(rt,n);
	getans();
	// test();
	return 0;
}