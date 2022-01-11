#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[200009],b[200009];
ll gcd(ll a,ll b)
{
	return !a||!b?a+b:gcd(b,a%b);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(int i=1;i<=m;i++)
		scanf("%lld",b+i);
	ll g=0;
	for(int i=2;i<=n;i++)
		g=gcd(g,abs(a[i]-a[1]));
	// printf("g:%lld\n",gcd(-2,-4));
	for(int j=1;j<=m;j++)
		printf("%lld ",gcd(g,a[1]+b[j]));
	return 0;
}