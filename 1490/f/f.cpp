#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;
int n;
ll st[200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		map<int,int> mp;
		ll ans=0;
		int tp=0;
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			mp[a]++;
		}
		for(pii t:mp)
			st[++tp]=t.se;
		sort(st+1,st+tp+1);
		for(int i=1;i<=tp;i++)
			ans=max(ans,(ll)(tp-i+1)*st[i]);
		printf("%lld\n",n-ans);
	}
	return 0;
}