#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cassert>
using namespace std;
int n;
int p[200009];
int ml[10009];
int ans1[200009],ans2[200009];
int vis[200009];
int main()
{
	int t;
	for(int i=1;i<=10000;i++)
		ml[i]=i*i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			vis[i]=0;
		int tp=0,vn=n;
		while(1)
		{
			if(vn==3)
			{
				if(!vis[3]&&n>3)
					ans1[++tp]=3,ans2[tp]=n;
				ans1[++tp]=n,ans2[tp]=2;
				ans1[++tp]=n,ans2[tp]=2;
				break;
			}
			if(vn==2)
			{
				ans1[++tp]=n,ans2[tp]=2;
				break;
			}
			int cl=upper_bound(ml+1,ml+10001,vn)-ml-1;
			for(int i=cl+1;i<=n-1&&!vis[i];i++)
					vis[i]=1,ans1[++tp]=i,ans2[tp]=n;
			ans1[++tp]=n,ans2[tp]=cl;
			vn=(vn-1)/cl+1;
		}
		// printf("n:%d tp:%d\n",n,tp),fflush(stdout);
		printf("%d\n",tp);
		for(int i=1;i<=tp;i++)
			printf("%d %d\n",ans1[i],ans2[i]);
		// assert(tp<=n+5);
		// for(int i=1;i<=n;i++)
		// 	p[i]=i;
		// for(int i=1;i<=tp;i++)
		// 	p[ans1[i]]=(p[ans1[i]]-1)/p[ans2[i]]+1;
		// int sm1=0,sm2=0;
		// for(int i=1;i<=n;i++)
		// 	if(p[i]==1)
		// 		sm1++;
		// 	else if(p[i]==2)
		// 		sm2++;
		// for(int i=1;i<=n;i++)
		// 	printf("%d ",p[i]);
		// printf("\n");
		// assert(sm1==n-1&&sm2==1);
	}
	return 0;
}