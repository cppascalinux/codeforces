#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
#define pii pair<int,int>
using namespace std;
int n;
int x[200009],y[200009],s[200009];
int f[200009],sm[200009];
int main()
{
	scanf("%d",&n);
	vector<pii> v;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",x+i,y+i,s+i);
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		int p=upper_bound(x+1,x+n+1,y[i])-x;
		// assert(p>=1&&p<=i);
		f[i]=((ll)x[i]-y[i]+(ll)sm[i-1]-sm[p-1]+2LL*mod)%mod;
		// assert(f[i]>=0);
		sm[i]=(sm[i-1]+f[i])%mod;
		// printf("i:%d f:%d\n",i,f[i]);
	}
	int ans=(x[n]+1)%mod;
	for(int i=1;i<=n;i++)
		if(s[i])
			ans=(ans+f[i])%mod;
	printf("%d",ans);
	return 0;
}