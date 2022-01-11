#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll s[200009];
ll f[20][200009];
int lg[200009];
ll gcd(ll a,ll b)
{
	if(!a||!b)
		return a+b;
	return gcd(b,a%b);
}
void init()
{
	for(int i=1;i<=n;i++)
		f[0][i]=s[i];
	for(int i=1;i<=18;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			f[i][j]=gcd(f[i-1][j],f[i-1][j+(1<<(i-1))]);
	for(int i=2;i<=n;i++)
		lg[i]=lg[i/2]+1;
}
ll ask(int l,int r)
{
	int d=lg[r-l+1];
	return gcd(f[d][l],f[d][r-(1<<d)+1]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",s+i);
		n--;
		for(int i=1;i<=n;i++)
			s[i]=abs(s[i]-s[i+1]);
		init();
		int ans=0;
		int lp=1;
		for(int i=1;i<=n;i++)
		{
			while(lp<=i&&ask(lp,i)<2)
				lp++;
			ans=max(ans,i-lp+1);
		}
		printf("%d\n",ans+1);
	}
	return 0;
}