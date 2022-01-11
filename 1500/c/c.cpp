#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mod 1000000009
#define bs 10007
#define ll long long
using namespace std;
int n,m;
int ma[1509][1509];
int hsa[1509],hsb[1509];
int mb[1509][1509];
int f[1509][1509];
bitset<1509> sp[1509],wa[1509];
int vis[1509],st[1509];
void fail()
{
	printf("-1");
	exit(0);
}
void iniths()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			hsa[i]=(ll)hsa[i]*bs+ma[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			hsb[i]=(ll)hsb[i]*bs+mb[i][j];
	}
	set<pii> mp;
	for(int i=1;i<=n;i++)
		mp.insert(pii(hsa[i],i));
	for(int i=1;i<=n;i++)
	{
		auto it=mp.lower_bound(pii(hsb[i],0));
		if(it==mp.end()||it->fi!=hsb[i])
			fail();
		mb[i][m+1]=it->se;
		mp.erase(it);
	}
	if(!mp.empty())
		fail();
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&ma[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mb[i][j]);
	iniths();
	for(int j=1;j<=m+1;j++)
		for(int i=1;i<=n-1;i++)
		{
			if(mb[i][j]<mb[i+1][j])
				sp[j][i]=1;
			else if(mb[i][j]>mb[i+1][j])
				wa[j][i]=1;
		}
	bitset<1509> cur;
	int tp=0;
	while(1)
	{
		int fg=0;
		for(int i=1;i<=m+1;i++)
			if(!vis[i]&&(cur&wa[i])==wa[i])
			{
				fg=1;
				vis[i]=1;
				st[++tp]=i;
				cur|=sp[i];
				if(i==m+1)
					break;
			}
		if(!fg)
			break;
		if(vis[m+1])
			break;
	}
	if(!vis[m+1])
		fail();
	for(int i=1;i<=tp;i++)
		if(st[i]==m+1)
		{
			tp=i-1;
			break;
		}
	printf("%d\n",tp);
	for(int i=tp;i>=1;i--)
		printf("%d ",st[i]);
	return 0;
}