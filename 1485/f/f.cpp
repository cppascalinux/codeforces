#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define ll long long
#define mod 1000000007
using namespace std;
int n;
int sb[200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",sb+i);
		map<ll,int> mp;
		mp[0]=1;
		ll ost=0;
		int sm=1;
		for(int i=1;i<=n;i++)
		{
			// ost+=sb[i];
			int tsm=(sm-mp[-ost]+mod)%mod;
			ll nost=ost+sb[i];
			(mp[sb[i]-nost]+=tsm)%=mod;
			(sm+=tsm)%=mod;
			ost+=sb[i];
		}
		printf("%d\n",sm);
	}
	return 0;
}