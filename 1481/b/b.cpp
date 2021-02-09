#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n,k;
int h[109];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",h+i);
		h[n+1]=0;
		int ans=0;
		for(int i=1;i<=k;i++)
		{
			int p=1;
			while(p<=n&&h[p]>=h[p+1])
				p++;
			if(p>n)
			{
				ans=-1;
				break;
			}
			ans=p;
			h[p]++;
		}
		printf("%d\n",ans);
	}
	return 0;
}