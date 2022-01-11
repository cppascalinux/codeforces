#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n,k;
int h[200009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",h+i);
		int mn=h[1],mx=h[1];
		int fg=1;
		for(int i=2;i<=n;i++)
		{
			int pmn=mn-k+1,pmx=mx+k-1;
			if(pmn>h[i]+k-1)
			{
				fg=0;
				break;
			}
			if(pmx<h[i])
			{
				fg=0;
				break;
			}
			pmn=max(pmn,h[i]);
			pmx=min(pmx,h[i]+k-1);
			mn=pmn,mx=pmx;
			// printf("i:%d mn:%d mx:%d\n",i,mn,mx);
		}
		if(!(mn<=h[n]&&h[n]<=mx))
			fg=0;
		printf("%s\n",fg?"YES":"NO");
	}
	return 0;
}