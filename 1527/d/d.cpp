#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<int> g[200009];
int sz[200009],dep[200009];
int f[200009][20];
ll ans[200009];
void dfs(int x,int fa)
{
	sz[x]=1;
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=18;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int v:g[x])
		if(v!=fa)
		{
			dfs(v,x);
			sz[x]+=sz[v];
		}
}
int getk(int a,int k)
{
	if(k<0)
		return 0;
	for(int i=0;i<=18;i++)
		if(k>>i&1)
			a=f[a][i];
	return a;
}
int getlca(int a,int b)
{
	if(dep[a]<dep[b])
		swap(a,b);
	a=getk(a,dep[a]-dep[b]);
	for(int i=18;i>=0;i--)
		if(f[a][i]!=f[b][i])
			a=f[a][i],b=f[b][i];
	if(a==b)
		return a;
	return f[a][0];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			for(int j=0;j<=19;j++)
				f[i][j]=0;
			ans[i]=ans[i+1]=0;
		}
		for(int i=1;i<=n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a++,b++;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		dfs(1,0);
		for(int v:g[1])
			ans[1]+=(ll)sz[v]*(sz[v]-1)/2;
		int f2=getk(2,dep[2]-2),sm=1;
		for(int v:g[1])
		{
			int ts=sz[v];
			if(v==f2)
				ts-=sz[2];
			ans[2]+=(ll)ts*sm;
			sm+=ts;
		}
		int a=1,b=1;
		for(int i=2;i<=n-1;i++)
		{
			if(getk(i,dep[i]-dep[a])==a)
				a=i;
			else if(b!=1&&getk(i,dep[i]-dep[b])==b)
				b=i;
			else if(b==1&&getk(a,dep[a]-2)!=getk(i,dep[i]-2))
				b=i;
			else if(getk(a,dep[a]-dep[i])!=i&&getk(b,dep[b]-dep[i])!=i)
				break;
			// printf("i:%d a:%d b:%d\n",i,a,b);
			int sa=sz[a],sb=sz[b];
			if(b==1)
			{
				int sn=getk(a,dep[a]-2);
				sb=n-sz[sn];
				if(getk(a,dep[a]-dep[i+1])==i+1)
					ans[i+1]=0;
				else if(getk(i+1,dep[i+1]-dep[a])==a)
					ans[i+1]=(ll)(sa-sz[i+1])*sb;
				else if(getk(i+1,dep[i+1]-2)!=sn)
					ans[i+1]=(ll)sa*(sb-sz[i+1]);
				else
					ans[i+1]=(ll)sa*sb;
			}
			else
			{
				if(getk(a,dep[a]-dep[i+1])==i+1||getk(b,dep[b]-dep[i+1])==i+1)
					ans[i+1]=0;
				else if(getk(i+1,dep[i+1]-dep[a])==a)
					ans[i+1]=(ll)(sa-sz[i+1])*sb;
				else if(getk(i+1,dep[i+1]-dep[b])==b)
					ans[i+1]=(ll)sa*(sb-sz[i+1]);
				else
					ans[i+1]=(ll)sa*sb;
			}
		}
		ans[n+1]=(ll)n*(n-1)/2;
		for(int i=1;i<=n;i++)
			ans[n+1]-=ans[i];
		for(int i=1;i<=n+1;i++)	
			printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}