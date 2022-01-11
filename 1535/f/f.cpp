#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod1 1000000007
#define mod2 1000000009
#define base 619
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
pii operator+(pii a,pii b){return pii((a.fi+b.fi)%mod1,(a.se+b.se)%mod2);}
pii operator-(pii a,pii b){return pii((a.fi+mod1-b.fi)%mod1,(a.se+mod2-b.se)%mod2);}
pii operator*(pii a,pii b){return pii((ll)a.fi*b.fi%mod1,(ll)a.se*b.se%mod2);}
pii operator+(pii a,int v){return a+pii(v,v);}
pii operator-(pii a,int v){return a-pii(v,v);}
pii operator*(pii a,int v){return a*pii(v,v);}
int n,m,tot,tp;
char t[200009];
char *s[200009];
pii h0[200009];
pii mul[200009];
pii *h1[200009];
int p[200009],q[200009],rep[200009];
int rt[400009];
int nxt[30000009][2];
ll vl[30000009];
void init()
{
	mul[0]=pii(1,1);
	for(int i=1;i<=m*n;i++)
		mul[i]=mul[i-1]*base;
}
int getpr(int a,int b)
{
	int l=0,r=m;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(h1[a][mid]!=h1[b][mid])
			r=mid-1;
		else
			l=mid;
	}
	return l;
}
bool cmp(int a,int b)
{
	if(h0[a]!=h0[b])
		return h0[a]<h0[b];
	int ln=getpr(a,b);
	return ln<m?s[a][ln+1]<s[b][ln+1]:a<b;
}
void add(int &a,int d,ull v,int r)
{
	int b=a;
	a=++tot;
	vl[a]=vl[b];
	memcpy(nxt[a],nxt[b],sizeof(nxt[a]));
	if(d<63)
		add(nxt[a][(v>>(d+1))&1],d+1,v,r);
	else
		vl[a]+=r;
}
ll ask(int a,int d,ull v)
{
	if(!a)
		return 0;
	if(d<63)
		return ask(nxt[a][v>>(d+1)&1],d+1,v);
	else
		return vl[a];
}
int getmn(int ps,int len)
{
	int l=1,r=ps;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(h0[p[ps]]==h0[p[mid]]&&getpr(p[ps],p[mid])>=len)
			r=mid;
		else
			l=mid+1;
	}
	return l;
}
int getmx(int ps,int len)
{
	int l=ps,r=tp;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(h0[p[ps]]==h0[p[mid]]&&getpr(p[ps],p[mid])>=len)
			l=mid;
		else
			r=mid-1;
	}
	return l;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",t+1);
		m=strlen(t+1);
		s[i]=new char[m+3]();
		for(int j=1;j<=m;j++)
			s[i][j]=t[j]-'a'+1;
		s[i][m+1]=0;
	}
	init();
	map<pii,int> m0,m1;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int sm[27]={0};
		for(int j=1;j<=m;j++)
			sm[s[i][j]]++;
		for(int j=1;j<=26;j++)
			h0[i]=h0[i]*base+sm[j];
		m0[h0[i]]++;
		h1[i]=new pii[m+3]();
		for(int j=1;j<=m;j++)	
			h1[i][j]=h1[i][j-1]*base+s[i][j];
		m1[h1[i][m]]++;
	}
	for(auto t:m0)
		ans+=(ll)t.se*(n-t.se);
	ans/=2;
	ans=(ans*1337)+((ll)n*(n-1)/2-ans)*2;
	for(auto t:m1)
		ans-=(ll)t.se*(t.se-1);
	for(int i=1;i<=n;i++)
		q[i]=i;
	sort(q+1,q+n+1,cmp);
	int lst=0;
	for(int i=1;i<=n;i++)
		if(i==n||h1[q[i]][m]!=h1[q[i+1]][m])
		{
			p[++tp]=q[i];
			rep[tp]=i-lst;
			// if(n==25000&&rep[tp]>n)
			// 	printf("i:%d rep:%d\n",i,rep[tp]);
			lst=i;
		}
	// if(n==25000)
	// 	printf("ans:%lld tp:%d\n",ans,tp);
	for(int j=1;j<=m+1;j++)
	{
		for(int i=1;i<=tp;i++)
		{
			int a=p[i];
			pii ph=h1[a][m]-h1[a][j-1]*mul[m-j+1];
			ull h=((ull)ph.fi<<32)+(ull)ph.se;
			int id=(j-1)*tp+i;
			rt[id]=rt[id-1];
			add(rt[id],-1,h,rep[i]);
		}
	}
	for(int i=1;i<=tp;i++)
	{
		// if(n==25000&&i%1000==0)
		// 	printf("i:%d rep:%d\n",i,rep[i]);
		int ls=0,a=p[i];
		for(int j=1;j<=m;j++)
			if(j==m||s[a][j]>s[a][j+1])
			{
				int lp=getmn(i,ls);
				int rp=getmx(i,ls);
				pii ph=h1[a][m]-h1[a][j]*mul[m-j];
				ull h=((ull)ph.fi<<32)+(ull)ph.se;
				ans-=(ll)rep[i]*(ask(rt[j*tp+rp],-1,h)-ask(rt[j*tp+lp-1],-1,h)-rep[i]);
				// if(n==25000&&i%1000==0)
				// 	printf("i:%d j:%d a:%d ls:%d rep:%d lp:%d rp:%d ans:%lld\n",i,j,a,ls,rep[i],lp,rp,ans);
				ls=j;
			}
	}
	printf("%lld",ans);
	return 0;
}