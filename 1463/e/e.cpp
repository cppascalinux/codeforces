#include<bits/stdc++.h>
using namespace std;
int n,k;
int p[300009];
int f[300009],sz[300009];
vector<int> gt[300009],gf[300009];
int nxt[300009];
int deg[300009],pos[300009];
int ans[300009];
void fail()
{
	printf("0");
	exit(0);
}
int fnd(int x)
{
	return x==f[x]?x:f[x]=fnd(f[x]);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		if(a)
			gt[a].push_back(i);
	}
	for(int i=1;i<=n;i++)
		f[i]=i,sz[i]=1;
	for(int i=1;i<=k;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		nxt[a]=b;
		int fa=fnd(a),fb=fnd(b);
		if(fa==fb)
			fail();
		f[fb]=fa,sz[fa]+=sz[fb];
	}
	// for(int i=1;i<=n;i++)
	// 	printf("i:%d fnd:%d sz:%d\n",i,fnd(i),sz[fnd(i)]);
	for(int i=1;i<=n;i++)
		for(int v:gt[i])
			if(fnd(i)!=fnd(v))
				gf[fnd(i)].push_back(fnd(v)),deg[fnd(v)]++;
	queue<int> q;
	int tot=0;
	for(int i=1;i<=n;i++)
		if(fnd(i)==i&&deg[i]==0)
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		// printf("x:%d\n",x);
		pos[x]=tot;
		tot+=sz[x];
		for(int v:gf[x])
			if(--deg[v]==0)
				q.push(v);
	}
	if(tot<n)
		fail();
	for(int i=1;i<=n;i++)
		if(fnd(i)==i)
		{
			int t=pos[i];
			for(int j=i;j;j=nxt[j])
				pos[j]=++t;
		}
	for(int i=1;i<=n;i++)
		for(int v:gt[i])
			if(pos[v]<=pos[i])
				fail();
	for(int i=1;i<=n;i++)
		if(nxt[i]&&pos[i]+1!=pos[nxt[i]])
			fail();
	for(int i=1;i<=n;i++)
		ans[pos[i]]=i;
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}