#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,k;
pii p[100009];
int main()
{
	int ttt;
	scanf("%d",&ttt);
	while(ttt--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i].fi);
			p[i].se=i;
		}
		sort(p+1,p+n+1);
		int mn=n;
		for(int i=1;i<=n-1;i++)
			if(p[i].se+1==p[i+1].se)
				mn--;
		if(mn<=k)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}