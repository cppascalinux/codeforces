#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll k,m;
ll s[200009];
ll sb[200009],tp;
int main()
{
	scanf("%d%lld%lld",&n,&k,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",s+i);
	sort(s+1,s+n+1);
	int ans=1;
	for(int i=1;i<=n-1;i++)
		if(s[i+1]-s[i]>m)
			ans++,sb[++tp]=(s[i+1]-s[i]+m-1)/m-1;
	sort(sb+1,sb+tp+1);
	for(int i=1;i<=tp;i++)
		if(k>=sb[i])
			k-=sb[i],ans--;
	ans=max(ans,1);
	printf("%d",ans);
	return 0;
}