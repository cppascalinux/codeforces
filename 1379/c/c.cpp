#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define PII pair<int,int>
#define FI first
#define SE second
using namespace std;
int n,m;
int va[100009],vb[100009];
PII s[100009];
LL sm[100009];
int pos[100009];
void solve()
{
	LL ans=0;
	for(int i=1;i<=m;i++)
		s[i]=PII(va[i],i);
	sort(s+1,s+m+1);
	for(int i=1;i<=m;i++)
		pos[s[i].SE]=i;
	sm[m+1]=0;
	for(int i=m;i>=1;i--)
		sm[i]=sm[i+1]+s[i].FI;
	for(int i=1;i<=m;i++)
	{
		int p=lower_bound(s+1,s+m+1,PII(vb[i],0))-s;
		int num=m-p+1;
		LL st=sm[p];
		if(pos[i]<p)
			num++,st+=va[i];
		if(num>=n)
		{
			p=m-n+1,st=sm[p];
			if(pos[i]<p)
				st=st-s[p].FI+va[i];
			ans=max(ans,st);
		}
		else
		{
			st+=(LL)(n-num)*vb[i];
			ans=max(ans,st);
		}
	}
	printf("%lld\n",ans);
}
int main()
{
#ifdef I_LOVE_KTY
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
			scanf("%d%d",va+i,vb+i);
		solve();
	}
	return 0;
}