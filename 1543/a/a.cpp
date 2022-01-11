#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,b;
		scanf("%lld%lld",&a,&b);
		if(a==b)
			printf("0 0\n");
		else
		{
			if(a>b)
				swap(a,b);
			ll ans=b-a;
			ll rep=a/ans;
			ll st=min(a-rep*ans,(rep+1)*ans-a);
			printf("%lld %lld\n",ans,st);
		}
	}
	return 0;
}