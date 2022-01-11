#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
int n;
int w[100009],deg[100009];
int s[200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",w+i),deg[i]=0;
		for(int i=1;i<=n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			deg[a]++,deg[b]++;
		}
		ll ans=0;
		int tp=0;
		for(int i=1;i<=n;i++)
		{
			ans+=w[i];
			for(int j=1;j<=deg[i]-1;j++)
				s[++tp]=w[i];
		}
		printf("%lld ",ans);
		sort(s+1,s+tp+1);
		for(int i=1;i<=n-2;i++)
		{
			ans+=s[tp--];
			printf("%lld ",ans);
		}
		printf("\n");
	}
	return 0;
}