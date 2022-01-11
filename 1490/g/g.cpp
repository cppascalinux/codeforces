#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x7F7F7F7F7F7F7F7FLL
using namespace std;
int n,m;
int s[200009];
ll sm[200009],mx[200009];
ll solve(ll x)
{
	// printf("mx:%lld\n",mx[n]);
	int p=lower_bound(mx+1,mx+n+1,x)-mx;
	if(p<=n)
		return p-1;
	if(sm[n]<=0)
		return -1;
	ll rep=(x-mx[n]-1)/sm[n]+1;
	x-=rep*sm[n];
	p=lower_bound(mx+1,mx+n+1,x)-mx;
	return p+rep*n-1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		mx[0]=-inf;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",s+i);
			sm[i]=sm[i-1]+s[i];
			mx[i]=max(mx[i-1],sm[i]);
		}
		for(int i=1;i<=m;i++)
		{
			int a;
			scanf("%d",&a);
			printf("%lld ",solve(a));
		}
		printf("\n");
	}
	return 0;
}