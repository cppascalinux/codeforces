#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int s[100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		map<int,ll> mp;
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=mp[s[i]]*(n-i+1);
			mp[s[i]]+=i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}