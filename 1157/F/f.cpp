#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int buc[200009],st[200009],outst[200009];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1,a;i<=n;i++)
	{
		scanf("%d",&a);
		buc[a]++;
	}
	int ans=0,tp=0;
	for(int i=200000;i>=1;i--)
	{
		if(buc[i]==0)
			tp=0;
		else if(buc[i]==1)
			st[++tp]=i;
		else
			for(int j=1;j<=buc[i];j++)
				st[++tp]=i;
		ans=max(tp,ans);
		if(buc[i]==1)
			st[tp=1]=i;
	}
	printf("%d\n",ans);
	tp=0;
	for(int i=200000;i>=1;i--)
	{
		if(buc[i]==0)
			tp=0;
		else if(buc[i]==1)
			st[++tp]=i;
		else
			for(int j=1;j<=buc[i];j++)
				st[++tp]=i;
		if(tp==ans)
		{
			// for(int j=1;j<=tp;j++)
				// printf("j:%d st:%d\n",j,st[j]);
			for(int j=1;j<=tp;j+=2)
				printf("%d ",st[j]);
			if(tp&1)
				for(int j=tp-1;j>=1;j-=2)
					printf("%d ",st[j]);
			else
				for(int j=tp;j>=1;j-=2)
					printf("%d ",st[j]);
			return 0;
		}
		if(buc[i]==1)
			st[tp=1]=i;
	}
	return 0;
}