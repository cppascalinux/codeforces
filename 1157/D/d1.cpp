//2019.05.24
//CF1157D 构造
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define li long long
using namespace std;
int k,n;
int ans[100009];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("d.in","r",stdin);
	freopen("d1.out","w",stdout);
#endif
	scanf("%d%d",&k,&n);
	if(k<(li)n*(n+1)/2)
	{
		printf("NO\n");
		return 0;
	}
	if(n==1)
	{
		printf("YES\n%d",k);
		return 0;
	}
	k-=(li)n*(n+1)/2;
	for(int i=1;i<=n;i++)
		ans[i]=i;
	int dt=k/n;
	for(int i=1;i<=n;i++)
		ans[i]+=dt;
	k%=n;
	for(int i=n;i>=n-k+1;i--)
		ans[i]++;
	if(dt==0&&k==n-1)
		ans[2]--,ans[n]++;
	for(int i=2;i<=n;i++)
		if(ans[i]<=ans[i-1]||ans[i]>2*ans[i-1])
		{
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}