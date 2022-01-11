#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int n,m;
vector<int> g[409];
int dep[409][409];
vector<int> v[409][409],pre[409][409];
int ans[409][409];
void bfs(int s)
{
	queue<int> q;
	dep[s][s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int v:g[x])
			if(!dep[s][v])
				dep[s][v]=dep[s][x]+1,q.push(v);
	}
	for(int i=1;i<=n;i++)
		v[s][dep[s][i]].push_back(i);
	for(int i=1;i<=n;i++)
		for(int j:g[i])
			if(dep[s][j]==dep[s][i]+1)
				pre[s][j].push_back(i);
}
int solve(int x,int y)
{
	int mn=y,ans=1;
	for(int i=2;i<=n;i++)
	{
		const vector<int> &p=v[y][i];
		for(int j:p)
		{
			if(dep[x][j]<dep[x][mn]-1)
				return 0;
			if(dep[x][j]==dep[x][mn]-1)
			{
				mn=j;
				continue;
			}
			int sm=0;
			for(int s:pre[y][j])
				if(dep[x][s]+1==dep[x][j])
					sm++;
			ans=(ll)ans*sm%mod;
		}
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b),g[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
		bfs(i);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			ans[i][j]=ans[j][i]=solve(i,j);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			printf("%d%c",ans[i][j],j==n?'\n':' ');
	return 0;
}