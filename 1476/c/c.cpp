#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define ninf 0x8080808080808080LL
using namespace std;
int n;
int s[100009];
int va[100009],vb[100009];
ll sm[100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",s+i);
		for(int i=1;i<=n;i++)
			scanf("%d",va+i);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",vb+i);
			if(va[i]>vb[i])
				swap(va[i],vb[i]);
		}
		for(int i=2;i<=n;i++)
			sm[i]=sm[i-1]+(ll)va[i]+(ll)(s[i-1]-vb[i]+1);
		int lp=2;
		ll ans=0,mx=ninf;
		for(int i=2;i<=n;i++)
		{
			if(va[i]==vb[i])
				lp=i,mx=ninf;
			mx=max(mx,vb[i]-va[i]+1-sm[i]);
			// printf("i:%d lp:%d\n",i,lp);
			ll cur=s[i]+sm[i]+mx;
			ans=max(ans,cur);
		}
		printf("%lld\n",ans);
	}
	return 0;
}