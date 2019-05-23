//2019.05.23
//CF1131G Most Dangerous Shark 单调栈+序列dp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define gc() (p1==p2&&(p2=(p1=buffer)+fread(buffer,1,10000000,stdin),p1==p2)?EOF:*p1++)
#define fi first
#define se second
#define li long long
#define pil pair<int,li>
using namespace std;
char *p1,*p2,buffer[10000009];
int n,m;
vector<int> blh[250009],blc[250009];
int h[10000009];
li c[10000009];
int rp[10000009],lp[10000009];
int st[10000009];
li f[10000009];
void rd(int &x)
{
	char ch=0;
	x=0;
	while(ch<'0'||ch>'9')
		ch=gc();
	while(ch>='0'&&ch<='9')
		x=x*10+(ch&15),ch=gc();
}
void init()
{
	int tp=0;
	for(int i=1;i<=m;i++)
	{
		lp[i]=i;
		while(tp&&i-st[tp]<h[i])
			lp[i]=min(lp[i],lp[st[tp--]]);
		st[++tp]=i;
	}
	tp=0;
	for(int i=m;i>=1;i--)
	{
		rp[i]=i;
		while(tp&&st[tp]-i<h[i])
			rp[i]=max(rp[i],rp[st[tp--]]);
		st[++tp]=i;
	}
}
void init1()//an alternative init
{
	int tp=0;
	for(int i=1;i<=m;i++)
	{
		while(tp&&h[st[tp]]<=i-st[tp])
			rp[st[tp--]]=i-1;
		st[++tp]=i;
	}
	while(tp)
		rp[st[tp--]]=m;
	for(int i=m;i>=1;i--)
	{
		while(tp&&h[st[tp]]<=st[tp]-i)
			lp[st[tp--]]=i+1;
		st[++tp]=i;
	}
	while(tp)
		lp[st[tp--]]=1;
}
void solve()
{
	int tp=0;
	memset(f,0x7F,sizeof(f));
	f[0]=0;
	for(int i=1;i<=m;i++)
	{
		f[i]=f[lp[i]-1]+c[i];
		while(tp&&rp[st[tp]]<i)
			tp--;
		if(tp)
			f[i]=min(f[i],f[st[tp]-1]+c[st[tp]]);
		if(!tp||f[i-1]+c[i]<f[st[tp]-1]+c[st[tp]])
			st[++tp]=i;
	}
	cout<<f[m];
}
void dbg()
{
	for(int i=1;i<=m;i++)
		printf("i:%d h:%d c:%lld lp:%d rp:%d f:%lld\n",i,h[i],c[i],lp[i],rp[i],f[i]);
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("domino.in","r",stdin);
	freopen("domino.out","w",stdout);
#endif
	rd(n),rd(m);
	for(int i=1,a,b;i<=n;i++)
	{
		rd(a);
		for(int j=1;j<=a;j++)
			rd(b),blh[i].push_back(b);
		for(int j=1;j<=a;j++)
			rd(b),blc[i].push_back(b);
	}
	int q,cur=0;
	rd(q);
	for(int i=1,a,b;i<=q;i++)
	{
		rd(a),rd(b);
		for(int j=0;j<(int)blh[a].size();j++)
			h[++cur]=blh[a][j],c[cur]=(li)blc[a][j]*b;
	}
	init1();
	solve();
	// dbg();
	return 0;
}