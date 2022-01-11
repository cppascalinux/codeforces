#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n,m,seed,base;
int typ[5000009],sa[5000009];
int bksa[5000009];
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
		int t=(((bksa[i]-(ll)s[i])^((ll)i*i))+1)%mod;
		ans=(ll)ans*t%mod;
	}
	printf("%d",ans);
	exit(0);
}
int main()
{
	scanf("%d%d",&n,&m);
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
			bksa[j]=sa[j]=rnd()%k+1;
		}
		lst=p;
	}
	// for(int i=1;i<=n;i++)
	// 	scanf("%d%d",typ+i,sa+i);
	ll sm[3]={0,0,0};
	for(int i=1;i<=n;i++)
		sm[typ[i]]+=sa[i];
	// printf("sm1:%lld sm2:%lld\n",sm[1],sm[2]);
	if(sm[1]==0||sm[2]==0)
		sa[1]--,out(sa);
	// printf("asdasda");
	if(sm[1]>sm[2]||(sm[1]==sm[2]&&typ[1]==2))
		for(int i=1;i<=n;i++)
			typ[i]^=3;
	int st=1;
	if(typ[st]==2)
	{
		sa[st]--;
		for(int j=st+1;j<=n;j++)
			if(typ[j]==1)
			{
				st=j;
				break;
			}
	}
	// printf("st:%d\n",st);
	ll tot=0;
	for(int i=1;i<=2*n;i++)
	{
		int p=(i-1)%n+1;
		if(typ[p]==1)
			tot+=sa[p],sa[p]=0;
		else
		{
			ll dt=min(tot,(ll)sa[p]);
			sa[p]-=dt,tot-=dt;
		}
	}
	// for(int i=1;i<=n;i++)
	// 	if(sa[i])
	// 		printf("%d ",sa[i]);
	out(sa);
	return 0;
}