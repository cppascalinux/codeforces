#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int s[100009];
ll sm[100009];
ll mx[20][100009],mn[20][100009];
int lg[100009];
void init()
{
	for(int i=1;i<=n;i++)
	{
		sm[i]=sm[i-1]+s[i];
		mx[0][i]=mn[0][i]=sm[i];
	}
	for(int i=1;i<=18;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
			mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
		}
	for(int i=2;i<=n;i++)
		lg[i]=lg[i>>1]+1;
}
ll askmin(int l,int r)
{
	int bt=lg[r-l+1];
	return min(mn[bt][l],mn[bt][r-(1<<bt)+1]);
}
ll askmax(int l,int r)
{
	int bt=lg[r-l+1];
	return max(mx[bt][l],mx[bt][r-(1<<bt)+1]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		s[i]-=a;
		s[i]=-s[i];
	}
	init();
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(sm[r]!=sm[l-1])
		{
			printf("-1\n");
			continue;
		}
		else if(askmin(l,r)-sm[l-1]<0)
		{
			printf("-1\n");
			continue;
		}
		else
		{
			printf("%lld\n",askmax(l,r)-sm[l-1]);
		}
	}
	return 0;
}