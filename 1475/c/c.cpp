#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n,m,k;
int pa[200009],pb[200009];
int sm1[200009],sm2[200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=k;i++)
			scanf("%d",pa+i),sm1[pa[i]]++;
		for(int i=1;i<=k;i++)
			scanf("%d",pb+i),sm2[pb[i]]++;
		ll ans=0;
		for(int i=1;i<=k;i++)
			ans+=k-sm1[pa[i]]-sm2[pb[i]]+1;
		printf("%lld\n",ans/2);
		for(int i=1;i<=k;i++)
			sm1[pa[i]]=sm2[pb[i]]=0;
	}
	return 0;
}