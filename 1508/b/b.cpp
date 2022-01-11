#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll k;
int fg[100009];
int p[100009];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		if(n<=63&&k>(1LL<<(n-1)))
		{
			printf("-1\n");
			continue;
		}
		k--;
		for(int i=1;i<=n;i++)
			fg[i]=0,p[i]=i;
		for(int i=0;i<=62;i++)
			if(k>>i&1)
				fg[n-1-i]=1;
		int lp=1;
		for(int i=1;i<=n;i++)
			if(fg[i]==0)
			{
				reverse(p+lp,p+i+1);
				lp=i+1;
			}
		for(int i=1;i<=n;i++)
			printf("%d ",p[i]);
		printf("\n");
	}
	return 0;
}