#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m;
int p[300009];
int invp[300009],vis[300009];
pii ans[1500009];
void add(int a,int b)
{
	if(abs(a-b)>=n/2)
		ans[++m]=pii(a,b);
	else
	{
		if(a>b)
			swap(a,b);
		int va,vb;
		if(a<=n/2)
			va=n;
		else
			va=1;
		if(b<=n/2)
			vb=n;
		else
			vb=1;
		if(va==vb)
		{
			ans[++m]=pii(a,va);
			ans[++m]=pii(b,va);
			ans[++m]=pii(a,va);
		}
		else
		{
			ans[++m]=pii(a,va);
			ans[++m]=pii(b,vb);
			ans[++m]=pii(va,vb);
			ans[++m]=pii(a,va);
			ans[++m]=pii(b,vb);
		}
	}
}
void solve()
{
	for(int i=1;i<=n;i++)
		invp[p[i]]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;!vis[j];j=invp[j])
		{
			vis[j]=1;
			if(!vis[invp[j]])
				add(j,invp[j]);
		}
	}
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",p+i);
	solve();
	printf("%d\n",m);
	for(int i=1;i<=m;i++)
		printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}