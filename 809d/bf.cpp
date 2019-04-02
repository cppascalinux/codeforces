#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7F7F7F7F
using namespace std;
int n;
int f[300009];
void solve(int l,int r)
{
	int lp=lower_bound(f+1,f+n+1,l)-f,rp=lower_bound(f+1,f+n+1,r)-f;
	for(int i=rp;i>=lp+1;i--)
		f[i]=f[i-1]+1;
	f[lp]=l;
}
void dbg()
{
	for(int i=0;i<=n;i++)
		printf("%d ",f[i]);
	printf("\n");
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("lis.in","r",stdin);
	freopen("bf.out","w",stdout);
#endif
	memset(f,0x7F,sizeof(f));
	f[0]=0;
	scanf("%d",&n);
	for(int i=1,l,r;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		solve(l,r);
		dbg();
	}
	printf("%d",lower_bound(f+1,f+n+1,inf)-f-1);
	return 0;
}