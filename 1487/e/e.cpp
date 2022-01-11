#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 1000000000
using namespace std;
int n[5],m[5];
int v[5][150009];
vector<int> vs[5][150009];
int f[5][150009];
int mn[20][150009],lg[150009];
void init(int *s,int n)
{
	for(int i=1;i<=n;i++)
		mn[0][i]=s[i];
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
	for(int i=2;i<=n;i++)
		lg[i]=lg[i>>1]+1;
}
int qry(int l,int r)
{
	if(l>r)
		return inf;
	int bt=lg[r-l+1];
	return min(mn[bt][l],mn[bt][r-(1<<bt)+1]);
}
int main()
{
	for(int i=1;i<=4;i++)
		scanf("%d",n+i);
	for(int i=1;i<=4;i++)
		for(int j=1;j<=n[i];j++)
			scanf("%d",v[i]+j);
	for(int i=2;i<=4;i++)
	{
		scanf("%d",m+i);
		for(int j=1;j<=m[i];j++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			vs[i][b].push_back(a);
		}
	}
	for(int i=1;i<=n[1];i++)
		f[1][i]=v[1][i];
	for(int i=2;i<=4;i++)
	{
		init(f[i-1],n[i-1]);
		for(int j=1;j<=n[i];j++)
		{
			sort(vs[i][j].begin(),vs[i][j].end());
			vs[i][j].push_back(n[i-1]+1);
			int lst=0,mn=inf;
			for(int k:vs[i][j])
			{
				// printf("k:%d lst:%d\n",k,lst);
				if(k>lst+1)
					mn=min(mn,qry(lst+1,k-1));
				lst=k;
			}
			f[i][j]=min(inf,mn+v[i][j]);
			// printf("i:%d j:%d mn:%d f:%d\n",i,j,mn,f[i][j]);
		}
	}
	int ans=inf;
	for(int i=1;i<=n[4];i++)
		ans=min(ans,f[4][i]);
	printf("%d",ans>=inf?-1:ans);
	return 0;
}