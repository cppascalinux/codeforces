#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int s[1009];
ll sm[1009];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",s+i);
		sm[i]=sm[i-1];
		if(i&1)
			sm[i]+=s[i];
		else
			sm[i]-=s[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i+=2)//start pos
	{
		ll mn=0;
		for(int j=i+1;j<=n;j+=2)
		{
			ll ml=max(1ll,-mn);
			if(ml>s[i])
				break;
			ll rs=sm[j-1]-sm[i];
			ml=max(ml,-(rs-1));
			ll mr=min((ll)s[i],-(rs-s[j]));
			// printf("i:%d j:%d ml:%d mr:%d\n",i,j,ml,mr);
			ans+=max(mr-ml+1,0ll);
			mn=min(mn,sm[j]-sm[i]);
			mn=min(mn,sm[j+1]-sm[i]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}