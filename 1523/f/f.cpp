#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m;
char s[509];
int mat[509][509];
int d[8][2]={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
int w[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int f[250009];
int cl[250009];
int vis[250009];
int ans[509][509];
vector<int> g[250009];
set<pii> edg;
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
int geti(int x,int y)
{
	return (x-1)*m+y;
}
void dfs(int x,int c)
{
	if(vis[x])
		return;
	vis[x]=1;
	cl[x]=c;
	for(int v:g[x])
		dfs(v,-c);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			mat[i][j]=s[j]=='X';
	}
	for(int i=2;i<=n-1;i++)
		for(int j=2;j<=m-1;j++)
			if(mat[i][j])
			{
				int sm=0;
				for(int k=0;k<4;k++)
				{
					int nx=i+w[k][0],ny=j+w[k][1];
					sm+=mat[nx][ny];
				}
				if(sm&1)
					return printf("NO"),0;
			}
	for(int i=1;i<=n*m;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!mat[i][j])
			{
				int id=geti(i,j);
				for(int k=0;k<8;k++)
				{
					int nx=i+d[k][0],ny=j+d[k][1];
					if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!mat[nx][ny])
					{
						int nid=geti(nx,ny);
						f[fnd(nid)]=fnd(id);
					}
				}
			}
	for(int i=2;i<=n-1;i++)
		for(int j=2;j<=m-1;j++)
			if(mat[i][j])
			{
				if(mat[i-1][j]&&mat[i+1][j]&&!mat[i][j-1]&&!mat[i][j+1])
					edg.emplace(fnd(geti(i,j-1)),fnd(geti(i,j+1)));
				if(!mat[i-1][j]&&!mat[i+1][j]&&mat[i][j-1]&&mat[i][j+1])
					edg.emplace(fnd(geti(i-1,j)),fnd(geti(i+1,j)));
			}
	for(pii t:edg)
	{
		g[t.fi].push_back(t.se);
		g[t.se].push_back(t.fi);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!mat[i][j]&&!vis[geti(i,j)])
			{
				dfs(geti(i,j),1);
			}
	for(int i=1;i<=n*m;i++)
		cl[i]=cl[fnd(i)];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int id=geti(i,j);
			ans[i][j]=(i%2?cl[id]:-cl[id]);
			(ans[i][j]+=5)%=5;
		}
	for(int i=2;i<=n-1;i++)
		for(int j=2;j<=m-1;j++)
			if(mat[i][j])
			{
				for(int k=0;k<4;k++)
				{
					int nx=i+w[k][0],ny=j+w[k][1];
					if(!mat[nx][ny])
						ans[i][j]+=ans[nx][ny];
				}
			}
	printf("YES\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}