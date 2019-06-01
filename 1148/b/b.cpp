#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7F7F7F7F
using namespace std;
int n,m,k,ta,tb;
int va[200009],vb[200009];
int solve(int x)
{
	if(x>=n)
		return inf;
	int arv=va[x+1]+ta;
	int stb=lower_bound(vb+1,vb+m+1,arv)-vb+(k-x);
	if(stb>m)
		return inf;
	return vb[stb]+tb;
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
#endif
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",va+i);
	for(int i=1;i<=m;i++)
		scanf("%d",vb+i);
	int ans=0;
	for(int i=0;i<=k;i++)
		ans=max(ans,solve(i));
	printf("%d",ans>=inf?-1:ans);
	return 0;
}