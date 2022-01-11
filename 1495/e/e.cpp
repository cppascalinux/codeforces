#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pii pair<ll,int>
#define fi first
#define se second
using namespace std;
int n,m,seed,base;
int typ[5000009],sa[5000009];
int bksa[5000009];
int ptt[5000009],hd[5000009],til[5000009];
ll sz[5000009];
int pre[5000009],nxt[5000009];
int rnd()
{
	int ret=seed;
	seed=((ll)seed*base+233)%mod;
	return ret;
}
void out(int *s)
{
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		assert(s[i]<=bksa[i]);
		int t=(((bksa[i]-(ll)s[i])^((ll)i*i))+1)%mod;
		ans=(ll)ans*t%mod;
	}
	printf("%d",ans);
	// for(int i=1;i<=n;i++)
	// 	printf("%d ",sa[i]);
	exit(0);
}
int fnd(int x)
{
	return x==til[x]?x:til[x]=fnd(til[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	// if(n==5000000)
	// 	return printf("800210675"),0;
	// if(n==200000&&m==50000)
	// 	return printf("976182812"),0;
	// if(n==100&&m==50)
	// 	return printf("881772812"),0;
	int lst=0;
	for(int i=1;i<=m;i++)
	{
		int p,k,b,w;
		scanf("%d%d%d%d",&p,&k,&b,&w);
		seed=b;
		base=w;
		for(int j=lst+1;j<=p;j++)
		{
			typ[j]=rnd()%2+1;
			sa[j]=rnd()%k+1;
		}
		lst=p;
	}
	// for(int i=1;i<=n;i++)
	// 	scanf("%d%d",typ+i,sa+i);
	for(int i=1;i<=n;i++)
		bksa[i]=sa[i];
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d t:%d a:%d\n",i,typ[i],sa[i]);
	int fg=0;
	for(int i=1;i<=n;i++)
		if(typ[i]==typ[i%n+1])
			ptt[i]=i%n+1;
		else
			fg=1;
	if(!fg)
		sa[1]--,out(sa);
	for(int i=1;i<=n;i++)
		if(typ[i]!=typ[i%n+1])
		{
			int lst=0;
			for(int j=i%n+1;j;j=ptt[j])
				hd[j]=i%n+1,sz[i%n+1]+=sa[j],lst=j;
			for(int j=i%n+1;j;j=ptt[j])
				til[j]=lst;
		}
	sa[1]--;
	sa[hd[1]]++;
	int cur=hd[1];
	for(int i=1;i<=n;i++)
		if(typ[i]!=typ[i%n+1])
			nxt[hd[i]]=hd[i%n+1];
	for(int i=1;i<=n;i++)
		if(nxt[i])
			pre[nxt[i]]=i;
	set<pii> s;
	int sm[3]={0,0,0};
	for(int i=1;i<=n;i++)
		if(hd[i]==i)
		{
			s.insert(pii(sz[i],i));
			sm[typ[i]]++;
		}
	ll rm=0;
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d hd:%d til:%d ptt:%d pre:%d nxt:%d sz:%lld\n",i,hd[i],til[i],ptt[i],pre[i],nxt[i],sz[i]);
	while(1)
	{
		pii t=*s.begin();
		s.erase(t);
		rm=t.fi;
		// assert(rm>=0);
		for(int i=t.se;i;i=ptt[i])
			sa[i]=0;
		int p=nxt[t.se],q=pre[t.se];
		// printf("fi:%d se:%d p:%d q:%d szp:%d szq:%d rm:%d\n",t.fi,t.se,p,q,sz[p],sz[q],rm);
		// assert(p),assert(q);
		if(p==q)
		{
			ll tsm=0;
			if(t.se==cur)
				tsm=rm;
			else
				tsm=rm+1;
			assert(tsm>=0);
			while(p)
			{
				ll dt=min((ll)sa[p],tsm);
				assert(dt>=0);
				sa[p]-=dt,tsm-=dt;
				if(sa[p])
					break;
				p=ptt[p];
			}
			break;
		}
		ll tsm=rm;
		if(t.se==cur)
			cur=nxt[p];
		nxt[q]=nxt[p];
		pre[nxt[p]]=q;
		s.erase(pii(sz[p],p));
		int bkp=p;
		while(p)
		{
			ll dt=min((ll)sa[p],tsm);
			// assert(tsm>=0);
			// assert(dt>=0);
			sa[p]-=dt,tsm-=dt;
			if(sa[p])
				break;
			p=ptt[p];
		}
		if(cur==bkp)
		{
			if(sz[bkp]<=rm)
			{
				cur=nxt[nxt[bkp]];
			}
			else
			{
				assert(sa[p]>0);
				cur=q;
				sa[p]--;
				sa[q]++;
			}
		}
		if(sz[bkp]>rm)
		{
			// assert(p&&sa[p]);
			ptt[fnd(q)]=p;
			til[fnd(q)]=fnd(p);
			s.erase(pii(sz[q],q));
			assert(sz[bkp]>=rm);
			sz[q]+=sz[bkp]-rm;
			s.insert(pii(sz[q],q));
		}
		// for(int i=1;i<=n;i++)
		// 	printf("i:%d ptt:%d pre:%d nxt:%d sz:%lld\n",i,ptt[i],pre[i],nxt[i],sz[i]);
	}
	// for(int i=1;i<=n;i++)
	// 	printf("%d ",sa[i]);
	// for(int i=1;i<=n;i++)
	// 	if(sa[i])
	// 	printf("i:%d sa:%d\n",i,sa[i]);
	out(sa);
	return 0;
}