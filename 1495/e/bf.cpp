#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n,m,seed,base;
int typ[5000009],sa[5000009];
int bksa[5000009];
int nxt[5000009],pre[5000009];
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
	exit(0);
}
int main()
{
	scanf("%d%d",&n,&m);
	int lst=0;
	// for(int i=1;i<=m;i++)
	// {
	// 	int p,k,b,w;
	// 	scanf("%d%d%d%d",&p,&k,&b,&w);
	// 	seed=b;
	// 	base=w;
	// 	for(int j=lst+1;j<=p;j++)
	// 	{
	// 		typ[j]=rnd()%2+1;
	// 		sa[j]=rnd()%k+1;
	// 	}
	// 	lst=p;
	// }
	for(int i=1;i<=n;i++)
		scanf("%d%d",typ+i,sa+i);
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d typ:%d sa:%d\n",i,typ[i],sa[i]);
	for(int i=1;i<=n;i++)
		bksa[i]=sa[i];
	for(int i=1;i<=n;i++)
	{
		nxt[i]=i%n+1;
		pre[i%n+1]=i;
	}
	int cur=1;
	while(1)
	{
		sa[cur]--;
		int cl=typ[cur];
		int p=nxt[cur],q=p;
		if(!sa[cur])
		{
			pre[nxt[cur]]=pre[cur];
			nxt[pre[cur]]=nxt[cur];
		}
		int fg=0;
		do
		{
			if(typ[p]!=cl)
			{
				fg=1;
				cur=p;
				break;
			}
			p=nxt[p];
		}while(p!=q);
		if(!fg)
			break;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",sa[i]);
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d sa:%d\n",i,sa[i]);
	// out(sa);
	// return 0;
}