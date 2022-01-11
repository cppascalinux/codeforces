#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int p[109],dep[109];
void solve(int l,int r,int d)
{
	int mxp=0;
	for(int i=l;i<=r;i++)
		if(p[i]>p[mxp])
			mxp=i;
	// printf("l:%d r:%d mxp:%d\n",l,r,mxp);
	dep[mxp]=d;
	if(mxp>l)
		solve(l,mxp-1,d+1);
	if(mxp<r)
		solve(mxp+1,r,d+1);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",p+i);
		solve(1,n,0);
		// printf("ans");
		for(int i=1;i<=n;i++)
			printf("%d ",dep[i]);
		printf("\n");
	}
	return 0;
}