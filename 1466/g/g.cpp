#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define bs 619
#define mod1 1000000007
#define mod2 1000000009
using namespace std;
pii operator+(pii a,pii b){return pii((a.fi+b.fi)%mod1,(a.se+b.se)%mod2);}
pii operator-(pii a,pii b){return pii((a.fi-b.fi+mod1)%mod1,(a.se-b.se+mod2)%mod2);}
pii operator*(pii a,pii b){return pii((ll)a.fi*b.fi%mod1,(ll)a.se*b.se%mod2);}
pii operator*(pii a,int v){return pii((ll)v*a.fi%mod1,(ll)v*a.se%mod2);}
pii operator+(pii a,int v){return pii((a.fi+v)%mod1,(a.se+v)%mod2);}
int n,m,usd,cul,tot=1,lst=1;
char s[2000009],t[100009],tmp[1000009];
int f[2000009];
int ts[100009][27];
pii pre[2000009],suf[2000009];
pii qpre[2000009],qsuf[2000009];
char abpr[2000009],absf[2000009];
vector<int> qs[100009],g[2000009];
int ans[100009];
struct qry
{
	int k,id;
	bool operator<(const qry &p)const{return qs[id].size()<qs[p.id].size();}
}q[100009];
void initt()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=26;j++)
			ts[i][j]=(ts[i-1][j]*2)%mod1;
		(++ts[i][t[i]])%=mod1;
	}
}
int qpow1(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod1)
		if(b&1)
			ans=(ll)ans*a%mod1;
	return ans;
}
int qpow2(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(ll)a*a%mod2)
		if(b&1)
			ans=(ll)ans*a%mod2;
	return ans;
}
void iniths(char *s,int n,pii *pre,pii *suf)
{
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]*bs+s[i];
	pii mul(1,1);
	for(int i=n;i>=1;i--)
	{
		suf[i]=suf[i+1]+mul*s[i];
		mul=mul*bs;
	}
}
int kmp(char *s,char *p,int n,int m)
{
	int a=0;
	for(int i=2;i<=m;i++)
	{
		while(a&&p[i]!=p[a+1])
			a=f[a];
		if(p[i]==p[a+1])
			a++;
		f[i]=a;
	}
	a=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		while(a&&s[i]!=p[a+1])
			a=f[a];
		if(s[i]==p[a+1])
			a++;
		if(a>=m)
			ans++;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	cul=strlen(s+1);
	for(int i=1;i<=cul;i++)
		s[i]-='a'-1;
	for(int i=1;i<=n;i++)
		t[i]-='a'-1;
	initt();
	for(int i=1;i<=m;i++)
	{
		int a;
		scanf("%d%s",&a,tmp+1);
		q[i]=qry{a,i};
		int l=strlen(tmp+1);
		for(int j=1;j<=l;j++)
			qs[i].push_back(tmp[j]-'a'+1);
	}
	iniths(s,cul,pre,suf);
	sort(q+1,q+m+1);
	int lp=0;
	for(int i=1;i<=m;i++)
	{
		int l=qs[q[i].id].size();
		for(int j=1;j<=l;j++)
			tmp[j]=qs[q[i].id][j-1];
		while(cul<l)
		{
			s[cul+1]=t[++usd];
			for(int i=cul+2;i<=2*cul+1;i++)
				s[i]=s[i-cul-1];
			cul=cul*2+1;
			iniths(s,cul,pre,suf);
		}
		// printf("i:%d id:%d cul:%d usd:%d\n",i,q[i].id,cul,usd);
		if(q[i].k<usd)
		{
			ans[q[i].id]=0;
			continue;
		}
		ans[q[i].id]=(ll)kmp(s,tmp,cul,l)*qpow1(2,q[i].k-usd)%mod1;
		iniths(tmp,l,qpre,qsuf);
		for(int j=1;j<=l;j++)
		{
			if(qpre[j]==suf[cul-j+1])
				abpr[j]=1;
			else
				abpr[j]=0;
			if(qsuf[j]==pre[l-j+1])
				absf[j]=1;
			else
				absf[j]=0;
			// printf("j:%d abpr:%d absf:%d\n",j,abpr[j],absf[j]);
		}
		abpr[0]=absf[l+1]=1;
		for(int j=1;j<=l;j++)
			if(abpr[j-1]&&absf[j+1])
			{
				int tp=(ts[q[i].k][tmp[j]]-(ll)ts[usd][tmp[j]]*qpow1(2,q[i].k-usd)%mod1+mod1)%mod1;
				(ans[q[i].id]+=tp)%=mod1;
			}
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}